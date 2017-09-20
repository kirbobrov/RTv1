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



unsigned long createRGB(int r, int g, int b)
{
    return ((r & 0xff) << 16) + ((g & 0xff) << 8) + (b & 0xff);
}



t_vector        normale_cylinder(t_ray *ray, t_cylinder *cyl)
{
    t_vector    norm;
    t_vector    c;
    float       temp;

    norm = vector_sub(&ray->start, &cyl->pos);
    temp = vector_dot(&norm, &cyl->pos);
    c = vector_scale(temp, &cyl->pos);
    norm = vector_sub(&norm, &c);
    norm = vector_normalize(&norm);
    return (norm);
}



int		ft_sphere(t_rt *rt)
{
    int         hit;
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
//            hit = 0;
            i = 0;
//           float   coef = 1.0;
            rt->ray.dir.x = x - rt->ray.start.x;
            rt->ray.dir.y = y - rt->ray.start.y;
            rt->ray.dir.z = 0 - rt->ray.start.z;
            rt->ray.dir = vector_normalize(&rt->ray.dir);

            rt->ray.dist = 200000;
            /* Check if the ray intersects with the figure */
///            sphere_color(&rt, &rt->sph[1]);
          while (i < 3)
         {
            ///if(intersect_cylinder(&rt->ray, &rt->cyl))
          ///  printf("intersect with cylinder %d\n", find_abc_cylinder(&rt->ray, &rt->cyl, rt));

               if (ft_intersect_sphere(&rt->ray, &rt->sph[i], rt)) //// find normale
                   /// if (find_abc_cylinder(&rt->ray, &rt->cyl, rt))
                    {
                   /// printf("1\n");
                     normale_sphere(rt, i);

                  ////  normale_cylinder(&rt->ray, &rt->cyl);

                    sphere_color(rt, &rt->mat[i]); /// &rt->mat[i]

                    hit = 1;
                }
                    //hit = 1;
                i++;
           }
            if (hit == 1)
            {
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

                (lambert < 0) ? lambert = 0 : 0;
                int hit2;

                ///hit2= find_abc_cylinder(&lightRay, &rt->cyl, rt);
               /// hit2 = intersect_cylinder(&lightRay, &rt->cyl);
                hit2 = ft_intersect_sphere(&lightRay, &rt->sph[i], rt); /// ray
                /// printf("hit2 === %d\t\n", hit2);


               if (hit2 == 0)
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
