/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbobrov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/15 20:43:09 by kbobrov           #+#    #+#             */
/*   Updated: 2017/10/15 20:43:10 by kbobrov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//
// Created by Kyrylo Bobrov on 8/14/17.
//

#include "rtv.h"

void    normale_sphere(t_rt *rt, t_sphere *sph)
{
    t_vector scaled;

    scaled = vector_scale(rt->ray.dist, &rt->ray.dir);

    rt->ray.hit_point = vector_add(&rt->ray.start, &scaled);
    rt->ray.normal = vector_sub(&rt->ray.hit_point, &sph->pos); //// find normale
    rt->ray.normal = vector_normalize(&rt->ray.normal);
}


int intersection_sphere(t_ray *r, t_sphere *s, t_rt *rt) ///// write to shadows one more arg
{
    double   A;
    double   B;
    double   C;
    double   discr;
    t_vector    dist;

    A = vector_dot(&r->dir, &r->dir);
    dist = vector_sub(&r->start, &s->pos);
    B = 2 * vector_dot(&r->dir, &dist);
    C = vector_dot(&dist, &dist) - (s->radius * s->radius);

    discr = B * B - 4 * A * C;

    if (discr < 0)
        return (0);

    double x1 = (-B + sqrt(discr)) / (2 * A);
    double x2 = (-B - sqrt(discr)) / (2 * A);

//    if (x1 < 0)
//        x1 = 100000000;
//    if (x2 < 0)
//        x2 = 100000000;
//    if (x1 > x2)
//        x1 = x2;

    if (x2 > 0.00001 && x2 < r->dist)
    {
        r->dist = x2;
        return (1);
    }
    return (0);
}
