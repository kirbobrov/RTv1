
#include "rtv.h"

void	ft_matrx(t_rt *rt)
{
	double y;
	double z;
	double a;

	y = rt->ray.dir.y;
	z = rt->ray.dir.z;
	a = rt->ray.ax;
	RAD(a);
	rt->ray.dir.y = ((y * cos(a)) + (z * (-sin(a))));
	rt->ray.dir.z = ((y * sin(a)) + (z * cos(a)));
}

void	ft_matry(t_rt *rt)
{
	double x;
	double z;
	double a;

	x = rt->ray.dir.x;
	z = rt->ray.dir.z;
	a = rt->ray.ay;
	RAD(a);
	rt->ray.dir.x = ((x * cos(a)) + (z * sin(a)));
	rt->ray.dir.z = ((x * (-sin(a))) + (z * cos(a)));
}

void	ft_matrz(t_rt *rt)
{
	double x;
	double y;
	double a;

	a = rt->ray.az;
	x = rt->ray.dir.x;
	y = rt->ray.dir.y;
	RAD(a);
	rt->ray.dir.x = ((x * cos(a)) + (y * (-sin(a))));
	rt->ray.dir.y = ((x * sin(a)) + (y * (cos(a))));
}

void	ft_rotate(t_rt *rt)
{
			ft_matrz(rt);
			ft_matrx(rt);
			ft_matry(rt);
}

//void	ft_begin_point(t_fdf *s)
//{
//	int y;
//	int x;
//
//	y = 0;
//	while (y < s->ymax)
//	{
//		x = 0;
//		while (x < s->xmax)
//		{
//			s->pt[y][x].x = s->pt[y][x].x0;
//			s->pt[y][x].y = s->pt[y][x].y0;
//			s->pt[y][x].z = s->pt[y][x].z0;
//			x++;
//		}
//		y++;
//	}
//}

//void	ft_isometric(t_fdf *s)
//{
//	int	x;
//	int	y;
//
//	y = 0;
//	s->xa = s->xa0;
//	s->ya = s->ya0;
//	s->za = s->za0;
//	ft_begin_point(s);
//	while (y < s->ymax)
//	{
//		x = 0;
//		while (x < s->xmax)
//		{
//			ft_matrz(s, &s->pt[y][x]);
//			ft_matrx(s, &s->pt[y][x]);
//			ft_matry(s, &s->pt[y][x]);
//			x++;
//		}
//		y++;
//	}
//}




