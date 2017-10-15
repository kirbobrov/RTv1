/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbobrov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/12 18:11:18 by kbobrov           #+#    #+#             */
/*   Updated: 2017/10/15 20:41:38 by kbobrov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv.h"

void	ft_put_image(t_mlx *mx)
{
	mlx_put_image_to_window(mx->mlx, mx->win, mx->img, 0, 0);
	mlx_destroy_image(mx->mlx, mx->img);
}

void ft_mlxinit(t_mlx *mx)
{
	mx->mlx = mlx_init();
	mx->win = mlx_new_window(mx->mlx, SIZE_X, SIZE_Y, "RTv1 by kbobrov");
}

void	ft_imageinit(t_mlx *mx)
{
	mx->img = mlx_new_image(mx->mlx, SIZE_X, SIZE_Y);
	mx->bpp = 0;
	mx->endl = 0;
	mx->sizel = 0;
	mx->buf = mlx_get_data_addr(mx->img, &mx->bpp, &mx->sizel, &mx->endl);
}

void	ft_img_color(t_rt *rt, int x, int y)
{
    int pix;

    if (y >= 0 && x >= 0 && y < SIZE_Y && x < SIZE_X)
    {
        pix = y * rt->mx.sizel + (x * 4);
        if (pix < SIZE_Y * SIZE_X * 4)
        {
            rt->mx.buf[pix] = rt->col.blue;
            rt->mx.buf[pix + 1] = rt->col.green;
            rt->mx.buf[pix + 2] = rt->col.red;
        }
    }
}
