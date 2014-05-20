/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msagodir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/12 18:43:48 by msagodir          #+#    #+#             */
/*   Updated: 2014/05/20 16:50:59 by msagodir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF3D_H
# define WOLF3D_H

# define WIN_WIDTH 1280
# define WIN_HEIGHT 720
# define MAP_WIDTH 24
# define MAP_HEIGHT 24
# define TRUE 1
# define FALSE 0
# include <sys/time.h>

typedef struct	s_color
{
	int			r;
	int			g;
	int			b;
}				t_color;

typedef struct	s_palette
{
	t_color		north;
	t_color		south;
	t_color		west;
	t_color		east;
}				t_palette;

typedef struct	s_inputs
{
	int		up;
	int		down;
	int		right;
	int		left;
}				t_inputs;

typedef struct	s_draw
{
	double		camerax;
	double		ray_posx;
	double		ray_posy;
	double		ray_dirx;
	double		ray_diry;
	int			mapx;
	int			mapy;
	double		side_distx;
	double		side_disty;
	double		delta_distx;
	double		delta_disty;
	double		perp_wall_dist;
	int			stepx;
	int			stepy;
	int			hit;
	int			side;
	int			line_height;
	int			draw_start;
	int			draw_end;
	int			x;
	t_color		c;
}				t_draw;

typedef struct	s_move
{
	struct timeval	time;
	long			usec;
	long			sec;
	double			movespeed;
	double			rotspeed;
	double			old_dirx;
	double			old_planex;
}				t_move;

typedef struct	s_env
{
	void		*mlx;
	void		*win;
	void		*img;
	t_palette	p;
	double		posx;
	double		posy;
	double		dirx;
	double		diry;
	double		planex;
	double		planey;
	double		time;
	double		old_time;
	double		frame_time;
	int			**world_map;
	t_inputs	inputs;
	t_draw		draw;
	t_move		move;
	int			map[MAP_WIDTH][MAP_HEIGHT];
}				t_env;

void			draw(t_env *e);
void			get_color(int r, int g, int b, t_color *get);
void			fill_palette(t_palette *palette);
void			calc_steps_and_side_dist(t_env *e);
void			init_draw(t_env *e);
void			calc_line_height(t_env *e);
void			calc_wall_dist(t_env *e);
void			init_move(t_env *e);
void			move_right(t_env *e);
void			move_left(t_env *e);
void			init_env(t_env *e);
void			init_map(t_env *e);

#endif
