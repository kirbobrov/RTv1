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

float   ft_sqrtp(float a ,float b ,float c)
{
    float   d;
    float   x;
    float   x1;
    float   x2;

    d = b * b - 4 * a * c;
    if (d == 0)
    {
        x = b / (2 * a);
        return (x);
    }
    else if (d > 0)
    {
        x1 = (-b + sqrtf(d)) / (2 * a);
        x2 = (-b - sqrtf(d)) / (2 * a);
        if (x1 < x2)
            return (x1);
        else
            return (x2);
    }
    else
        return (0);
}

int ft_intersect_sphere(t_ray *r, t_sphere *s) ///// write to shadows one more arg
{
    float   A;
    float   B;
    float   C;
    float   discr;
    t_vector    dist;

    A = vector_dot(&r->dir, &r->dir);
    dist = vector_sub(&r->start, &s->pos);
    B = 2 * vector_dot(&r->dir, &dist);
    C = vector_dot(&dist, &dist) - (s->radius * s->radius);

    discr = B * B - 4 * A * C;

    if (discr < 0)
        return (0);

    float x1 = (-B + sqrtf(discr)) / (2 * A);
    float x2 = (-B - sqrtf(discr)) / (2 * A);

    if (x1 < 0)
        x1 = 100000000;
    if (x2 < 0)
        x2 = 100000000;
    if (x1 > x2)
        x1 = x2;

    if (x1 > 0.0001 && x1 < r->dist)
    {
        r->dist = x1;
        return (1);
    }
    return (0);
}

unsigned long createRGB(int r, int g, int b)
{
    return ((r & 0xff) << 16) + ((g & 0xff) << 8) + (b & 0xff);
}

int		ft_sphere(t_rt *rt)
{
    int         hit;
    int     yc;
    int     xc;
    int     y;
    int     x;
    float   coss;

    rt->ray.start.x = 0;
    rt->ray.start.y = 0;
    rt->ray.start.z = -800;

//    rt->col.red = 255.0;
//    rt->col.green = 255.0;
//    rt->col.blue = 0.0;

    yc = SIZE_Y / 2;
    xc = SIZE_X / 2;
    y = -yc;
    while (y < yc)
    {
        x = -xc;
        while (x < xc)
        {
//            float   coef = 1.0;
            rt->ray.dir.x = x - rt->ray.start.x;
            rt->ray.dir.y = y - rt->ray.start.y;
            rt->ray.dir.z = 0 - rt->ray.start.z;
            rt->ray.dir = vector_normalize(&rt->ray.dir);

            rt->ray.dist = 200000;
            /* Check if the ray intersects with the shpere */
            hit = ft_intersect_sphere(&rt->ray, &rt->sph);    /// ray hit with sphere

            if (hit == 1) {
                t_vector scaled;

                scaled = vector_scale(rt->ray.dist, &rt->ray.dir);

                rt->ray.hit_point = vector_add(&rt->ray.start, &scaled);
                rt->ray.normal = vector_sub(&rt->ray.hit_point, &rt->sph.pos); //// find normale
                rt->ray.normal = vector_normalize(&rt->ray.normal);

                t_vector dist; /// distantion

                dist = vector_sub(&rt->light.pos, &rt->ray.hit_point);
//             if((vectorDot(&rt->ray.normal, &dist) > 0.0f))
//                continue ;

                float t;

                t = vector_len(&dist);///sqrtf(vector_dot(&dist, &dist));
//                if((t > 0.0f))
//                  continue ;

                t_ray lightRay;

                lightRay.start = rt->ray.hit_point;
                lightRay.dir = vector_scale((1 / t), &dist);

                float lambert;
                lambert = vector_dot(&lightRay.dir, &rt->ray.normal); /// lambert difusion
//                if (lambert < 0)
//                    lambert = 0;
                (lambert < 0) ? lambert = 0 : 0;
                int hit2;

                hit2 = ft_intersect_sphere(&lightRay, &rt->sph); /// ray
                /// printf("hit2 === %d\t\n", hit2);
                //printf("hit == %d\n", hit);
//            printf("rt->col.blue == %f\t rt->col.green == %f\trt->col.red == %f\n", rt->col.blue, rt->col.green, rt->col.red);
//                lambert += pow(lambert, 16) / 230;
                if (hit2 == 0)
                {
//                 rt->col.a = lambert * rt->light.intensity.a * rt->light.intensity.a * 255;
                   rt->col.red = lambert * rt->light.intensity.red * rt->light.intensity.red * 255;
                   rt->col.green = lambert * rt->light.intensity.green * rt->mat.diffuse.green * 255;
                   rt->col.blue = lambert * rt->light.intensity.blue * rt->mat.diffuse.blue * 255;

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
//                coef *= rt->mat.reflection;

//                rt->ray.start = rt->ray.hit_point;
//                float   reflect = 2.0f * vector_dot(&rt->ray.dir, &dist);
//                t_vector    tmp = vector_scale(reflect, &dist);
//                rt->ray.dir = vector_sub(&rt->ray.dir, &tmp);

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


           /* if(hit != 0)
                printf("rt->col.blue == %f\t rt->col.green == %f\trt->col.red == %f\n", rt->col.blue, rt->col.green, rt->col.red);
*/
                ft_img_color(rt, x + xc, y + yc);
            x++;
        }
        y++;
    }
    return (0);
}
