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

int			intersection_cone(t_ray *r, t_cone *c, t_rt *rt)
{
	t_vector	abc;
	double		dot[4];
	t_vector	mult[2];
	t_vector	sub[2];
	t_vector	dp;

	dot[2] = cos(c->a) * cos(c->a);
	dot[3] = sin(c->a) * sin(c->a);
	dp = vector_sub(&r->start, &c->pos);
	dot[0] = vector_dot(&r->dir, &c->dir);
	mult[0] = vector_scale(dot[0], &c->dir);
	sub[0] = vector_sub(&r->dir, &mult[0]);
	dot[1] = vector_dot(&dp, &c->dir);
	mult[1] = vector_scale(dot[1], &c->dir);
	sub[1] = vector_sub(&dp, &mult[1]);
	abc.x = dot[2] * vector_dot(&sub[0], &sub[0]);
	abc.x -= dot[3] * dot[0] * dot[0];
	abc.y = 2 * dot[2] * vector_dot(&sub[0], &sub[1]);
	abc.y -= 2 * dot[3] * dot[0] * dot[1];
	abc.z = dot[2] * vector_dot(&sub[1], &sub[1]);
	abc.z -= dot[3] * dot[1] * dot[1];
	if (discr(&abc, r))
		return (1);
	return (0);
}

t_vector	normale_cone(t_ray *ray, t_cone *cn)
{
	t_vector	b;
	t_vector	n;

	ray->hit_point = vector_scale(ray->dist, &ray->dir);
	ray->hit_point = vector_add(&ray->hit_point, &ray->start);
	b = vector_sub(&ray->hit_point, &cn->pos);
	n = vector_scale(vector_coss(&b, &cn->dir), &cn->dir);
	n = vector_sub(&b, &n);
	n = cross_product(&b, &n);
	n = cross_product(&n, &b);
	return (vector_normalize(&n));
}
