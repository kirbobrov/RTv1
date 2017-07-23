/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbobrov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/20 17:08:43 by kbobrov           #+#    #+#             */
/*   Updated: 2017/06/09 19:26:30 by kbobrov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void	ft_init(t_wolf *w)
{
	w->mx.mlx = mlx_init();
	w->mx.win = mlx_new_window(w->mx.mlx, SIZE_X, SIZE_Y, "wolf3d by kbobrov");
	w->pl.posx = 1;
	w->pl.posy = 1;
	w->pl.dirx = -1;
	w->pl.diry = 0;
	w->pl.planex = 0;
	w->pl.planey = 0.66;
	w->pl.time = 0;
	w->pl.oldtime = 0;
	w->pl.perpwalldist = 0;
	w->pl.camerax = 0;
	w->pl.raydirx = 0;
	w->pl.raydiry = 0;
	w->pl.rayposx = 0;
	w->pl.rayposy = 0;
	w->pl.frametime = 0;
	w->cl.color = 0xFAFF0F;
	w->pl.sm = 1.0;
	w->pl.posx = 20;
	w->pl.posy = 20;
}

void	ft_imageinit(t_wolf *w)
{
	w->mx.img = mlx_new_image(w->mx.mlx, SIZE_X, SIZE_Y);
	w->mx.bpp = 0;
	w->mx.endl = 0;
	w->mx.sizel = 0;
	w->mx.buf =
			mlx_get_data_addr(w->mx.img, &w->mx.bpp, &w->mx.sizel, &w->mx.endl);
}

void	ft_imageput(t_wolf *w)
{
	int		x;
	int		y;

	x = 920;
	y = 357;
	w->mx.sky = mlx_xpm_file_to_image(w->mx.mlx, "sky2.xpm", &x, &y);
	mlx_put_image_to_window(w->mx.mlx, w->mx.win, w->mx.sky, 0, 0);
	mlx_destroy_image(w->mx.mlx, w->mx.sky);
	w->mx.floor = mlx_xpm_file_to_image(w->mx.mlx, "lava.xpm", &x, &y);
	mlx_put_image_to_window(w->mx.mlx, w->mx.win, w->mx.floor, 0, 357);
	mlx_destroy_image(w->mx.mlx, w->mx.floor);
	mlx_put_image_to_window(w->mx.mlx, w->mx.win, w->mx.img, 0, 0);
	mlx_destroy_image(w->mx.mlx, w->mx.img);
}

int		ft_mouse_exit(void)
{
	exit(55);
}

int		main(void)
{
	t_wolf	w;

	ft_init(&w);
	ft_map(&w);
	mlx_hook(w.mx.win, 17, 0L, ft_mouse_exit, &w);
	mlx_hook(w.mx.win, 2, 5, my_key, &w);
	mlx_loop_hook(w.mx.mlx, ft_wolf, &w);
	mlx_loop(w.mx.mlx);
	return (0);
}
