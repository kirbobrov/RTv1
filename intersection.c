/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersection.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbobrov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/15 20:42:13 by kbobrov           #+#    #+#             */
/*   Updated: 2017/10/15 20:42:16 by kbobrov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv.h"

void	int_cone(t_rt *rt, int i)
{
	if (intersection_cone(&rt->ray, (t_cone *)rt->obj[i].obj, rt))
	{
		if (rt->sid == 0)
		{
			rt->ray.normal = normale_cone(&rt->ray, (t_cone *)rt->obj[i].obj);
			figure_color(rt, &rt->mat[rt->con->material]);
		}
		(rt->sid == 1) ? shadow(rt) : 0;
	}
}

void	int_sphere(t_rt *rt, int i)
{
	if (intersection_sphere(&rt->ray, (t_sphere *)rt->obj[i].obj))
	{
		if (rt->sid == 0)
		{
			rt->ray.normal = normale_sphere(rt, (t_sphere *)rt->obj[i].obj);
			figure_color(rt, &rt->mat[i]);
		}
		(rt->sid == 1) ? shadow(rt) : 0;
	}
}

void	int_cylinder(t_rt *rt, int i)
{
	if (intersection_cylinder(&rt->ray, (t_cylinder *)rt->obj[i].obj, rt))
	{
		if (rt->sid == 0)
		{
			rt->ray.normal =
			normale_cylinder(&rt->ray, (t_cylinder *)rt->obj[i].obj);
			figure_color(rt, &rt->mat[rt->cyl->material]);
		}
		(rt->sid == 1) ? shadow(rt) : 0;
	}
}

void	int_plane(t_rt *rt, int i)
{
	if (intersection_plane(&rt->ray, (t_plane *)rt->obj[i].obj, rt))
	{
		if (rt->sid == 0)
		{
			rt->ray.normal =
			plane_normale((t_plane *)rt->obj[i].obj, &rt->ray);
			rt->ray.normal = vector_normalize(&rt->ray.normal);
			figure_color(rt, &rt->mat[rt->pl->material]);
		}
		(rt->sid == 1) ? shadow(rt) : 0;
	}
}

int		intersection(t_rt *rt)
{
	int		i;
	double	temp;

	temp = 0;
	i = -1;
	while (++i < 6)
	{
		if (rt->obj[i].id == CONUS)
			int_cone(rt, i);
		else if (rt->obj[i].id == SPHERE)
			int_sphere(rt, i);
		else if (rt->obj[i].id == CYLINDER)
			int_cylinder(rt, i);
		else if (rt->obj[i].id == PLANE)
			int_plane(rt, i);
		temp = vector_dot(&rt->ray.normal, &rt->ray.normal);
		if (temp < 0)
			return (0);
	}
	if (rt->ray.dist != 2000001)
		return (1);
	return (0);
}
