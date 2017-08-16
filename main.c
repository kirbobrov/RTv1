/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbobrov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/12 18:11:48 by kbobrov           #+#    #+#             */
/*   Updated: 2017/08/12 18:11:51 by kbobrov          ###   ########.fr       */
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
    return (0);
}

void    ft_initialize(t_rt *rt)
{
    rt->mat.diffuse.red = 1;
    rt->mat.diffuse.green = 0.3;
    rt->mat.diffuse.blue = 0;
//    rt->mat.diffuse.a = 1;
    rt->mat.reflection = 0.2;

    rt->sph.pos.x = 0;
	rt->sph.pos.y = 0;
	rt->sph.pos.z = 0;
    rt->sph.radius = 200;

	rt->ray.dir.x = 0;
	rt->ray.dir.y = 0;
	rt->ray.dir.z = 1;

    rt->light.pos.x = -800;
    rt->light.pos.y = -300;
    rt->light.pos.z = -2000;

    rt->light.intensity.red = 1;
    rt->light.intensity.green = 1;
    rt->light.intensity.blue = 1;
//    rt->light.intensity.a = 1;

/////////////////////////////////// second sphere0
 /*
   - rt->mat[1].diffuse.red = 1;
    rt->mat[1].diffuse.green = 0.3;
    rt->mat[1].diffuse.blue = 0;
    rt->mat[1].reflection = 0.2;

    rt->sph[1].pos.x = -100;
    rt->sph[1].pos.y = -100;
    rt->sph[1].pos.z = 0;
    rt->sph[1].radius = 120;
*/
}

int		main(void)
{
	t_rt	r;
	ft_mlxinit(&r.mx);
	ft_imageinit(&r.mx);
    ft_initialize(&r);

    ft_sphere(&r);

	///mlx_hook(r.mx.win, 2, 5, my_key, &r);
	ft_put_image(r.mx.mlx);
//    mlx_loop_hook(r.mx.mlx, ft_sphere, &r);
    mlx_hook(r.mx.win, 17, 0L, ft_mouse_exit, &r);
    mlx_hook(r.mx.win, 2, 5, ft_keys, &r);
    mlx_loop(r.mx.mlx);
	return (0);
}
