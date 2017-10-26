/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbobrov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/26 20:43:34 by kbobrov           #+#    #+#             */
/*   Updated: 2017/10/26 20:43:37 by kbobrov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv.h"

double		vector_len(t_vector *v)
{
	return (sqrt((v->x * v->x) + (v->y * v->y) + (v->z * v->z)));
}

t_vector	vector_normalize(t_vector *v)
{
	double		len;
	t_vector	v1;

	len = vector_len(v);
	if (len > 0)
	{
		v1.x = v->x / len;
		v1.y = v->y / len;
		v1.z = v->z / len;
	}
	else
	{
		v1.x = v->x;
		v1.y = v->y;
		v1.z = v->z;
	}
	return (v1);
}

double		vector_coss(t_vector *v1, t_vector *v2)
{
	return (vector_dot(v1, v2) / (vector_len(v1) * vector_len(v2)));
}

t_vector	vector_mult(t_vector *v1, t_vector *v2)
{
	t_vector	mult;

	mult.x = (v1->y * v2->z) - (v1->z * v2->y);
	mult.y = (v1->z * v2->x) - (v1->x * v2->z);
	mult.z = (v1->x * v2->y) - (v1->y * v2->x);
	return (mult);
}

int			discr(t_vector *abc, t_ray *r)
{
	double		discr;
	double		x2;
	double		x1;

	discr = abc->y * abc->y - 4 * abc->x * abc->z;
	if (discr < 0)
		return (0);
	x1 = (-abc->y + sqrt(discr)) / (2 * abc->x);
	x2 = (-abc->y - sqrt(discr)) / (2 * abc->x);
	x1 = (x1 < x2) ? x1 : x2;
	x1 = (x1 < 0) ? x2 : x1;
	x1 = (x1 < 0) ? 0 : x1;
	if (x1 > 0.00001 && x1 < r->dist)
	{
		r->dist = x1;
		return (1);
	}
	return (0);
}
