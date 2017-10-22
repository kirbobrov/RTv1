/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbobrov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/15 20:42:24 by kbobrov           #+#    #+#             */
/*   Updated: 2017/10/15 20:42:26 by kbobrov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv.h"

int		ft_mouse_exit(void)
{
    exit(55);
}

int     ft_keys(int id, t_rt *r)
{
    (id == 53) ? exit(53) : 0;

    (id == 78 || id == 27) ? r->ray.start0.z -= 50 : 0;
    (id == 69 || id == 24) ? r->ray.start0.z += 50 : 0;
    (id == 124) ? r->cam.horizontal += 0.1 : 0;
    (id == 123) ? r->cam.horizontal -= 0.1 : 0;
    (id == 126) ? r->cam.vertical += 0.1 : 0;
    (id == 125) ? r->cam.vertical -= 0.1 : 0;
    if (id == 2)
    {
        r->ray.start.x += 20;
        r->ray.start.z -= 10;
        r->ray.ay -= 10;
    }
    if (id == 0)
    {
        r->ray.start.x -= 20;
        r->ray.start.z += 10;
        r->ray.ay += 10;
    }
    tracer(r);
    printf("key id == %d\n", id);
    return (0);
}