/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msagodir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/17 16:41:00 by msagodir          #+#    #+#             */
/*   Updated: 2014/01/18 17:22:29 by msagodir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wolf3d.h>
#include <math.h>

void	calc_steps_and_side_dist(t_env *e)
{
	if (e->draw.ray_dirx < 0)
	{
		e->draw.stepx = -1;
		e->draw.side_distx = (e->draw.ray_posx - e->draw.mapx) *
			e->draw.delta_distx;
	}
	else
	{
		e->draw.stepx = 1;
		e->draw.side_distx = (e->draw.mapx + 1.0 - e->draw.ray_posx) *
			e->draw.delta_distx;
	}
	if (e->draw.ray_diry < 0)
	{
		e->draw.stepy = -1;
		e->draw.side_disty = (e->draw.ray_posy - e->draw.mapy) *
			e->draw.delta_disty;
	}
	else
	{
		e->draw.stepy = 1;
		e->draw.side_disty = (e->draw.mapy + 1.0 - e->draw.ray_posy) *
			e->draw.delta_disty;
	}
}

void	calc_wall_dist(t_env *e)
{
	if (e->draw.side == 0)
		e->draw.perp_wall_dist = fabs((e->draw.mapx - e->draw.ray_posx +
					(1 - e->draw.stepx) / 2) / e->draw.ray_dirx);
	else
		e->draw.perp_wall_dist = fabs((e->draw.mapy - e->draw.ray_posy +
					(1 - e->draw.stepy) / 2) / e->draw.ray_diry);
}

void	calc_line_height(t_env *e)
{
	e->draw.line_height = fabs((int)(WIN_HEIGHT / e->draw.perp_wall_dist));
	e->draw.draw_start = -(e->draw.line_height) / 2 + WIN_HEIGHT / 2;
	if (e->draw.draw_start < 0)
		e->draw.draw_start = 0;
	e->draw.draw_end = e->draw.line_height / 2 + WIN_HEIGHT / 2;
	if (e->draw.draw_end >= WIN_HEIGHT)
		e->draw.draw_end = WIN_HEIGHT - 1;
	if (e->draw.side == 0 && e->draw.ray_dirx > 0)
		e->draw.c = e->p.north;
	else if (e->draw.side == 0 && e->draw.ray_dirx < 0)
		e->draw.c = e->p.south;
	else if (e->draw.side == 1 && e->draw.ray_diry > 0)
		e->draw.c = e->p.east;
	else
		e->draw.c = e->p.west;
}
