/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbobrov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/15 20:42:58 by kbobrov           #+#    #+#             */
/*   Updated: 2017/10/15 20:43:00 by kbobrov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//
// Created by Kyrylo Bobrov on 10/1/17.
//

#include "rtv.h"

void    ft_rotate (t_rt *rt)
{
    ///// прикрутить матрицы сдвига из ФДФ
}


/*
#include <math.h>
#include "rtv.h"

void		rotate_z(double *x, double *y, double *z, double angle)
{
    double	x_tmp;
    double	y_tmp;

    (void)*z;
    angle = DEG_TO_RAD(angle);
    x_tmp = *x;
    y_tmp = *y;
    *x = x_tmp * cos(angle) - y_tmp * sin(angle);
    *y = x_tmp * sin(angle) + y_tmp * cos(angle);
}

void		rotate_x(double *x, double *y, double *z, double angle)
{
    double	y_tmp;
    double	z_tmp;

    (void)*x;
    angle = DEG_TO_RAD(angle);
    y_tmp = *y;
    z_tmp = *z;
    *y = y_tmp * cos(angle) - z_tmp * sin(angle);
    *z = y_tmp * sin(angle) + z_tmp * cos(angle);
}

void		rotate_y(double *x, double *y, double *z, double angle)
{
    double	x_tmp;
    double	z_tmp;

    (void)*y;
    angle = DEG_TO_RAD(angle);
    x_tmp = *x;
    z_tmp = *z;
    *z = z_tmp * cos(angle) - x_tmp * sin(angle);
    *x = z_tmp * sin(angle) + x_tmp * cos(angle);
}


*/
