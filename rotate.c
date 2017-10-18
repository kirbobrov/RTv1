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

/*
   else if (keycode == 123 && (tmp_pos = mlx->cam_pos.x) < 20000)
     {
         POSX = mlx->cam_pos.x * cosf(0.05) + mlx->cam_pos.z * sinf(0.05);
        POSZ = tmp_pos * (-sinf(0.05)) + mlx->cam_pos.z * cosf(0.05);
     }
     else if (keycode == 124 && (tmp_pos = mlx->cam_pos.x) > -20000)
     {
         POSX = mlx->cam_pos.x * cosf(-0.05) + mlx->cam_pos.z * sinf(-0.05);
         POSZ = tmp_pos * (-sinf(-0.05)) + mlx->cam_pos.z * cosf(-0.05);
     }
     else if (keycode == 125 && (tmp_pos = mlx->cam_pos.y) > -20000)
     {
         POSY = mlx->cam_pos.y * cosf(-0.05) + mlx->cam_pos.z * (-sinf(-0.05));
         POSZ = tmp_pos * sinf(-0.05) + mlx->cam_pos.z * cosf(-0.05);
     }
     else if (keycode == 126 && (tmp_pos = mlx->cam_pos.y) < 20000)
     {
         POSY = mlx->cam_pos.y * cosf(0.05) + mlx->cam_pos.z * (-sinf(0.05));
         POSZ = tmp_pos * sinf(0.05) + mlx->cam_pos.z * cosf(0.05);
     }

*/
///POS и mlx->cam_pos


///это точка позиция камеры


//#include <math.h>
//#include "rtv.h"
//
//void		rotate_z(double *x, double *y, double *z, double angle)
//{
//    double	x_tmp;
//    double	y_tmp;
//
//    (void)*z;
//    angle = angle * M_PI / 180;
//    x_tmp = *x;
//    y_tmp = *y;
//    *x = x_tmp * cos(angle) - y_tmp * sin(angle);
//    *y = x_tmp * sin(angle) + y_tmp * cos(angle);
//}
//
//void		rotate_x(double *x, double *y, double *z, double angle)
//{
//    double	y_tmp;
//    double	z_tmp;
//
//    (void)*x;
//    angle = angle * M_PI / 180;
//    y_tmp = *y;
//    z_tmp = *z;
//    *y = y_tmp * cos(angle) - z_tmp * sin(angle);
//    *z = y_tmp * sin(angle) + z_tmp * cos(angle);
//}
//
//void		rotate_y(double *x, double *y, double *z, double angle)
//{
//    double	x_tmp;
//    double	z_tmp;
//
//    (void)*y;
//    angle = angle * M_PI / 180;
//    x_tmp = *x;
//    z_tmp = *z;
//    *z = z_tmp * cos(angle) - x_tmp * sin(angle);
//    *x = z_tmp * sin(angle) + x_tmp * cos(angle);
//}

