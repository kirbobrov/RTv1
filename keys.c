/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbobrov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/15 20:42:24 by kbobrov           #+#    #+#             */
/*   Updated: 2017/10/15 20:42:26 by kbobrov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv.h"

int		ft_mouse_exit(void)
{
    exit(55);
}

int     ft_keys(int id, t_rt *r)
{
    (id == 53) ? exit(53) : 0;

    (id == 78) ? r->ray.start.z -= 50 : 0;
    (id == 69) ? r->ray.start.z += 50 : 0;
    (id == 124) ? r->cam.horizontal += 0.1 : 0;
    (id == 123) ? r->cam.horizontal -= 0.1 : 0;
    (id == 126) ? r->cam.vertical += 0.1 : 0;
    (id == 125) ? r->cam.vertical -= 0.1 : 0;

    tracer(r);
    printf("key id == %d\n", id);
    return (0);
}


// void	begin_point(t_rt *rt)
// {
// 	rt->ray->dir.x = rt->dir0.x;
// 	rt->ray->dir.y = rt->dir0.y;
// 	rt->ray->dir.z = rt->dir0.z;
// }

// int		ft_rotate(int keycode, t_fdf *s)
// {
// 	(keycode == 0) ? rt->za0 += 2 : 0;
// 	(keycode == 6) ? rt->za0 -= 2 : 0;
// 	(keycode == 1) ? rt->xa0 += 2 : 0;
// 	(keycode == 7) ? rt->xa0 -= 2 : 0;
// 	(keycode == 2) ? rt->ya0 += 2 : 0;
// 	(keycode == 8) ? rt->ya0 -= 2 : 0;
// 	if (keycode == 4)
// 	{
// 		rt->xa0 = 0;
// 		rt->ya0 = 0;
// 		rt->za0 = 0;
// 	}
// 	ft_isometric(s);
// 	mlx_destroy(s);
// 	return (0);
// }
