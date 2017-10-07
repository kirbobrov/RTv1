//
// Created by Kyrylo Bobrov on 10/7/17.
//

#include "rtv.h"

void    intersection(t_rt *rt)
{
    int    i;

    i = 0;
    rt->i = 0;
    while (i < 5)
    {
        if (rt->obj[i].id == SPHERE)
        {
            if (intersection_sphere(&rt->ray, (t_sphere *) rt->obj[i].obj, rt)) {
                normale_sphere(rt, (t_sphere *) rt->obj[i].obj);
                figure_color(rt, &rt->mat[i]); /// &rt->mat[i]
                rt->hit = 1;
                rt->hit2 = 1;
            }
        }
        else if (rt->obj[i].id == CYLINDER)
        {
            if (intersection_cylinder(&rt->ray, (t_cylinder *) rt->obj[i].obj, rt)) {
                rt->ray.normal = normale_cylinder(&rt->ray, (t_cylinder *) rt->obj[i].obj);
                figure_color(rt, &rt->mat[5]); /// &rt->mat[i]
                rt->hit = 1;
                rt->hit2 = 1;
            }
        }
        else if (rt->obj[i].id == PLANE)
        {
            if (intersection_plane(&rt->ray, (t_plane *) rt->obj[i].obj, rt))
            {
                figure_color(rt, &rt->mat[4]); /// testing of material
                rt->hit = 1;
                rt->hit2 = 1;
                rt->i = 11;
            }
        }
        i++;
    }
}

