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

/// ∆p = p- pa
/// A = (V - (V,Va)Va)^2
/// B = 2* (v - (V,Va)va , ∆p - (∆p, Va) Va)
/// C = (∆p - (∆p, Va) Va)^2 - r^2

///where ∆p = p- pa
 /// V - direction vector camera
/// Va - direction vector cylinder
/// (V,Va) - voctor_dot_product(v, va)
/// p = point of camera
/// pa - point of cylinder
/// (V)^2 - vector_dot_product

int     intersection_cylinder(t_ray *r, t_cylinder *c, t_rt *rt)
{
    double   A;
    double   B;
    double   C;
    double   dot;
    double   dot2;
    double   ra;
    t_vector    delta_p;
    t_vector    mult;
    t_vector    v1;
    t_vector    v2;

    dot = vector_dot(&r->dir, &c->dir);
    mult = vector_scale(dot, &c->dir);
    v1 = vector_sub(&r->dir, &mult); //// (V - (V, Va)Va)

    A = vector_dot(&v1, &v1);

    delta_p = vector_sub(&r->start, &c->pos);
    dot2 = vector_dot(&delta_p, &c->dir);
    mult = vector_scale(dot2, &c->dir);
    v2 = vector_sub(&delta_p, &mult);
    B = vector_dot(&v1, &v2);
    B *= 2;

    ra = c->radius * c->radius;

    C = vector_dot(&v2, &v2);
    C = C - ra;

double discr;

    discr = B * B - 4 * A * C;

    if (discr < 0)
        return (0);

 ///   double x1 = (-B + sqrt(discr)) / (2 * A);
    double x2 = (-B - sqrt(discr)) / (2 * A);
    if (x2 > 0.00001 && x2 < r->dist)
    {
        r->dist = x2;
        return (1);
    }
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
