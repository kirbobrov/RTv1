

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

/*

    a   = D|D - (D|V)^2
   b/2 = D|X - (D|V)*(X|V)
   c   = X|X - (X|V)^2 - r*r


  m = D|V*t + X|V
   N = nrm( P-C-V*m )
 */

/*
 *
 * tmp[0] = vector_mult(vector_dot_product(&r->dir, &cyl->dir), &cyl->dir);
    tmp[0] = vector_substract(&r->dir, &tmp[0]);
    n.a = vector_dot_product(&tmp[0], &tmp[0]);



    delta = vector_substract(&r->origin, &cyl->pos);
    tmp[1] = vector_mult(vector_dot_product(&delta, &cyl->dir), &cyl->dir);
    tmp[1] = vector_substract(&delta, &tmp[1]);
    n.b = 2 * vector_dot_product(&tmp[0], &tmp[1]);
    n.c = vector_dot_product(&tmp[1], &tmp[1]) - pow(cyl->r, 2);
 */


int     intersection_cylinder(t_ray *r, t_cylinder *c, t_rt *rt)
{
    float   A;
    float   B;
    float   C;
    float   dot;
    float   dot2;
    float   ra;
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

float discr;

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

t_vector        normale_cylinder(t_ray *ray, t_cylinder *cyl)
{
    t_vector    normale;
    t_vector    temp;
    t_vector    scale_cent;


    cyl->hit_point = vector_scale(ray->dist, &ray->dir);
    cyl->hit_point = vector_add(&cyl->hit_point, &ray->start);
    temp = vector_sub(&cyl->hit_point, &cyl->pos);
    scale_cent = vector_scale(vector_dot(&temp, &cyl->dir), &cyl->dir);
    normale = vector_sub(&temp, &scale_cent);

    return (vector_normalize(&normale));
}