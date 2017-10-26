/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbobrov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/15 20:42:40 by kbobrov           #+#    #+#             */
/*   Updated: 2017/10/15 20:42:49 by kbobrov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv.h"

int			intersection_plane(t_ray *ray, t_plane *pl, t_rt *rt)
{
	double		dotn;
	t_vector	temp;
	double		t;

	dotn = vector_dot(&pl->dir, &ray->dir);
	if (fabs(dotn) > 0.001)
	{
		temp = vector_sub(&pl->pos, &ray->start);
		t = vector_dot(&temp, &pl->dir) / dotn;
		if (t > 0.001 && t < ray->dist)
		{
			ray->dist = t;
			return (1);
		}
	}
	return (0);
}

t_vector	plane_normale(t_plane *pl, t_ray *ray)
{
	ray->hit_point = vector_scale(ray->dist, &ray->dir);
	ray->hit_point = vector_add(&ray->hit_point, &ray->start);
	return (vector_normalize(&pl->dir));
}
