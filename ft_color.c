//
// Created by Kyrylo Bobrov on 8/18/17.
//

#include "rtv.h"

void    figure_color(t_rt *rt, t_material *mat)
{
    rt->col.red = rt->light.intensity.red * mat->diffuse.red * 255;
    rt->col.green = rt->light.intensity.green * mat->diffuse.green * 255;
    rt->col.blue = rt->light.intensity.blue * mat->diffuse.blue * 255;
}

unsigned long createRGB(int r, int g, int b)
{
    return ((r & 0xff) << 16) + ((g & 0xff) << 8) + (b & 0xff);
}

