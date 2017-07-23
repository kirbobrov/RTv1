//
// Created by Kyrylo Bobrov on 04.07.17.
//


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

void	ft_img_color(t_rt *rt)
{
    int pix;

    if (rt->y >= 0 && rt->x >= 0 && rt->y < SIZE_Y && rt->x < SIZE_X)
    {
        pix = rt->y * rt->mx.sizel + (rt->x * 4);
        if (pix < SIZE_Y * SIZE_X * 4)
        {
            rt->mx.buf[pix] = rt->cl.blue * 255; ////blue;
            rt->mx.buf[pix + 1] = rt->cl.green * 255; ///w->f->green;
            rt->mx.buf[pix + 2] = rt->cl.red * 255; ///w->f->red;
        }
    }
}