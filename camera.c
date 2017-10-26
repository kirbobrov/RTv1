/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbobrov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/15 20:43:41 by kbobrov           #+#    #+#             */
/*   Updated: 2017/10/15 20:43:43 by kbobrov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv.h"

void	cam_init(t_camera *cam)
{
	cam->invwidth = (double)1 / (double)SIZE_X;
	cam->invheight = (double)1 / (double)SIZE_Y;
	cam->aspectratio = (double)SIZE_X / (double)SIZE_Y;
	cam->angle = tan(M_PI * 0.5 * 30 / 180.);
	cam->a0 = 10 * M_PI / 180;
	cam->horizontal = 0;
	cam->vertical = 0;
}

void	camera(t_rt *rt, int x, int y)
{
	rt->ray.dir.x = (((2 * ((x + 0.5) * rt->cam.invwidth) - 1) *
		rt->cam.angle * rt->cam.aspectratio) + rt->cam.horizontal);
	rt->ray.dir.y = (((1 - 2 * ((y + 0.5) * rt->cam.invheight)) *
		rt->cam.angle) + rt->cam.vertical);
	rt->ray.dir.z = 1;
	rt->ray.dir = vector_normalize(&rt->ray.dir);
	rt->ray.dist = 2000001;
}
