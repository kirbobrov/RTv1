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


int find_abc_cylinder(t_ray *r, t_cylinder *c, t_rt *rt)
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

    dot = vector_dot(&r->dir, &c->pos);
    mult = vector_scale(dot, &c->pos);
    v1 = vector_sub(&r->dir, &mult); //// (V - (V, Va)Va)
    A = vector_dot(&v1, &v1);

    delta_p = vector_sub(&r->start, &c->pos);
    dot2 = vector_dot(&delta_p, &c->pos);
    mult = vector_scale(dot2, &c->pos);
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

int                intersect_cylinder(t_ray *ray, t_cylinder *cyl, double d)
{
    t_vector    dist;
    t_vector    abc;

    t_vector    t;
    double        discr;
    int            ret;

    ret = 0;
    dist = vector_sub(&cyl->pos, &ray->start);
    cyl->pos = vector_normalize(&(cyl->pos);
    abc = cyl_abc(ray, (cyl, &dist);
    discr = abc.y * abc.y - 4 * abc.x * abc.z;
    if (discr < 0)
        return (ret);
    t.x = (abc.y - sqrt(discr)) / (2 * abc.x);
    t.y = (abc.y + sqrt(discr)) / (2 * abc.x);
    (t.x > 0.001) && (t.x < ray ->dist) ? ret = 1 : 0;
    (t.x > 0.001) && (t.x < ray ->dist) ? ray ->dist = t.x : 0;
    (t.y > 0.001) && (t.y < ray ->dist) ? ret = 1 : 0;
    (t.y > 0.001) && (t.y < ray ->dist) ? ray ->dist = t.y : 0;
    ray ->dist -= 0.01;
    if (ray ->dist > d)
        return (0);
    return (ret);
}*/

////write all formuls for find intersection of cylinder but not to be tested.


//
//void	find_abc_for_cylynder(t_ray *r, t_cylinder *cyl, t_mod *mod)
//{
//    double		dot;
//    t_vector	mult;
//    t_vector	sub1;
//    t_vector	sub2;
//    t_vector	delta_p;
//
//    dot = vector_dot(&r->dir, &cyl->r.dir);
//    mult = vector_scale(dot, &cyl->r.dir);
//    sub1 = vector_sub(&r->dir, &mult);
//    delta_p = vector_sub(&r->start, &cyl->r.start);
//    dot = vector_dot(&delta_p, &cyl->r.dir);
//    mult = vector_scale(dot, &cyl->r.dir);
//    sub2 = vector_sub(&delta_p, &mult);
//    mod->a = vector_dot(&sub1, &sub1);
//    mod->b = 2 * vector_dot(&sub1, &sub2);
//    mod->c = vector_dot(&sub2, &sub2) - cyl->sq_radius;
//}

 /*
void	find_normal_cylinder(t_mod *mod, t_cylinder *cyl)
{
	t_vector scaled;
	t_vector b;
	t_vector a;
	t_vector rv;

	scaled = vector_scale(mod->t, &mod->r.dir);
	mod->new_start = vector_add(&mod->r.start, &scaled);
	b = vector_sub(&mod->new_start, &cyl->r.start);
	a = vector_scale(vector_dot(&b, &cyl->r.dir), &cyl->r.dir);
	rv = vector_sub(&b, &a);
	mod->n = vector_normalize(&rv);
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