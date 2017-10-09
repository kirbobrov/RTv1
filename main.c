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

void    init_material(t_rt *rt)
{
    rt->mat[0].diffuse.red = 1;
    rt->mat[0].diffuse.green = 0.3;
    rt->mat[0].diffuse.blue = 0;
//  rt->mat.diffuse.a = 1;
    rt->mat[0].reflection = 0.2;

    rt->mat[2].diffuse.red = 0.3;
    rt->mat[2].diffuse.green = 0.7;
    rt->mat[2].diffuse.blue = 0.2;
//  rt->mat.diffuse.a = 1;
    rt->mat[2].reflection = 0.2;

    rt->mat[1].diffuse.red = 0;
    rt->mat[1].diffuse.green = 0.3;
    rt->mat[1].diffuse.blue = 1;
    rt->mat[1].reflection = 0.2;

    rt->mat[3].diffuse.red = 0.9;
    rt->mat[3].diffuse.green = 0.5;
    rt->mat[3].diffuse.blue = 0.9;

    rt->mat[4].diffuse.red = 0.1;
    rt->mat[4].diffuse.green = 0.2;
    rt->mat[4].diffuse.blue = 0.3;

    rt->mat[5].diffuse.red = 0.5;
    rt->mat[5].diffuse.green = 0.3;
    rt->mat[5].diffuse.blue = 0.1;
}

void    init_figure(t_rt *rt)
{
	rt->ray.dir.x = 0;
	rt->ray.dir.y = 0;
	rt->ray.dir.z = 1;

    rt->light.pos.x = -1800;
    rt->light.pos.y = 300;
    rt->light.pos.z = -2000;

    rt->light.intensity.red = 1;
    rt->light.intensity.green = 1;
    rt->light.intensity.blue = 1;

    rt->sph0 = malloc(sizeof(t_sphere));

    rt->sph0->pos.x = 0;
    rt->sph0->pos.y = 0;
    rt->sph0->pos.z = 20;
    rt->sph0->radius = 12;
    rt->sph0->material = 0;
    rt->obj[0].id = 0;
    rt->obj[0].obj = (void *)rt->sph0;

    rt->sph1 = malloc(sizeof(t_sphere));
    rt->sph1->pos.x = -22;
    rt->sph1->pos.y = 12;
    rt->sph1->pos.z = -20;
    rt->sph1->radius = 12;
    rt->sph1->material = 1;
    rt->obj[1].id = 0;
    rt->obj[1].obj = (void *)rt->sph1;

    rt->sph2 = malloc(sizeof(t_sphere));
    rt->sph2->pos.x = 32;
    rt->sph2->pos.y = -12;
    rt->sph2->pos.z = 70;
    rt->sph2->radius = 12;
    rt->sph2->material = 2;
    rt->obj[2].id = 0;
    rt->obj[2].obj = (void *)rt->sph2;

    rt->cyl = malloc(sizeof(t_cylinder));
    rt->cyl->pos.x = 10;
    rt->cyl->pos.y = 25;
    rt->cyl->pos.z = 80;
    rt->cyl->radius = 6;
    rt->cyl->dir.x = 0.1;
    rt->cyl->dir.y = 0.7;
    rt->cyl->dir.z = 0.2;
    rt->cyl->material = 1;
    rt->cyl->dir = vector_normalize(&rt->cyl->dir);
    rt->obj[3].id = 1;
    rt->obj[3].obj = (void *)rt->cyl;

    rt->pl = malloc(sizeof(t_plane));
    rt->pl->pos.x = 0;
    rt->pl->pos.y = 0;
    rt->pl->pos.z = 200;

    rt->pl->dir.x = 0;
    rt->pl->dir.y = 0;
    rt->pl->dir.z = 1;

    rt->pl->material = 5;
    rt->obj[4].id = 3;
    rt->obj[4].obj = (void *)rt->pl;

    rt->con = malloc(sizeof(t_cone));
    rt->con->pos.x = 0;
    rt->con->pos.y = 0;
    rt->con->pos.z = 0;

    rt->con->dir.x = 0;
    rt->con->dir.y = 1;
    rt->con->dir.z = 0;

    int i = 10;
    rt->con->a = RAD(i);

    rt->obj[5].id = 2;
    rt->obj[5].obj = (void *)rt->pl;

}

int		main(void)
{
	t_rt	r;
	ft_mlxinit(&r.mx);
	ft_imageinit(&r.mx);
    init_material(&r);
    init_figure(&r);

    tracer(&r);

	///mlx_hook(r.mx.win, 2, 5, my_key, &r);
	ft_put_image(r.mx.mlx);
/// mlx_loop_hook(r.mx.mlx, ft_sphere, &r);
    mlx_hook(r.mx.win, 17, 0L, ft_mouse_exit, &r);
    mlx_hook(r.mx.win, 2, 5, ft_keys, &r);
    mlx_loop(r.mx.mlx);
	return (0);
}
