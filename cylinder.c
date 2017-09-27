//
// Created by Kyrylo Bobrov on 8/14/17.
//
/*


 */

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
t_vector        cyl_abc(t_ray *ray, t_cylinder *cyl, t_vector *dist)
{
    t_vector    abc;

    abc.x = vector_dot(&ray->dir, &cyl->dir)
            - powf(vector_dot(&ray->dir, &cyl->dir), 2);
    abc.y = 2 * (vector_dot(&ray->dir, dist)
                 - (vector_dot(&ray->dir, &cyl->dir) * vector_dot(dist, &cyl->dir)));
    abc.z = (vector_dot(dist, dist) - powf(vector_dot(dist, &cyl->pos), 2)
                     - powf(cyl->radius, 2));
    return (abc);
}

int     intersect_cylinder(t_ray *ray, t_cylinder *cyl)///, float d)
{
    t_vector    dist;
    t_vector    abc;

    t_vector    t;
    float      discr;
    int         ret;

    ret = 0;
    dist = vector_sub(&ray->dir, &ray->start);
    cyl->pos = vector_normalize(&cyl->pos);
    abc = cyl_abc(ray, cyl, &dist);
    discr = abc.y * abc.y - 4 * abc.x * abc.z;
    if (discr < 0)
        return (ret);

    t.x = (abc.y - sqrtf(discr)) / (2 * abc.x);
    t.y = (abc.y + sqrtf(discr)) / (2 * abc.x);

    (t.x > 0.001) && (t.x < ray ->dist) ? ret = 1 : 0;
    (t.x > 0.001) && (t.x < ray ->dist) ? ray ->dist = t.x : 0;
    (t.y > 0.001) && (t.y < ray ->dist) ? ret = 1 : 0;
    (t.y > 0.001) && (t.y < ray ->dist) ? ray ->dist = t.y : 0;
    ray ->dist -= 0.01;
//    if (ray ->dist > d)
//        return (0);
    return (ret);


//    if (t.x < 0)
//        t.x = 100000000;
//    if (t.y < 0)
//        t.y = 100000000;
//    if (t.x > t.y)
//        t.x = t.y;
//
//    if (t.x > 0.0001 && t.x < ray->dist)
//    {
//        ray->dist = t.x;
//        return (1);
//    }
//    return (0);
} */





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


























/*t_vector        cyl_abc(t_ray *ray, t_cylinder *cyl, t_vector *dist)
{
    t_vector    abc;

    abc.x = vector_dot(&ray->dir, &ray->dir)
            - pow(vector_dot(&ray->dir, &cyl->pos), 2);
    abc.y = 2 * (vector_dot(&ray->dir, dist)
                 - (vector_dot(&ray->dir, &cyl->pos) * vector_dot(dist, &cyl->pos)));
    abc.z = vector_dot(dist, dist) - pow(vector_dot(dist, &cyl->pos), 2)
            - pow(cyl->radius, 2);
    return (abc);
}

void	find_abc_for_cylynder(t_ray *r, t_cylinder *cyl, t_mod *mod)
{
	double		dot;
	t_vector	mult;
	t_vector	sub1;
	t_vector	sub2;
	t_vector	delta_p;

	dot = vector_dot(&r->dir, &cyl->r.dir);
	mult = vector_scale(dot, &cyl->r.dir);
	sub1 = vector_sub(&r->dir, &mult);
	delta_p = vector_sub(&r->start, &cyl->r.start);
	dot = vector_dot(&delta_p, &cyl->r.dir);
	mult = vector_scale(dot, &cyl->r.dir);
	sub2 = vector_sub(&delta_p, &mult);
	mod->a = vector_dot(&sub1, &sub1);
	mod->b = 2 * vector_dot(&sub1, &sub2);
	mod->c = vector_dot(&sub2, &sub2) - cyl->sq_radius;
}


** Check if the ray and cylinder intersect
*/
/*
int		intersect_cylinder(t_ray *r, t_cylinder *cyl, t_mod *mod)
{
	double	discr;
	double	sqrtdiscr;
	double	t;

	find_abc_for_cylynder(r, cyl, mod);
	discr = mod->b * mod->b - 4 * mod->a * mod->c;
	if (discr < 0)
		return (0);
	sqrtdiscr = sqrt(discr);
	mod->t0 = (-mod->b + sqrtdiscr) / (2 * mod->a);
	mod->t1 = (-mod->b - sqrtdiscr) / (2 * mod->a);
	t = min_distance(mod);
	if (t < mod->t && t > 0.00001)
	{
		mod->t = t;
		if (mod->light == 0)
			mod->cur_color = cyl->diffuse;
		mod->intersection++;
		mod->shadow = 1;
		return (1);
	}
	return (0);
}

*/
/*
typedef struct    s_cylinder
{
    t_vect        pos;
    t_vect        dir;
    double        r;
}                t_cylinder;


int        intersection_cylinder(t_ray *r, void *c, double *t) /// kzahreba
{
    t_cylinder    *cyl;
    t_vector        tmp[2];
    t_vector        delta;
    t_equation    n;
    int res;

    cyl = (t_cylinder *)c;
    tmp[0] = vector_mult(vector_dot_product(&r->dir, &cyl->dir), &cyl->dir);
    tmp[0] = vector_substract(&r->dir, &tmp[0]);
    n.a = vector_dot_product(&tmp[0], &tmp[0]);
    delta = vector_substract(&r->origin, &cyl->pos);
    tmp[1] = vector_mult(vector_dot_product(&delta, &cyl->dir), &cyl->dir);
    tmp[1] = vector_substract(&delta, &tmp[1]);
    n.b = 2 * vector_dot_product(&tmp[0], &tmp[1]);
    n.c = vector_dot_product(&tmp[1], &tmp[1]) - pow(cyl->r, 2);
    if ((res = quadratic_equation(&n)))
        return(check_solving(t, select_value(n.root, res)));
    return (0);
}



int        quadratic_equation(t_equation *n) //// kzahreba
{
    n->root[0] = -1;
    n->root[1] = -1;
    n->discr = n->b * n->b - 4.0 * n->a * n->c;
    if (n->discr < 0)
        return (0);
    n->sqdiscr = sqrt(n->discr);
    if (n->discr >= 0)
    {
        n->root[0] = (-n->b + n->sqdiscr) / (2.0 * n->a);
        n->root[1] = (-n->b - n->sqdiscr) / (2.0 * n->a);
        return (2);
    }
    return (0);
}*/