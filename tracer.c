/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tracer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbobrov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/15 20:43:17 by kbobrov           #+#    #+#             */
/*   Updated: 2017/10/26 18:47:06 by kbobrov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv.h"

void		camera_init(t_rt *rt, int x, int y)
{
	rt->sid = 0;
	rt->ray.start.x = rt->ray.start0.x;
	rt->ray.start.y = rt->ray.start0.y;
	rt->ray.start.z = rt->ray.start0.z;
	rt->ray.dir.x = rt->ray.dir0.x;
	rt->ray.dir.y = rt->ray.dir0.y;
	rt->ray.dir.z = rt->ray.dir0.z;
	camera(rt, x, y);
	ft_rotate(rt);
	rt->col0.red = 0;
	rt->col0.green = 0;
	rt->col0.blue = 0;
	rt->col.red = 0;
	rt->col.green = 0;
	rt->col.blue = 0;
}

void		calc_trace(t_rt *rt, t_ray *lightray)
{
	t_vector	dist;

	dist = vector_sub(&rt->current_light.pos, &rt->ray.hit_point);
	rt->ray.dist = vector_len(&dist);
	lightray->dir = vector_scale((1 / rt->ray.dist), &dist);
	lambert(rt, lightray);
	rt->shadow = vector_sub(&rt->current_light.pos, &rt->ray.hit_point);
	rt->ray.dist = vector_len(&rt->shadow);
	rt->shadow = vector_normalize(&rt->shadow);
	rt->ray.dir = rt->shadow;
	rt->ray.start = rt->ray.hit_point;
	rt->sid = 1;
	intersection(rt);
}

void		tracer(t_rt *rt)
{
	int			y;
	int			x;
	t_ray		lightray;

	ft_imageinit(&rt->mx);
	y = -1;
	while (++y < SIZE_Y)
	{
		x = -1;
		while (++x < SIZE_X)
		{
			camera_init(rt, x, y);
			if (intersection(rt))
			{
				rt->i = -1;
				while (++rt->i < 1)
				{
					rt->current_light = rt->light[rt->i];
					calc_trace(rt, &lightray);
				}
			}
			ft_img_color(rt, x, y);
		}
	}
	ft_put_image((t_mlx *)&rt->mx.mlx);
}
