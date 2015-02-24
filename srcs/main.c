/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msagodir <msagodir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/12 18:41:56 by msagodir          #+#    #+#             */
/*   Updated: 2015/02/24 15:16:41 by msagodir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <X11/X.h>
#include <stdlib.h>
#include <wolf3d.h>
#include <libft.h>

static int					loop_hook(t_env *e)
{
	if (e->img != NULL)
		mlx_destroy_image(e->mlx, e->img);
	draw(e);
	return (1);
}

static int					key_hook(int keycode, t_env *e)
{
	if (keycode == 65362 || keycode == 119)
		e->inputs.up = 1;
	if (keycode == 65364 || keycode == 115)
		e->inputs.down = 1;
	if (keycode == 65363 || keycode == 100)
		e->inputs.right = 1;
	if (keycode == 65361 || keycode == 97)
		e->inputs.left = 1;
	return (1);
}

static int					key_hook_r(int keycode, t_env *e)
{
	if (keycode == 65307)
		exit(0);
	if (keycode == 65362 || keycode == 119)
		e->inputs.up = 0;
	if (keycode == 65364 || keycode == 115)
		e->inputs.down = 0;
	if (keycode == 65363 || keycode == 100)
		e->inputs.right = 0;
	if (keycode == 65361 || keycode == 97)
		e->inputs.left = 0;
	return (1);
}

int							main(void)
{
	t_env					e;

	init_env(&e);
	fill_palette(&(e.p));
	e.mlx = mlx_init();
	init_map(&e);
	e.win = mlx_new_window(e.mlx, WIN_WIDTH, WIN_HEIGHT, "Wolf3D");
	mlx_hook(e.win, KeyPress, KeyPressMask, &key_hook, &e);
	mlx_hook(e.win, KeyRelease, KeyReleaseMask, &key_hook_r, &e);
	mlx_loop_hook(e.mlx, &loop_hook, &e);
	mlx_loop(e.mlx);
	return (0);
}
