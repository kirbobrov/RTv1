/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbobrov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/15 20:42:40 by kbobrov           #+#    #+#             */
/*   Updated: 2017/10/15 20:42:49 by kbobrov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//
// Created by Kyrylo Bobrov on 9/28/17.
//

#include "rtv.h"


int intersection_plane(t_ray *ray, t_plane *pl, t_rt *rt)
{

    double        dotn;
    t_vector        temp;
    double        t;
 ///   pl->dir = vector_normalize(&pl->dir);

   /// ray->hit_point = (t_vector) {0, 0, 0};
    dotn = vector_dot(&pl->dir, &ray->dir);
    if (fabs(dotn) > 0.001)
    {
        temp = vector_sub(&pl->pos, &ray->start);
//        if (vector_dot(&temp, &pl->dir) / dotn < 0)
//        {
//            temp.x = -temp.x;
//            temp.y = -temp.y;
//            temp.z = -temp.z;
//        }
        t = vector_dot(&temp, &pl->dir) / dotn;
        if (t > 0.001 && t < ray->dist)
        {
            ray->dist = t;
            return (1);
        }
    }
    return (0);
}


/*

  int            inter_plane(t_vec ray_o, t_vec ray_d, t_all *all)
{
    t_vec    math;
    double    denom;
    double    result;

    math = vec_sub(all->plane.position, ray_o);
    denom = dot(ray_d, all->plane.normal);
    if (fabs(denom) < 1e-6)
        return (-1);
    else
    {
        result = dot(math, all->plane.normal) / denom;
        all->plane.t = result;
        if (result < 0)
            return (-1);
        if (all->plane.t >= 0)
            return (1);
        else
            return (-1);
    }
    return (-1);
}

 */
