//
// Created by Kyrylo Bobrov on 8/18/17.
//

#include "rtv.h"

void    sphere_color(t_rt *rt, t_material *mat)
{
    rt->col.red = rt->light.intensity.red * mat->diffuse.red * 255;
    rt->col.green = rt->light.intensity.green * mat->diffuse.green * 255;
    rt->col.blue = rt->light.intensity.blue * mat->diffuse.blue * 255;
}
