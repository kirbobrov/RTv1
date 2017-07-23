
#ifndef RTV_H
# define RTV_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <time.h>
# include <math.h>
# include "mlx.h"
# include <stdbool.h>
# include "libft/libft.h"
# define SIZE_Y 780
# define SIZE_X 1024

typedef struct	s_vector
{
	float		x;
	float		y;
	float		z;
}				t_vector;

typedef struct	s_sphere
{
	t_vector	pos;
	float		radius;
    int         material;
}				t_sphere;

typedef struct	s_ray
{
	t_vector	start;
	t_vector	dir;
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
	t_mlx		mx;
	t_vector	vec;
	t_sphere	sph;
	t_ray		ray;
    t_color     col;
    int         x;
    int         y;
    t_light     light;
    t_material  mat;
    ///double      color;
}				t_rt;

void	ft_imageinit(t_mlx *mx);
void	ft_mlxinit(t_mlx *mx);
void	ft_put_image(t_mlx *mx);
int		ft_sphere(t_rt *rt);
void	ft_img_color(t_rt *rt);

#endif