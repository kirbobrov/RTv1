/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cone.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbobrov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/15 20:40:49 by kbobrov           #+#    #+#             */
/*   Updated: 2017/10/15 20:40:52 by kbobrov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "rtv.h"

int     intersection_cone(t_ray *r, t_cone *c, t_rt *rt)
{
    double   A;
    double   B;
    double   C;

        double		dot[2];
        t_vector	mult[2];
        t_vector	sub[2];
        t_vector	dp;

        double sqc;
        double sqs;

        sqc = cos(c->a) * cos(c->a);
        sqs = sin(c->a) * sin(c->a);

        dp = vector_sub(&r->start, &c->pos);
        dot[0] = vector_dot(&r->dir, &c->dir);
        mult[0] = vector_scale(dot[0], &c->dir);
        sub[0] = vector_sub(&r->dir, &mult[0]);
        dot[1] = vector_dot(&dp, &c->dir);
        mult[1] = vector_scale(dot[1], &c->dir);
        sub[1] = vector_sub(&dp, &mult[1]);
        A = sqc * vector_dot(&sub[0], &sub[0]);
        A -= sqs * dot[0] * dot[0];
        B = 2 * sqc * vector_dot(&sub[0], &sub[1]);
        B -= 2 * sqs * dot[0] * dot[1];
        C = sqc * vector_dot(&sub[1], &sub[1]);
        C -= sqs * dot[1] * dot[1];


    double discr;

    discr = B * B - 4 * A * C;

    if (discr < 0)
        return (0);
   /// double x1 = (-B + sqrt(discr)) / (2 * A);
    double x2 = (-B - sqrt(discr)) / (2 * A);

    if (x2 > 0.00001 && x2 < r->dist)
    {
        r->dist = x2;
        return (1);
    }
    return (0);
}

t_vector        normale_cone(t_ray *ray, t_cone *cn)
{

    t_vector	b;
    t_vector n;

    ray->hit_point = vector_scale(ray->dist, &ray->dir); ////  D|V*t
    ray->hit_point = vector_add(&ray->hit_point, &ray->start); //// D|V*t + X|V

    b = vector_sub( &ray->hit_point, &cn->pos);
    n = vector_scale(vector_coss(&b, &cn->dir), &cn->dir);
    n = vector_sub(&b, &n);
    n = cross_product(&b, &n);
    n = cross_product(&n, &b);

    return (vector_normalize(&n));
}

//    t_vector norm;
//    t_vector tmp1;
//    t_vector tmp2;
//
//    t_vector scaled;
//
//    scaled = vector_scale(ray->dist, &ray->dir);
//
//    cn->dir = vector_normalize(&cn->dir);
//   ///ray->hit_point = vector_scale(ray->dist, &ray->dir); ////  D|V*t
//   ray->hit_point = vector_add(&scaled, &ray->start); //// D|V*t + X|V
//
//    tmp1 = vector_sub(&cn->hit_point, &cn->pos);
//    norm = vector_normalize(&tmp1);
//    tmp2 = vector_scale((vector_len(&norm) / cos(cn->a)), &cn->dir);
//    if (vector_dot(&norm, &cn->dir) < 0)
//    {
//        tmp2.x = -tmp2.x;
//        tmp2.y = -tmp2.y;
//        tmp2.z = -tmp2.z;
//    }
//    tmp1 = vector_sub(&norm, &tmp2);
//    return (vector_normalize(&tmp1));

