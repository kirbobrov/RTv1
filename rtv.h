/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbobrov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/12 18:13:05 by kbobrov           #+#    #+#             */
/*   Updated: 2017/08/12 18:13:08 by kbobrov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RTV_H
# define RTV_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <time.h>
# include <math.h>
# include "minilibx/mlx.h"
# include <stdbool.h>
# include "libft/libft.h"
# define RAD(a) (a = a * (M_PI / 180))
# define SIZE_Y 800
# define SIZE_X 1000
# define SPHERE 0
# define CYLINDER 1
# define CONUS 2
# define PLANE 3

////# define M_PI 3.14159265358979323846264338327950288


//typedef struct  s_equetion
//{
//    double       tmp[2];
//    double         root[2];
//    double       sqdiscr;
//    double       discr;
//    double   a;
//    double   b;
//    double   c;
//}               t_equation;

typedef struct      s_camera
{
    double      invwidth;
    double      invheight;
    double      aspectratio;
    double      angle;
    double      vertical;
    double      horizontal;
    double      a0;
}                   t_camera;

typedef struct      s_vector
{
	double      x;
	double      y;
	double      z;
}                   t_vector;

typedef struct      s_color ////color definithion
{
    double      red;
    double      green;
    double      blue;
    double      a;
}                   t_color;

typedef struct      s_sphere
{
	t_vector    pos;    ///centre
	double      radius;
    int         material;
    int         id;
    t_vector    hit_point;

}                   t_sphere;

typedef struct      s_cylinder
{
    t_vector    pos;    ///centre
    t_vector    dir;
    t_vector    hit_point;
    double      radius;
    int         material;
    int         id;
}                   t_cylinder;

typedef struct      s_plane
{
    t_vector    dir;
    t_vector    pos;
    int         id;
    int         material;
}                   t_plane;

typedef struct      s_cone
{
    t_vector    pos;
    t_vector    dir;
    double      a;
    t_vector    hit_point;
    int         material;
    int         id;
}                   t_cone;

typedef struct      s_ray
{
	t_vector    start;  //// start vector
	t_vector    dir;    /// direction vector
    t_vector    normdir; /// normalize direction vector
    t_vector    hit_point;
    t_vector    normal;
    double      dist;      ///distantion

    double      ax;
    double      ay;
    double      az;
}                   t_ray;

typedef struct      s_light /// light defenition
{
    t_vector    pos;
    t_color     intensity;
}                   t_light;

typedef struct      s_material  //// Material definition
{
    t_color     diffuse;
    double      reflection;
}                   t_material;

typedef struct      s_mlx
{
	void        *mlx;
	void        *win;
	void        *img;
	char        *buf;
	int         bpp;
	int         endl;
	int         sizel;
}                   t_mlx;

typedef struct      s_object
{
    int         id;
    void        *obj;
}                   t_object;

typedef struct      s_rt
{
	t_mlx       mx;     ///mlx
	t_vector    vec;    ///vector
    t_sphere    *sph0;
    t_sphere    *sph1;
    t_sphere    *sph2;
    t_cylinder  *cyl;
    t_plane     *pl;
    t_plane     *pl1;
    t_cone      *con;
    t_ray       ray;

    t_camera    cam;

    t_color     col;    ///color
    t_light     light[2];
    t_material  mat[6];
    t_object    obj[6];

///    int     id;
}				t_rt;

void        ft_imageinit(t_mlx *mx);
void        ft_mlxinit(t_mlx *mx);
void        ft_put_image(t_mlx *mx);
void         tracer(t_rt *rt);
void        ft_img_color(t_rt *rt, int x, int y);
int         ft_keys(int id, t_rt *r);
int		   ft_mouse_exit(void);

t_vector        vector_sub(t_vector *v1, t_vector *v2);
t_vector        vector_add(t_vector *v1, t_vector *v2);
double           vector_dot(t_vector *v1, t_vector *v2);
t_vector        vector_scale(double t, t_vector *v);
double           vector_len(t_vector *v);
t_vector        vector_normalize(t_vector *v);
double           vector_coss(t_vector *v1, t_vector *v2);
t_vector        vector_mult(t_vector *v1, t_vector *v2);



double           vector_cos(t_vector *v1, t_vector *v2);
t_vector    cross_product(t_vector *v1, t_vector *v2);




int            intersection(t_rt *rt);
int             intersection_sphere(t_ray *r, t_sphere *s);
void            normale_sphere(t_rt *rt, t_sphere *sph);
int             intersection_cylinder(t_ray *r, t_cylinder *c, t_rt *rt);
t_vector        normale_cylinder(t_ray *ray, t_cylinder *cyl);
int             intersection_plane(t_ray *ray, t_plane *pl, t_rt *rt);
void            figure_color(t_rt *rt, t_material *mat);

int             intersection_cone(t_ray *r, t_cone *cn, t_rt *rt);
t_vector        normale_cone(t_ray *ray, t_cone *cn);



void    cam_init(t_camera *cam);
void    camera(t_rt *rt, int x, int y);

int   discr(t_vector *abc, t_ray *r);


void	ft_rotate(t_rt *rt);
void	ft_matrx(t_rt *rt);
void	ft_matry(t_rt *rt);
void	ft_matrz(t_rt *rt);

#endif
