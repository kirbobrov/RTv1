/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbobrov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/12 18:11:38 by kbobrov           #+#    #+#             */
/*   Updated: 2017/10/15 20:42:07 by kbobrov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv.h"

t_vector vector_sub(t_vector *v1, t_vector *v2)
{
    t_vector result;

    result.x = v1->x - v2->x;
    result.y = v1->y - v2->y;
    result.z = v1->z - v2->z;
    return (result);
}

t_vector    cross_product(t_vector *v1, t_vector *v2)
{
    t_vector    v;

    v.x = v1->y * v2->z - v1->z * v2->y;
    v.y = v1->z * v2->x - v1->x * v2->z;
    v.z = v1->x * v2->y - v1->y * v2->x;
    return (v);
}

t_vector vector_add(t_vector *v1, t_vector *v2)
{
    t_vector result;
    result.x = v1->x + v2->x;
    result.y = v1->y + v2->y;
    result.z = v1->z + v2->z;
    return (result);
}

double vector_dot(t_vector *v1, t_vector *v2)
{
    return (v1->x * v2->x + v1->y * v2->y + v1->z * v2->z);
}

t_vector vector_scale(double t, t_vector *v)
{
    t_vector result;

    result.x = v->x * t;
    result.y = v->y * t;
    result.z = v->z * t;
    return (result);
}

double       vector_len(t_vector *v)
{
    return (sqrt((v->x * v->x) + (v->y * v->y) + (v->z * v->z)));
}

t_vector    vector_normalize(t_vector *v)
{
    double       len;
    t_vector    v1;

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
    return(v1);
}

double   vector_coss(t_vector *v1, t_vector *v2)
{
    return (vector_dot(v1, v2) / (vector_len(v1) * vector_len(v2)));
}

t_vector    vector_mult(t_vector *v1, t_vector *v2)
{
    t_vector    mult;

    mult.x = (v1->y * v2->z) - (v1->z * v2->y);
    mult.y = (v1->z * v2->x) - (v1->x * v2->z);
    mult.z = (v1->x * v2->y) - (v1->y * v2->x);

    return(mult);
}

int   discr(t_vector *abc, t_ray *r)
{
    double   discr;
    double   x2;

    discr = abc->y * abc->y - 4 * abc->x * abc->z;
    if (discr < 0)
        return (0);
    x2 = (-abc->y - sqrt(discr)) / (2 * abc->x);
    if (x2 > 0.00001 && x2 < r->dist)
    {
        r->dist = x2;
        return (1);
    }
    return (0);
}
