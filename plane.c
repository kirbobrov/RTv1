//
// Created by Kyrylo Bobrov on 9/28/17.
//

#include "rtv.h"


int intersection_plane(t_ray *ray, t_plane *pl, t_rt *rt)
{

    float        dotn;
    t_vector        temp;
    float        t;

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


/*
double  ft_inter_plane(t_th *mlx, t_obj *tmp, t_vec ray, t_vec pos)
{
	mlx->t0 = ((ft_vectordot(&tmp->rot, &tmp->pos) -
				ft_vectordot(&tmp->rot, &pos)) / ft_vectordot(&tmp->rot, &ray));
	if (mlx->t0 < 0.0001)
		return (-1);
	return (mlx->t0);
}

*/