//
// Created by Kyrylo Bobrov on 06.07.17.
//

/* A simple ray tracer */

#include <stdio.h>
#include <stdbool.h> /* Needed for boolean datatype */
#include <math.h>
#include "rtv.h"
#define min(a,b) (((a) < (b)) ? (a) : (b))

/* Subtract two vectors and return the resulting vector */




t_vector ft_vectorsub(t_vector *v1, t_vector *v2)
{
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

/* Calculate Vector x Scalar and return resulting Vector*/
t_vector vectorScale(float c, t_vector *v)
{
	t_vector result;
    ///result = {v->x * c, v->y * c, v->z * c };
    result.x = v->x * c;
    result.y = v->y * c;
    result.z = v->z * c;
	return (result);
}


/* Add two vectors and return the resulting vector */
t_vector vectorAdd(t_vector *v1, t_vector *v2)
{
	t_vector result;
    ///result = {v1->x + v2->x, v1->y + v2->y, v1->z + v2->z };
    result.x = v1->x + v2->x;
    result.y = v1->y + v2->y;
    result.z = v1->z + v2->z;

    ///printf("result.x == %f\tresult.y == %f\tresult.z == %f\n", result.x, result.y, result.z);

	return (result);
}

/* Check if the ray and sphere intersect */
int     intersectRaySphere(t_ray *r, t_sphere *s, float *t)
{

	int     retval;
    retval = 0;
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
	 * t represents the distance between the start of the ray and
	 * the point on the sphere where it intersects.
	 */
	if(discr < 0)
		retval = 0;
	else
    {
		float sqrtdiscr;
        sqrtdiscr = sqrtf(discr);
		float t0;
        t0 = (-B + sqrtdiscr)/(2);
		float t1;
        t1 = (-B - sqrtdiscr)/(2);

		/* We want the closest one */
		if(t0 > t1)
			t0 = t1;
		/* Verify t1 larger than 0 and less than the original t */
		if((t0 > 0.001f) && (t0 < *t))
        {
			*t = t0;
			retval = 1;
		}
        else
			retval = 0;
	}
	return (retval);
}
/*
*//* Output data as PPM file *//*
void saveppm(char *filename, unsigned char *img, int width, int height){
	*//* FILE pointer *//*
	FILE *f;

	*//* Open file for writing *//*
	f = fopen(filename, "w");

	*//* PPM header info, including the size of the image *//*
	fprintf(f, "P6 %d %d %d\n", width, height, 255);

	*//* Write the image data to the file - remember 3 byte per pixel *//*
	fwrite(img, 3, width*height, f);

	*//* Make sure you close the file *//*
	fclose(f);
}*/

//int main(int argc, char *argv[]){
//
//	ray r;

	/*material materials[3];
	materials[0].diffuse.red = 1;
	materials[0].diffuse.green = 0;
	materials[0].diffuse.blue = 0;
	materials[0].reflection = 0.2;

	materials[1].diffuse.red = 0;
	materials[1].diffuse.green = 1;
	materials[1].diffuse.blue = 0;
	materials[1].reflection = 0.5;

	materials[2].diffuse.red = 0;
	materials[2].diffuse.green = 0;
	materials[2].diffuse.blue = 1;
	materials[2].reflection = 0.9;

	sphere spheres[3];
	spheres[0].pos.x = 200;
	spheres[0].pos.y = 300;
	spheres[0].pos.z = 0;
	spheres[0].radius = 100;
	spheres[0].material = 0;

	spheres[1].pos.x = 400;
	spheres[1].pos.y = 400;
	spheres[1].pos.z = 0;
	spheres[1].radius = 100;
	spheres[1].material = 1;

	spheres[2].pos.x = 500;
	spheres[2].pos.y = 140;
	spheres[2].pos.z = 0;
	spheres[2].radius = 100;
	spheres[2].material = 2;

	light lights[3];

	lights[0].pos.x = 0;
	lights[0].pos.y = 240;
	lights[0].pos.z = -100;
	lights[0].intensity.red = 1;
	lights[0].intensity.green = 1;
	lights[0].intensity.blue = 1;

	lights[1].pos.x = 3200;
	lights[1].pos.y = 3000;
	lights[1].pos.z = -1000;
	lights[1].intensity.red = 0.6;
	lights[1].intensity.green = 0.7;
	lights[1].intensity.blue = 1;

	lights[2].pos.x = 600;
	lights[2].pos.y = 0;
	lights[2].pos.z = -100;
	lights[2].intensity.red = 0.3;
	lights[2].intensity.green = 0.5;
	lights[2].intensity.blue = 1;*/

	/* Will contain the raw image */
//	unsigned char img[3*WIDTH*HEIGHT];
int		ft_sphere2(t_rt *rt)
{
    int hit;

    hit = 0;

//	int x, y;
    rt->y = 0;
    while (rt->y < SIZE_Y)
    {
        /* Set the y-coordinate of the start position of the ray */
        rt->ray.start.y = rt->y;
        rt->x = 0;
        while (rt->x < SIZE_X)
        {

            rt->col.blue = 0;
            rt->col.green = 0;
            rt->col.red = 0;
			int level = 0;
			float coef = 1.0;

			rt->ray.start.x = rt->x;
            rt->ray.start.y = rt->y;
            rt->ray.start.z = -2000;

			rt->ray.dir.x = 0;
            rt->ray.dir.y = 0;
            rt->ray.dir.z = 1;


            while ((coef > 0.0f) && (level < 15))
            {
				/* Find closest intersection */
				float t = 20000.0f;
				///it currentSphere = -1;

//				unsigned int i;
//                i = 0;
//
//				while (i < 3)
//                {
//                    if(intersectRaySphere(&rt->ray, &rt->sph[i], &t))
//                        currentSphere = i;
//                    i++;
//				}
//				if(currentSphere == -1)
//                    return (0);

				t_vector scaled;
                scaled = vectorScale(t, &rt->ray.dir);
				t_vector newStart;
                newStart = vectorAdd(&rt->ray.start, &scaled);

				/* Find the normal for this new vector at the point of intersection */
				t_vector n;
                n = ft_vectorsub(&newStart, &rt->sph.pos);

				float temp ;
                temp = vectorDot(&n, &n);
               /// printf("temp == %f\n", temp);
				if(temp == 0)
                    break;

				temp = 1.0f / sqrtf(temp);
				n = vectorScale(temp, &n);

				/* Find the material to determine the colour */
				///material currentMat = materials[].material];

				/* Find the value of the light at this point */
				unsigned int j;

                j = 0;
				while (j < 3)
                {
                   printf("j == %d\n", j);
					///light currentLight = lights[j];
					t_vector dist;
                    dist = ft_vectorsub(&rt->light.pos, &newStart);
					if((vectorDot(&n, &dist) > 0.0f))
                        break;

                    float t;
                    t = sqrtf(vectorDot(&dist,&dist));
                    if((t > 0.0f))
                        break;

					t_ray lightRay;
					lightRay.start = newStart;
					lightRay.dir = vectorScale((1/t), &dist);

					/* Calculate shadows */
//					int inShadow = 0;
//					unsigned int k;
//                    k = 0;
//					while (k++ < 3)
//                    {
//                        printf("2");
//						if (intersectRaySphere(&lightRay, &rt->sph, &t))
//                        {
//							inShadow = 1;
//							break;
//						}
//					}
//					if (inShadow == 0)
//                    {
						/* Lambert diffusion */
						float lambert;
                        lambert = vectorDot(&lightRay.dir, &n) * coef;
                       /// lambert = vectorDot(&lightRay.dir, &n);
                        printf("lambert == %f\n", lambert);
						rt->col.red += lambert * rt->light.intensity.red * rt->mat.diffuse.red;
                        rt->col.green += lambert * rt->light.intensity.green * rt->mat.diffuse.green;
                        rt->col.blue += lambert * rt->light.intensity.blue * rt->mat.diffuse.blue;
//					}
                    j++;
				}
               ///printf("red == %f\tgreen == %f\tblue == %f\t\n", rt->col.red, rt->col.green, rt->col.blue);
				/* Iterate over the reflection */
				coef *= rt->mat.reflection;

				/* The reflected ray start and direction */
				rt->ray.start = newStart;
				float reflect;
                reflect = 2.0f * vectorDot(&rt->ray.dir, &n);
				t_vector tmp;
                tmp = vectorScale(reflect, &n);
                rt->ray.dir = ft_vectorsub(&rt->ray.dir, &tmp);

				level++;
			}

            ft_img_color(rt);
            rt->x++;
//			img[(x + y*WIDTH)*3 + 0] = (unsigned char)min(red*255.0f, 255.0f);
//			img[(x + y*WIDTH)*3 + 1] = (unsigned char)min(green*255.0f, 255.0f);
//			img[(x + y*WIDTH)*3 + 2] = (unsigned char)min(blue*255.0f, 255.0f);
		}
        ///printf("current x == %d\t current y == %d\n", rt->x, rt->y);
        rt->y++;
	}

//	saveppm("image.ppm", img, WIDTH, HEIGHT);

	return (0);
}