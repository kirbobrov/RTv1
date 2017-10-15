/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tracer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbobrov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/15 20:43:17 by kbobrov           #+#    #+#             */
/*   Updated: 2017/10/15 20:43:20 by kbobrov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv.h"

void		tracer(t_rt *rt)
{
    int         y;
    int         x;
    double      coss;
    double      t;
    double      lambert;
    t_ray       lightRay;
    t_vector    dist;

    ft_imageinit(&rt->mx);
    y = -1;
    while (++y < SIZE_Y)
    {
        x = -1;
        while (++x < SIZE_X)
        {
            camera(rt, x, y);
            if (intersection(rt))
            {
                dist = vector_sub(&rt->light.pos, &rt->ray.hit_point);

                t = vector_len(&dist);

                lightRay.dir = vector_scale((1 / t), &dist);

                lambert = vector_dot(&lightRay.dir, &rt->ray.normal);

                (lambert < 0) ? lambert = 0 : 0;

                if (intersection(rt))
                {
                    rt->col.red = lambert * rt->col.red;
                    rt->col.green = lambert * rt->col.green;
                    rt->col.blue = lambert * rt->col.blue;

                    coss = vector_coss(&rt->ray.normal, &lightRay.dir);
                    (coss < 0) ? coss = 0 : 0;

                    rt->col.red += ((255 - rt->col.red) * (0.9 * pow(coss, 25) + 0.1 * coss));
                    rt->col.green += ((255 - rt->col.green) * (0.9 * pow(coss, 25) + 0.1 * coss));
                    rt->col.blue += ((255 - rt->col.blue) * (0.9 * pow(coss, 25) + 0.1 * coss));
                }
                else
                {
                    rt->col.a = 0.9;
                    rt->col.blue = 0.5;
                    rt->col.green = 1 /255;
                    rt->col.red = 0.1;
                }
            }
            else
            {
                rt->col.blue = 0.3;
                rt->col.green = 0.3;
                rt->col.red = 0.3;
            }
            ft_img_color(rt, x, y);
     //       x++;
        }
    //    y++;
    }
   /// printf("2\n");
    ft_put_image((t_mlx *) &rt->mx.mlx);
   /// printf("3\n");

//    mlx_hook(rt->mx.win, 17, 0L, ft_mouse_exit, &rt);
//    mlx_hook(rt->mx.win, 2, 5, ft_keys, &rt);
//    mlx_loop(rt->mx.mlx);
}
