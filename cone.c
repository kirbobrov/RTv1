//
// Created by Kyrylo Bobrov on 10/7/17.
//

#include <AppleTextureEncoder.h>
#include "rtv.h"


/*
a   = D|D - (1+k*k)*(D|V)^2


   b/2 = D|X - (1+k*k)*(D|V)*(X|V)
   c   = X|X - (1+k*k)*(X|V)^2

 */
/*
t_vector        cone_abc(t_ray *ray, t_cone *cone, t_vector *dist)
{
    t_vector    abc;

    abc.x = vector_dot(&ray->dir, &ray->dir)
    - (1 + pow(tan(cone->angle), 2))
    * pow(vector_dot(&ray->dir, &cone->rot), 2);


    abc.y = 2 * (vector_dot(&ray->dir, dist)
    - (1 + pow(tan(cone->angle), 2)) * (vector_dot(&ray->dir, &cone->rot)
    * vector_dot(dist, &cone->rot)));


    abc.z = vector_dot(dist, dist)
    - (1 + pow(tan(cone->angle), 2)) * pow(vector_dot(dist, &cone->rot), 2);
    return (abc);
}

 */
int     intersection_cone(t_ray *r, t_cone *c, t_rt *rt)
{
    float   A;
    float   B;
    float   C;

    t_vector    delta_p;
    t_vector    mult;
    t_vector    v1;
    t_vector    v2;


    t_vector    temp;


    float   multi;

    float k;

   // k = (float) tan(c->a);
   /// k = cn->a * M_PI / 180;
  ///  ra = 1 + k * k ;

   //// printf("r.x = %f\tr.y = %f\tr.z = %f\t\n", c->pos.x, c->pos.y, c->pos.z );

    delta_p = vector_sub(&r->start, &c->pos);

   /// dot = vector_dot(&r->dir, &c->dir);

    v1 = vector_scale(vector_dot(&r->dir, &c->dir), &c->dir);
    v1 = vector_sub(&r->dir, &v1);    ///// V - dot_product
    ////A = vector_dot(&v1, &v1);
    k = cosf(c->a) * cosf(c->a);
    multi = k * vector_dot(&v1, &v1);
    k = sinf(c->a)* sinf(c->a) * powf(vector_dot(&r->dir, &c->dir), 2);

    A = multi - k;


    v2 = vector_scale(vector_dot(&delta_p, &c->dir), &c->dir);
    v2 = vector_sub(&delta_p, &v2);

    multi = (float) 2.0 * vector_dot(&v1, &v2) * (cosf(c->a) * cosf(c->a)); //// левая часть В
    k = vector_dot(&r->dir, &c->dir) * vector_dot(&delta_p, &c->dir) * 2.0 * (sinf(c->a) * sinf(c->a));
    B = multi - k;


    C = (cosf(c->a) * cosf(c->a)) * vector_dot(&v2, &v2) - (sinf(c->a) * sinf(c->a)) * powf(vector_dot(&delta_p, &c->dir), 2);

    float discr;

    discr = B * B - 4 * A * C;

    ///discr = -discr;

    printf("discr == %f\n", discr);

    if (discr < 0)
        return (0);

    float x1 = (-B + sqrtf(discr)) / (2 * A);
    float x2 = (-B - sqrtf(discr)) / (2 * A);

    printf("x1 == %f\t x2 == %f\n", x1, x2);

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

t_vector        normale_cone(t_ray *ray, t_cone *cn)
{
    t_vector norm;
    t_vector tmp1;
    t_vector tmp2;

    cn->hit_point = vector_scale(ray->dist, &ray->dir); ////  D|V*t
    cn->hit_point = vector_add(&cn->hit_point, &ray->start); //// D|V*t + X|V

    tmp1 = vector_sub(&cn->hit_point, &cn->pos);
    tmp1 = vector_normalize(&tmp1);
    tmp2 = vector_scale((vector_len(&tmp1) / cosf(cn->a)), &cn->dir);
//    if (vector_dot(&norm, &cn->dir) < 0)
//        tmp2 = change_vector_direction(&tmp2);
    norm = vector_sub(&tmp1, &tmp2);
    return (vector_normalize(&norm));
}


//int     intersection_cone(t_ray *ray, t_cone *cn, t_rt *rt)
//{
//    t_vector X;
//    X.x = ray->start.x - cn->pos.x;
//    X.y = ray->start.y - cn->pos.y;
//    X.z = ray->start.z - cn->pos.z;
//    t_vector va;
//    va.x = cn->dir.x;
//    va.y = cn->dir.y;
//    va.z = cn->dir.z;
//
//    double k = tan(RAD(cn->a) / 2);
//
//    double a = vector_dot(&ray->dir, &ray->dir) - ((1 + (k * k)) * pow(vector_dot(&ray->dir, &va), 2));
//    double b = 2 * (vector_dot(&ray->dir, &X) - ((1 + (k * k)) * vector_dot(&ray->dir, &va) * vector_dot(&X, &va)));
//    double c = vector_dot(&X, &X) - ((1 + (k * k)) * pow(vector_dot(&X, &va), 2));
//    double we = (b*b) - (4 * a * c);
//
//    if(we < 0)
//        return(0);
//    else {
//        double t1 = (-b - sqrt(we))/ (2 * a);
//        double t2 = (-b + sqrt(we))/ (2 * a);
//
//        if(t2 > 0 && t1 > t2) {
//            ray->dist = t2;
//        }
//        else if(t1 > 0 && t2 >= t1) {
//            ray->dist = t1;
//        }
//    }
//    return (0);
//}



//t_vector        normale_cone(t_ray *ray, t_cone *cn)
//{
//    t_vector normale;
//    t_vector temp;
//    t_vector scale_cent;
//    float k;
//    float ra;
//
//    k = tan(RAD(cn->a) / 2);
//    ra = 1 + k * k ;
//
//
//    cn->hit_point = vector_scale(ray->dist, &ray->dir); ////  D|V*t
//    cn->hit_point = vector_add(&cn->hit_point, &ray->start); //// D|V*t + X|V
//
//    temp = vector_sub(&cn->hit_point, &cn->pos);
//
//    scale_cent = vector_scale(vector_dot(&temp, &cn->dir), &cn->dir);
//
//    temp = vector_scale(ra, &temp);
//    normale = vector_sub(&temp, &scale_cent);
//
//    return (vector_normalize(&normale));
//}

