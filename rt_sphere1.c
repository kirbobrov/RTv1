//
// Created by Kyrylo Bobrov on 06.07.17.
//

/* A simple ray tracer */

#include "rtv.h"

/* The vector structure */


/* The sphere */


/* The ray */





/* Subtract two vectors and return the resulting vector */
t_vector ft_vectorsub(t_vector *v1, t_vector *v2){
	t_vector result;
	result.x = v1->x - v2->x;
    result.y = v1->y - v2->y;
    result.z = v1->z - v2->z;
	return (result);
}

/* Multiply two vectors and return the resulting scalar (dot product) */
float vectorDot(t_vector *v1, t_vector *v2)
{
	return (v1->x * v2->x + v1->y * v2->y + v1->z * v2->z);
}

float       vectorlen(t_vector *v)
{
    return(sqrtf((v->x * v->x) + (v->y * v->y) + (v->z * v->z)));
}

t_vector    vectornorm(t_vector *v)
{
    float       len;
    t_vector    v1;

    len = vectorlen(v);
    v1.x = v->x / len;
    v1.y = v->y / len;
    v1.z = v->z / len;
    return(v1);
}

float   sqrt1(float a ,float b ,float c)
{

}

float   sqrt2(float a ,float b ,float c)
{

}

int     intersectsphere(t_ray *r, t_sphere *s) ///// write to shadows one more arg
{

}



/* Check if the ray and sphere intersect */
int intersectRaySphere(t_ray *r, t_sphere *s){
	
	/* A = d.d, the vector dot product of the direction */
	float A;
    A = vectorDot(&r->dir, &r->dir);
	
	/* We need a vector representing the distance between the start of 
	 * the ray and the position of the circle.
	 * This is the term (p0 - c) 
	 */
	t_vector dist;
	dist = ft_vectorsub(&r->start, &s->pos);
	
	/* 2d.(p0 - c) */
	float B;
	B = 2 * vectorDot(&r->dir, &dist);
	
	/* (p0 - c).(p0 - c) - r^2 */
	float C;
	C = vectorDot(&dist, &dist) - (s->radius * s->radius);
	
	/* Solving the discriminant */
	float discr;
	discr = B * B - 4 * A * C;
	
	/* If the discriminant is negative, there are no real roots.
	 * Return false in that case as the ray misses the sphere.
	 * Return true in all other cases (can be one or two intersections)
	 */
	if(discr < 0)
		return (0);
	else
		return (1);
}

/* Output data as PPM file */
//void saveppm(char *filename, unsigned char *img, int width, int height){
//	/* FILE pointer */
//	FILE *f;
//
//	/* Open file for writing */
//	f = fopen(filename, "w");
//
//	/* PPM header info, including the size of the image */
//	fprintf(f, "P6 %d %d %d\n", width, height, 255);
//
//	/* Write the image data to the file - remember 3 byte per pixel */
//	fwrite(img, 3, width*height, f);
//
//	/* Make sure you close the file */
//	fclose(f);
//}

int		ft_sphere(t_rt *rt)
{
	
	/* Image data */


	/* Our ray and a sphere */
	///sphere s;
	///ray r;
	
	/* x, y for screen 'resolution' */


	/* Intersect ray/sphere or not */
    int         hit;
    float       fov;
//    t_vector    nvect;

    fov = 66.0;
    hit = 0;

	/* Position the sphere */
	/*rt->sph.pos.x = 400;
	rt->sph.pos.y = 400;
	rt->sph.pos.z = 200;

	*//* Sphere radius *//*
	rt->sph.radius = 200;

	*//* Direction of the ray *//*
	rt->ray.dir.x = 0;
	rt->ray.dir.y = 0;
	rt->ray.dir.z = 1;*/

	/* Start position of the ray, z coordinate */
	rt->ray.start.z = 0;

	/* Iterate over every pixel of our screen */

    rt->y = 0;
	while (rt->y < SIZE_Y)
	{
		/* Set the y-coordinate of the start position of the ray */
			rt->ray.start.y = rt->y;
        rt->x = 0;
		while (rt->x < SIZE_X)
		{

            float imageAspectRatio = SIZE_X / (float)SIZE_Y; // assuming width > height
            float px = ((2 * ((rt->x + 0.5) / SIZE_X) - 1) * tan(fov / 2 * M_PI / 180) * imageAspectRatio);
            float py = (1 - 2 * ((rt->y + 0.5) / SIZE_Y) * tan(fov / 2 * M_PI / 180));

            /* Set the x-coordinate of the start position of the ray */
			rt->ray.start.x = 0;
            rt->ray.start.y = 0;
            rt->ray.start.z = 0;

            rt->ray.dir.x = px;
            rt->ray.dir.y = py;
            rt->ray.dir.z = -1;

            rt->ray.dist = 10000;

            rt->ray.dir = vectornorm(&rt->ray.dir);
			/* Check if the ray intersects with the shpere */
			hit = intersectRaySphere(&rt->ray, &rt->sph);
			if(hit == 1)
			{
//                mlx_pixel_put(rt->mx.mlx, rt->mx.win, rt->x, rt->y, 0xFFFFFF);
                rt->col.blue = 1;
                rt->col.green = 0.5;
                rt->col.red = 0.25;

//				rt->mx.buf[(rt->x + rt->y * SIZE_X) * 3 + 0] = 255;
//				rt->mx.buf[(rt->x + rt->y * SIZE_X) * 3 + 1] = 0;
//				rt->mx.buf[(rt->x + rt->y * SIZE_X) * 3 + 2] = 0;
			}
			else
			{
                rt->col.blue = 0;
                rt->col.green = 0;
                rt->col.red = 0;

////                mlx_pixel_put(rt->mx.mlx, rt->mx.win, rt->x, rt->y, 0xFF00FF);
////				rt->mx.buf[(rt->x + rt->y * SIZE_X) * 3 + 0] = 0;
////				rt->mx.buf[(rt->x + rt->y * SIZE_X) * 3 + 1] = 0;
////				rt->mx.buf[(rt->x + rt->y * SIZE_X) * 3 + 2] = 0;
			}
            ft_img_color(rt);
            rt->x++;
		}
        rt->y++;
	}


	return (0);
}