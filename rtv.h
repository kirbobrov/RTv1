
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
# define SIZE_Y 600
# define SIZE_X 800
# define M_PI 3.14159265358979323846264338327950288

typedef struct	s_vector
{
	float		x;
	float		y;
	float		z;
}				t_vector;

typedef struct	s_sphere
{
	t_vector	pos;    ///centre
	float		radius;
    int         material;
}				t_sphere;

typedef struct	s_ray
{
	t_vector	start;  //// start vector
	t_vector	dir;    /// direction vector
    t_vector    normdir; /// normalize direction vector
    float       dist;      ///distantion
}				t_ray;

typedef struct  s_color ////color definithion
{
    float      red;
    float      green;
    float      blue;
}               t_color;

typedef struct  s_light /// light defenition
{
    t_vector pos;
    t_color intensity;
}               t_light;

typedef struct  s_material  //// Material definition
{
    t_color     diffuse;
    float       reflection;
}               t_material;

typedef struct	s_mlx
{
	void		*mlx;
	void		*win;
	void		*img;
	char		*buf;
	int			bpp;
	int			endl;
	int			sizel;
}				t_mlx;

typedef struct	s_rt
{
	t_mlx		mx;     ///mlx
	t_vector	vec;    ///vector
	t_sphere	sph;    ///sphere
	t_ray		ray;    ///ray
    t_color     col;    ///color
    int         x;      /// current x
    int         y;      /// current y
    t_light     light;  /// light
    t_material  mat;    ///material
    ///double      color;
}				t_rt;

void	ft_imageinit(t_mlx *mx);
void	ft_mlxinit(t_mlx *mx);
void	ft_put_image(t_mlx *mx);
int		ft_sphere(t_rt *rt);
void	ft_img_color(t_rt *rt);

#endif