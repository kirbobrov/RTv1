
#include "rtv.h"

int		ft_mouse_exit(void)
{
	exit(55);
}

void    ft_in(t_rt *rt)
{
    rt->mat.diffuse.red = 1;
    rt->mat.diffuse.green = 0;
    rt->mat.diffuse.blue = 0;
    rt->mat.reflection = 0.2;


    rt->sph.pos.x = 400;
	rt->sph.pos.y = 300;
	rt->sph.pos.z = 200;

    rt->sph.radius = 200;

	rt->ray.dir.x = 0;
	rt->ray.dir.y = 0;
	rt->ray.dir.z = 1;


    rt->light.pos.x = 0;
    rt->light.pos.y = 0;
    rt->light.pos.z = 0;

    rt->light.intensity.red = 1;
    rt->light.intensity.green = 1;
    rt->light.intensity.blue = -1;



}

int		main(void)
{
	t_rt	r;
	ft_mlxinit(&r.mx);
	ft_imageinit(&r.mx);
    ft_in(&r);

    ft_sphere(&r);

	///mlx_hook(r.mx.win, 2, 5, my_key, &r);
    ft_put_image(r.mx.mlx);
//    mlx_loop_hook(r.mx.mlx, ft_sphere2, &r);
    mlx_hook(r.mx.win, 17, 0L, ft_mouse_exit, &r);
    mlx_loop(r.mx.mlx);
	return (0);
}