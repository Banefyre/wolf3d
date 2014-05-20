/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   directions.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msagodir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/17 19:44:37 by msagodir          #+#    #+#             */
/*   Updated: 2014/01/18 17:25:01 by msagodir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wolf3d.h>
#include <math.h>

void		move_right(t_env *e)
{
	e->move.old_dirx = e->dirx;
	e->dirx = e->dirx * cos(-(e->move.rotspeed)) - e->diry *
		sin(-(e->move.rotspeed));
	e->diry = e->move.old_dirx * sin(-(e->move.rotspeed)) + e->diry *
		cos(-(e->move.rotspeed));
	e->move.old_planex = e->planex;
	e->planex = e->planex * cos(-(e->move.rotspeed)) - e->planey *
		sin(-(e->move.rotspeed));
	e->planey = e->move.old_planex * sin(-(e->move.rotspeed)) + e->planey *
		cos(-(e->move.rotspeed));
}

void		move_left(t_env *e)
{
	e->move.old_dirx = e->dirx;
	e->dirx = e->dirx * cos(e->move.rotspeed) - e->diry *
		sin(e->move.rotspeed);
	e->diry = e->move.old_dirx * sin(e->move.rotspeed) + e->diry *
		cos(e->move.rotspeed);
	e->move.old_planex = e->planex;
	e->planex = e->planex * cos(e->move.rotspeed) - e->planey *
		sin(e->move.rotspeed);
	e->planey = e->move.old_planex * sin(e->move.rotspeed) + e->planey *
		cos(e->move.rotspeed);
}
