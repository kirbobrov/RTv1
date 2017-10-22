/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_color.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbobrov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/15 20:41:21 by kbobrov           #+#    #+#             */
/*   Updated: 2017/10/15 20:41:25 by kbobrov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "rtv.h"

void    figure_color(t_rt *rt, t_material *mat)
{
//    rt->col.red = rt->current_light.intensity.red * mat->diffuse.red;
//    rt->col.green = rt->current_light.intensity.green * mat->diffuse.green;
//    rt->col.blue = rt->current_light.intensity.blue * mat->diffuse.blue;
    rt->col.red = mat->diffuse.red;
    rt->col.green = mat->diffuse.green;
    rt->col.blue = mat->diffuse.blue;
}

unsigned long createRGB(int r, int g, int b)
{
    return ((r & 0xff) << 16) + ((g & 0xff) << 8) + (b & 0xff);
}

void    lambert(t_rt *rt, t_ray *light)
{
    double      lambert;
    double      coss;

    light->dir = vector_normalize(&light->dir);
    lambert = vector_dot(&light->dir, &rt->ray.normal);
    (lambert < 0) ? lambert = 0 : 0;

/*

        rt->col.red = lambert * rt->col.red;
        rt->col.green = lambert * rt->col.green;
        rt->col.blue = lambert * rt->col.blue;

        coss = vector_coss(&rt->ray.normal, &light->dir);
        (coss < 0) ? coss = 0 : 0;

    rt->col.red += ((255 - rt->current_light.intensity.red) * (0.8 * pow(coss, 25) + 0.1 * coss));
    (rt->col.red > 255) ? rt->col.red = 255 : 0;
    rt->col.green += ((255 - rt->current_light.intensity.green) * (0.8 * pow(coss, 25) + 0.1 * coss));
    (rt->col.green > 255) ? rt->col.green = 255 : 0;
    rt->col.blue += ((255 - rt->current_light.intensity.blue) * (0.8 * pow(coss, 25) + 0.1 * coss));
    (rt->col.blue > 255) ? rt->col.blue = 255 : 0;
*/

    rt->col0.red += lambert * rt->current_light.intensity.red * rt->col.red;
    rt->col0.green += lambert * rt->current_light.intensity.green * rt->col.green;
    rt->col0.blue += lambert * rt->current_light.intensity.blue * rt->col.blue;

    coss = vector_coss(&rt->ray.normal, &light->dir);
    (coss < 0) ? coss = 0 : 0;
    rt->col0.red += ((1 - rt->col.red) * (0.8 * pow(coss, 25) + 0.1 * coss));
    (rt->col0.red > 1) ? rt->col0.red = 1 : 0;
    rt->col0.green += ((1 - rt->col.green) * (0.8 * pow(coss, 25) + 0.1 * coss));
    (rt->col0.green > 1) ? rt->col0.green = 1 : 0;
    rt->col0.blue += ((1 - rt->col.blue) * (0.8 * pow(coss, 25) + 0.1 * coss));
    (rt->col0.blue > 1) ? rt->col0.blue = 1 : 0;


    rt->lambert = lambert;
//    if (rt->col.shadow == 0)
//    {
//        rt->col.red += (0.8 - rt->cur_material.diffuse.red ) * pow(lambert, 15) * 0.9;
//        rt->col.green += (0.8 - rt->cur_material.diffuse.green) * pow(lambert, 15) * 0.9;
//        rt->col.blue += (0.8 - rt->cur_material.diffuse.blue) * pow(lambert, 15) * 0.9;
//        rt->col.a *= (1 - pow(lambert, 2));
//    }
}