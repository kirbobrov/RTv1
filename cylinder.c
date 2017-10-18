/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbobrov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/15 20:41:03 by kbobrov           #+#    #+#             */
/*   Updated: 2017/10/15 20:41:07 by kbobrov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "rtv.h"

int     intersection_cylinder(t_ray *r, t_cylinder *c, t_rt *rt)
{
    t_vector    abc;
    double   dot;
    double   dot2;
    t_vector    delta_p;
    t_vector    mult;
    t_vector    v1;
    t_vector    v2;

    dot = vector_dot(&r->dir, &c->dir);
    mult = vector_scale(dot, &c->dir);
    v1 = vector_sub(&r->dir, &mult);
    abc.x = vector_dot(&v1, &v1);
    delta_p = vector_sub(&r->start, &c->pos);
    dot2 = vector_dot(&delta_p, &c->dir);
    mult = vector_scale(dot2, &c->dir);
    v2 = vector_sub(&delta_p, &mult);
    abc.y = vector_dot(&v1, &v2);
    abc.y *= 2;
    abc.z = vector_dot(&v2, &v2);
    abc.z = abc.z - c->radius * c->radius;
    if (discr(&abc, r))
        return(1);
    return (0);
}

t_vector        normale_cylinder(t_ray *ray, t_cylinder *cyl)
{
    t_vector    normale;
    t_vector    temp;
    t_vector    scale_cent;

    ray->hit_point = vector_scale(ray->dist, &ray->dir);
    ray->hit_point = vector_add(&ray->hit_point, &ray->start);
    temp = vector_sub(&ray->hit_point, &cyl->pos);
    scale_cent = vector_scale(vector_dot(&temp, &cyl->dir), &cyl->dir);
    normale = vector_sub(&temp, &scale_cent);
    return (vector_normalize(&normale));
}
