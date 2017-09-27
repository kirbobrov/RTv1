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

void    init_material(t_rt *rt)
{
    rt->mat[0].diffuse.red = 1;
    rt->mat[0].diffuse.green = 0.3;
    rt->mat[0].diffuse.blue = 0;
//    rt->mat.diffuse.a = 1;
    rt->mat[0].reflection = 0.2;

    rt->mat[2].diffuse.red = 0.3;
    rt->mat[2].diffuse.green = 0.7;
    rt->mat[2].diffuse.blue = 0.2;
//    rt->mat.diffuse.a = 1;
    rt->mat[2].reflection = 0.2;

    rt->mat[1].diffuse.red = 0;
    rt->mat[1].diffuse.green = 0.3;
    rt->mat[1].diffuse.blue = 1;
    rt->mat[1].reflection = 0.2;

    rt->mat[3].diffuse.red = 0.9;
    rt->mat[3].diffuse.green = 0.5;
    rt->mat[3].diffuse.blue = 0.7;
}

void    init_figure(t_rt *rt)
{
	rt->ray.dir.x = 0;
	rt->ray.dir.y = 0;
	rt->ray.dir.z = 1;

    rt->light.pos.x = -1800;
    rt->light.pos.y = -300;
    rt->light.pos.z = -2000;

    rt->light.intensity.red = 1;
    rt->light.intensity.green = 1;
    rt->light.intensity.blue = 1;

    printf("2\n");
    rt->sph0 = malloc(sizeof(t_sphere));
    printf("3\n");
    rt->sph0->pos.x = 0;
    rt->sph0->pos.y = 0;
    rt->sph0->pos.z = 200;
    rt->sph0->radius = 120;
    rt->sph0->material = 0;
    rt->obj[0].id = 0;
    rt->obj[0].obj = (void *)rt->sph0;

    rt->sph1 = malloc(sizeof(t_sphere));
    rt->sph1->pos.x = -180;
    rt->sph1->pos.y = -100;
    rt->sph1->pos.z = -100;
    rt->sph1->radius = 120;
    rt->sph1->material = 1;
    rt->obj[1].id = 0;
    rt->obj[1].obj = (void *)rt->sph1;


    rt->sph2 = malloc(sizeof(t_sphere));
    rt->sph2->pos.x = 300;
    rt->sph2->pos.y = 150;
    rt->sph2->pos.z = 500;
    rt->sph2->radius = 120;
    rt->sph2->material = 2;
    rt->obj[2].id = 0;
    rt->obj[2].obj = (void *)rt->sph2;


    rt->cyl = malloc(sizeof(t_cylinder));
    rt->cyl->pos.x = 100;
    rt->cyl->pos.y = 250;
    rt->cyl->pos.z = 800;
    rt->cyl->radius = 50;
    rt->cyl->dir.x = 0.1;
    rt->cyl->dir.y = 0.7;
    rt->cyl->dir.z = 0.2;
    rt->cyl->material = 1;
    rt->cyl->dir = vector_normalize(&rt->cyl->dir);
    rt->obj[3].id = 1;
    rt->obj[3].obj = (void *)rt->cyl;
    printf("3\n");

}

int		main(void)
{
	t_rt	r;
	ft_mlxinit(&r.mx);
	ft_imageinit(&r.mx);
    init_material(&r);
    printf("1\n");
    init_figure(&r);
    printf("222\n");
   /// object_init(&r);

    ft_sphere(&r);

	///mlx_hook(r.mx.win, 2, 5, my_key, &r);
	ft_put_image(r.mx.mlx);
//    mlx_loop_hook(r.mx.mlx, ft_sphere, &r);
    mlx_hook(r.mx.win, 17, 0L, ft_mouse_exit, &r);
    mlx_hook(r.mx.win, 2, 5, ft_keys, &r);
    mlx_loop(r.mx.mlx);
	return (0);
}
