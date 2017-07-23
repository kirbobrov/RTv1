/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbobrov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/20 17:09:09 by kbobrov           #+#    #+#             */
/*   Updated: 2017/06/09 19:26:38 by kbobrov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF_H
# define WOLF_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <time.h>
# include <math.h>
# include "mlx.h"
# include "libft/libft.h"
# define MX 24
# define MY 24
# define SIZE_Y 720
# define SIZE_X 912
# define RDY w->pl.raydiry
# define RDX w->pl.raydirx
# define PERWALL w->pl.perpwalldist
# define RPY w->pl.rayposy
# define RPX w->pl.rayposx

typedef struct	s_color
{
	int			color;
}				t_color;

typedef struct	s_player
{
	int			**map;
	double		posx;
	double		posy;
	double		dirx;
	double		diry;
	double		planex;
	double		planey;
	double		time;
	double		oldtime;
	double		rayposx;
	double		rayposy;
	double		raydirx;
	double		raydiry;
	int			mapx;
	int			mapy;
	double		sidedistx;
	double		sidedisty;
	double		deltadistx;
	double		deltadisty;
	double		perpwalldist;
	int			stepx;
	int			stepy;
	double		movespeed;
	double		olddirx;
	double		oldplanex;
	double		rotspeed;
	double		camerax;
	int			side;
	double		frametime;
	double		drawstart;
	double		drawend;
	double		lineheight;
	double		sm;
	int			dx;
	int			dy;
	int			sx;
	int			sy;
	int			error;
	int			error2;
	int			hit;
	int			x;
}				t_player;

typedef struct	s_mlx
{
	void		*mlx;
	void		*win;
	void		*img;
	char		*buf;
	int			bpp;
	int			endl;
	int			sizel;
	void		*sky;
	void		*floor;
}				t_mlx;

typedef struct	s_wolf
{
	t_mlx		mx;
	t_player	pl;
	t_color		cl;
	int			x1;

}				t_wolf;

int				my_key(int keycode, t_wolf *w);
void			ft_draw(t_wolf *w, int x1, int y1, int y2);
int				ft_wolf(t_wolf *w);
void			img_put(t_wolf *w, int x, int y, int color);
void			ft_imageput(t_wolf *w);
void			ft_imageinit(t_wolf *w);
int				get_red(int color);
int				get_green(int color);
int				get_blue(int color);
int				geto(int color);
void			color_floor_celing(t_wolf *w, int x);
void			ft_map(t_wolf *w);

#endif
