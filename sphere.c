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

#include "rtv.h"

t_vector	normale_sphere(t_rt *rt, t_sphere *sph)
{
	t_vector	scaled;
	t_vector	normale;

	scaled = vector_scale(rt->ray.dist, &rt->ray.dir);
	rt->ray.hit_point = vector_add(&rt->ray.start, &scaled);
	normale = vector_sub(&rt->ray.hit_point, &sph->pos);
	return (vector_normalize(&normale));
}

int			intersection_sphere(t_ray *r, t_sphere *s)
{
	t_vector	abc;
	t_vector	dist;

	abc.x = vector_dot(&r->dir, &r->dir);
	dist = vector_sub(&r->start, &s->pos);
	abc.y = 2 * vector_dot(&r->dir, &dist);
	abc.z = vector_dot(&dist, &dist) - (s->radius * s->radius);
	if (discr(&abc, r))
		return (1);
	return (0);
}
