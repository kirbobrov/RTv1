/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_sphere.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbobrov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/12 18:12:41 by kbobrov           #+#    #+#             */
/*   Updated: 2017/08/12 18:12:46 by kbobrov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv.h"

int    blick(t_rt *rt)
{

    int b = 0;

    if (rt->fpointer == 0)
    {
        (intersection_sphere(&rt->ray, &rt->sph[2], rt)) ? b = 1 : 0;
    }
    if (rt->fpointer == 1)
    {
        (intersection_cylinder(&rt->ray, &rt->cyl, rt)) ? b = 1 : 0;
    }
    return (b);
}

void    figure_intersection(t_rt *rt)
{
    int i = 0;

    if (intersection_cylinder(&rt->ray, &rt->cyl, rt))
    {

        rt->ray.normal = normale_cylinder(&rt->ray, &rt->cyl);
        figure_color(rt, &rt->mat[3]); /// &rt->mat[i]
        rt->hit = 1;
        rt->pointer = 1;
    }
     else
    {
        while (i < 3)
        {
            if (intersection_sphere(&rt->ray, &rt->sph[i], rt))
            {
                normale_sphere(rt, i);
                figure_color(rt, &rt->mat[i]); /// &rt->mat[i]
                rt->hit = 1;
            }
            i++;
        }
        rt->pointer = 0;
    }
}

int		ft_sphere(t_rt *rt)
{
    int     yc;
    int     xc;
    int     y;
    int     x;
    float   coss;
    int     i;

    rt->ray.start.x = 0;
    rt->ray.start.y = 0;
    rt->ray.start.z = -800;

    yc = SIZE_Y / 2;
    xc = SIZE_X / 2;
    y = -yc;
    while (y < yc)
    {
        x = -xc;
        while (x < xc)
        {
            i = 0;
            rt->ray.dir.x = x - rt->ray.start.x;
            rt->ray.dir.y = y - rt->ray.start.y;
            rt->ray.dir.z = 0 - rt->ray.start.z;
            rt->ray.dir = vector_normalize(&rt->ray.dir);

            rt->ray.dist = 200000;

            figure_intersection(rt);

            if (rt->hit == 1)
            {
               t_vector dist; /// distantion

                dist = vector_sub(&rt->light.pos, &rt->ray.hit_point);

                float t;

                t = vector_len(&dist);///sqrtf(vector_dot(&dist, &dist));

                t_ray lightRay;

                lightRay.start = rt->ray.hit_point;
                lightRay.dir = vector_scale((1 / t), &dist);

                float lambert;
                lambert = vector_dot(&lightRay.dir, &rt->ray.normal); /// lambert difusion

                (lambert < 0) ? lambert = 0 : 0;

                //rt->hit2 = intersection_cylinder(&lightRay, &rt->cyl, rt);

                ///rt->hit2 = intersection_sphere(&lightRay, &rt->sph[i], rt); /// ray

                rt->hit2 = blick(rt);
               if (rt->hit2 == 0)
                {
//                 rt->col.a = lambert * rt->light.intensity.a * rt->light.intensity.a * 255;
//                   rt->col.red = lambert * rt->light.intensity.red * rt->mat[i].diffuse.red * 255;
//                   rt->col.green = lambert * rt->light.intensity.green * rt->mat[i].diffuse.green * 255;
//                   rt->col.blue = lambert * rt->light.intensity.blue * rt->mat[i].diffuse.blue * 255;

                    rt->col.red = lambert * rt->col.red;
                    rt->col.green = lambert * rt->col.green;
                    rt->col.blue = lambert * rt->col.blue;

//                    rt->ray.dir = vector_normalize(&rt->ray.dir);
                    coss = vector_coss(&rt->ray.normal, &lightRay.dir);
                    (coss < 0) ? coss = 0 : 0;
//                    coss = -coss;

//                    rt->col.a = (230 * (1 - coss));
                    rt->col.red += ((255 - rt->col.red) * (0.9 * pow(coss, 25) + 0.1 * coss));
                    rt->col.green += ((255 - rt->col.green) * (0.9 * pow(coss, 25) + 0.1 * coss));
                    rt->col.blue += ((255 - rt->col.blue) * (0.9 * pow(coss, 25) + 0.1 * coss));



                    /// printf("lambert == %f\t normal.x == %f\tnormal.y == %f\tnormal.z == %f\n", lambert, rt->ray.normal.x, rt->ray.normal.y, rt->ray.normal.z);
//                      printf("rt->col.blue == %f\t rt->col.green == %f\trt->col.red == %f\t coss == %f\n", rt->col.blue, rt->col.green, rt->col.red, coss);
                }
                else
                {
                    rt->col.a = 0.9;
                    rt->col.blue = 0.5;
                    rt->col.green = 1 /255;
                    rt->col.red = 0.1;
                    printf(" HELLO \n"); //// shadow
                }
            }
            else
            {
                rt->col.blue = 0.3;
                rt->col.green = 0.3;
                rt->col.red = 0.3;
            }

          /*  coef *= rt->mat.reflection;

            *//* The reflected ray start and direction *//*
            rt->ray.start = rt->ray.hit_point;
            float reflect;
            reflect = 2.0f * vectorDot(&rt->ray.dir, &dist);
            t_vector tmp;
            tmp = vector_scale(reflect, &dist);
            rt->ray.dir = ft_vectorsub(&rt->ray.dir, &tmp);*/

                ft_img_color(rt, x + xc, y + yc);
            x++;
        }
        y++;
    }
    return (0);
}
