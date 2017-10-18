/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersection.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbobrov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/15 20:42:13 by kbobrov           #+#    #+#             */
/*   Updated: 2017/10/15 20:42:16 by kbobrov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv.h"

t_vector    plane_normale(t_plane *pl, t_ray *ray)
{
    ray->hit_point = vector_scale(ray->dist, &ray->dir);
    ray->hit_point = vector_add(&ray->hit_point, &ray->start);
    return(vector_normalize(&pl->dir));
}

int    intersection(t_rt *rt)
{
    int    i;

    i = -1;
    while (++i < 6)
    {
        if (rt->obj[i].id == CONUS)
         {
             if (intersection_cone(&rt->ray, (t_cone *) rt->obj[i].obj, rt))
            {
                rt->ray.normal = normale_cone(&rt->ray, (t_cone *) rt->obj[i].obj);
                figure_color(rt, &rt->mat[rt->con->material]);
            }
         }
        else if (rt->obj[i].id == SPHERE)
        {
            if (intersection_sphere(&rt->ray, (t_sphere *) rt->obj[i].obj))
            {
                normale_sphere(rt, (t_sphere *) rt->obj[i].obj);
                figure_color(rt, &rt->mat[i]);
            }
        }
        else if (rt->obj[i].id == CYLINDER)
        {
            if (intersection_cylinder(&rt->ray, (t_cylinder *) rt->obj[i].obj, rt))
            {
                rt->ray.normal = normale_cylinder(&rt->ray, (t_cylinder *) rt->obj[i].obj);
                figure_color(rt, &rt->mat[rt->cyl->material]);
            }
        }
        else if (rt->obj[i].id == PLANE)
        {
            if (intersection_plane(&rt->ray, (t_plane *) rt->obj[i].obj, rt))
            {
                rt->ray.normal = plane_normale((t_plane *) rt->obj[i].obj , &rt->ray);
                rt->ray.normal = vector_normalize(&rt->ray.normal);
                figure_color(rt, &rt->mat[rt->pl->material]);
            }
        }
    }
    if (rt->ray.dist != 2000001)
        return (1);
    return (0);
}
