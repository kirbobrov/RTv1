/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_color.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbobrov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/15 20:41:21 by kbobrov           #+#    #+#             */
/*   Updated: 2017/10/15 20:41:25 by kbobrov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "rtv.h"

void    figure_color(t_rt *rt, t_material *mat)
{
    rt->col.red = rt->light[0].intensity.red * mat->diffuse.red * 255;
    rt->col.green = rt->light[0].intensity.green * mat->diffuse.green * 255;
    rt->col.blue = rt->light[0].intensity.blue * mat->diffuse.blue * 255;
}

unsigned long createRGB(int r, int g, int b)
{
    return ((r & 0xff) << 16) + ((g & 0xff) << 8) + (b & 0xff);
}

