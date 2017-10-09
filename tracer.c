
#include "rtv.h"

int		tracer(t_rt *rt)
{
  ///  int     yc;
   /// int     xc;
    int     y;
    int     x;
    float   coss;

    rt->ray.start.x = 0;
    rt->ray.start.y = 0;
    rt->ray.start.z = -130;

   /// yc = SIZE_Y / 2;
   /// xc = SIZE_X / 2;
    /// y = -yc;

    y = 0;
    float invWidth = (float) 1 / (float)SIZE_X;
    float invHeight = (float) 1 / (float)SIZE_Y;
    float aspectratio = (float)SIZE_X / (float)SIZE_Y;
    float angle = (float) tan(M_PI * 0.5 * 30 / 180.);

    while (y < SIZE_Y)
    {
        x = 0;
        ///x = -xc;
        while (x < SIZE_X)
        {
          ///  i = 0;

            rt->ray.dir.x = (float) ((2 * ((x + 0.5) * invWidth) - 1) * angle * aspectratio);
            rt->ray.dir.y = (float) ((1 - 2 * ((y + 0.5) * invHeight)) * angle);
            rt->ray.dir.z = 1;


            rt->ray.dir = vector_normalize(&rt->ray.dir);

            rt->ray.dist = 2000001;

           /// printf("x == %d\ty == %d\t\t",x,y);
            intersection(rt);

            if (rt->hit == 1)
            {
                t_vector dist; /// distantion
                dist = vector_sub(&rt->light.pos, &rt->ray.hit_point);
                float t;
                t = vector_len(&dist);///sqrtf(vector_dot(&dist, &dist));
                t_ray lightRay;

                lightRay.start = rt->ray.hit_point;
                lightRay.dir = vector_scale((1 / t), &dist);

                float lambert;
                ///printf("obj->id === %d\t\n", rt->obj->id);
                lambert = vector_dot(&lightRay.dir, &rt->ray.normal); /// lambert difusion


                (lambert < 0) ? lambert = 0 : 0;
                if (rt->i == 11)
                {
                    t_vector v;
                    v = vector_normalize(&rt->pl->dir);
                    lambert = vector_dot(&lightRay.dir, &v);
                    (lambert < 0) ? (lambert = -lambert) : 0;
                   /// printf("plaine lambert == %f\n", lambert);
                }
                rt->hit2 = 0;
                intersection(rt);
                if (rt->hit2 == 0)
                {
                    rt->col.red = lambert * rt->col.red;
                    rt->col.green = lambert * rt->col.green;
                    rt->col.blue = lambert * rt->col.blue;

                    coss = vector_coss(&rt->ray.normal, &lightRay.dir);
                    (coss < 0) ? coss = 0 : 0;
                    // coss = -coss;

//                  rt->col.a = (230 * (1 - coss));
                    rt->col.red += ((255 - rt->col.red) * (0.9 * pow(coss, 25) + 0.1 * coss));
                    rt->col.green += ((255 - rt->col.green) * (0.9 * pow(coss, 25) + 0.1 * coss));
                    rt->col.blue += ((255 - rt->col.blue) * (0.9 * pow(coss, 25) + 0.1 * coss));
                    /// printf("lambert == %f\t normal.x == %f\tnormal.y == %f\tnormal.z == %f\n", lambert, rt->ray.normal.x, rt->ray.normal.y, rt->ray.normal.z);
                }
                else
                {
                    rt->col.a = 0.9;
                    rt->col.blue = 0.5;
                    rt->col.green = 1 /255;
                    rt->col.red = 0.1;
                    /// printf(" HELLO \n"); //// shadow
                }
            }
            else
            {   rt->col.blue = 0.9;
                rt->col.green = 0.9;
                rt->col.red = 0.9;
            }
            ft_img_color(rt, x, y);
            x++;
        }
        y++;
    }
    return (0);
}