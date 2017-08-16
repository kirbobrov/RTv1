/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbobrov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/12 18:11:38 by kbobrov           #+#    #+#             */
/*   Updated: 2017/08/12 18:11:41 by kbobrov          ###   ########.fr       */
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

t_vector vector_add(t_vector *v1, t_vector *v2)
{
    t_vector result;
    result.x = v1->x + v2->x;
    result.y = v1->y + v2->y;
    result.z = v1->z + v2->z;
    return (result);
}

/* Multiply two vectors and return the resulting scalar (dot product) */
float vector_dot(t_vector *v1, t_vector *v2)
{
    return (v1->x * v2->x + v1->y * v2->y + v1->z * v2->z);
}

t_vector vector_scale(float t, t_vector *v)
{
    t_vector result;

    result.x = v->x * t;
    result.y = v->y * t;
    result.z = v->z * t;
    return (result);
}

float       vector_len(t_vector *v)
{
    return (sqrtf((v->x * v->x) + (v->y * v->y) + (v->z * v->z)));
}

t_vector    vector_normalize(t_vector *v)
{
    float       len;
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

float   vector_coss(t_vector *v1, t_vector *v2)
{
    return (vector_dot(v1, v2) / (vector_len(v1) * vector_len(v2)));
}