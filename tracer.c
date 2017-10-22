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
  ///  double      coss;
    double      t;
  ///  double      lambert;
    t_ray       lightRay;
    t_vector    dist;

    ft_imageinit(&rt->mx);

    y = -1;
    while (++y < SIZE_Y)
    {
        x = -1;
        while (++x < SIZE_X)
        {
            rt->ray.start.x = rt->ray.start0.x;
            rt->ray.start.y = rt->ray.start0.y;
            rt->ray.start.z = rt->ray.start0.z;

            rt->ray.dir.x = rt->ray.dir0.x;
            rt->ray.dir.y = rt->ray.dir0.y;
            rt->ray.dir.z = rt->ray.dir0.z;

            camera(rt, x, y);
            ft_rotate(rt);

            rt->col0.red = 0;
            rt->col0.green = 0;
            rt->col0.blue = 0;

            rt->col.red = 0;
            rt->col.green = 0;
            rt->col.blue = 0;

            if (intersection(rt))
            {


                int i = 0;
                while (i < 2)
                {
                    rt->current_light = rt->light[i];

                dist = vector_sub(&rt->current_light.pos, &rt->ray.hit_point);

                rt->ray.dist = vector_len(&dist);

                lightRay.dir = vector_scale((1 / rt->ray.dist), &dist);
                ///rt->current_light = rt->light[0];
             ///lambert = vector_dot(&lightRay.dir, &rt->ray.normal);
             ///(lambert < 0) ? lambert = 0 : 0;


                lambert(rt, &lightRay);

                    ///double lambert;

//                    lightRay.dir = vector_normalize(&lightRay.dir);
//                    lambert = vector_dot(&lightRay.dir, &rt->ray.normal);
//                    (lambert < 0) ? lambert = 0 : 0;


                t_vector    shadow;
                shadow = vector_sub(&rt->current_light.pos, &rt->ray.hit_point);
                double    len;
                len = vector_len(&shadow);

                rt->ray.dist = len;
                shadow = vector_normalize(&shadow);

                rt->ray.dir = shadow;
                rt->ray.start = rt->ray.hit_point;

                 //   double coss = 0;
         ///       if (intersection(rt))
            ///    {
               ///     rt->col.red = 0.5 * rt->lambert;
                  ///  rt->col.blue = 0.5 * rt->lambert;
                   /// rt->col.green = 0.5 * rt->lambert;

//                    rt->col0.red += (0.8 - rt->cur_material.diffuse.red ) * pow(rt->lambert, 15) * 0.9;
//        rt->col0.green += (0.8 - rt->cur_material.diffuse.green) * pow(rt->lambert, 15) * 0.9;
//        rt->col0.blue += (0.8 - rt->cur_material.diffuse.blue) * pow(rt->lambert, 15) * 0.9;
//        rt->col0.a *= (1 - pow(rt->lambert, 2));
           ///         lambert(rt, &lightRay);

                    //
//                    coss = vector_coss(&rt->ray.normal, &lightRay.dir);
//                    (coss < 0) ? coss = 0 : 0;
//                    rt->col0.red += ((1 - rt->col.red) * (0.8 * pow(coss, 25) + 0.1 * coss));
//                    (rt->col0.red > 1) ? rt->col0.red = 1 : 0;
//                    rt->col0.green += ((1 - rt->col.green) * (0.8 * pow(coss, 25) + 0.1 * coss));
//                    (rt->col0.green > 1) ? rt->col0.green = 1 : 0;
//                    rt->col0.blue += ((1 - rt->col.blue) * (0.8 * pow(coss, 25) + 0.1 * coss));
//                    (rt->col0.blue > 1) ? rt->col0.blue = 1 : 0;
               /// }

                i++;
                }
            }
            ft_img_color(rt, x, y);
        }
    }
    ft_put_image((t_mlx *) &rt->mx.mlx);
}