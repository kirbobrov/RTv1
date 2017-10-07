//
// Created by Kyrylo Bobrov on 9/29/17.
//

#include "rtv.h"

void    ray_cam(t_rt *rt)
{

}

/*
Main rendering function.
We compute a camera ray for each pixel of the image trace
it and return a color. If the ray hits a sphere, we return
the color of the sphere at the intersection point, else we return the background color.
*/
/*
void render(const std::vector<Sphere> &spheres)
{
unsigned width = 640, height = 480;
Vec3f *image = new Vec3f[width * height], *pixel = image;
float invWidth = 1 / float(width), invHeight = 1 / float(height);
                                                   float fov = 30, aspectratio = width / float(height);
                                                                                         float angle = tan(M_PI * 0.5 * fov / 180.);
// Trace rays
for (unsigned y = 0; y < height; ++y) {
for (unsigned x = 0; x < width; ++x, ++pixel) {
float xx = (2 * ((x + 0.5) * invWidth) - 1) * angle * aspectratio;
float yy = (1 - 2 * ((y + 0.5) * invHeight)) * angle;
Vec3f raydir(xx, yy, -1);
raydir.normalize();
*pixel = trace(Vec3f(0), raydir, spheres, 0);
}
}
// Save result to a PPM image (keep these flags if you compile under Windows)
std::ofstream ofs("./untitled.ppm", std::ios::out | std::ios::binary);
ofs << "P6\n" << width << " " << height << "\n255\n";
for (unsigned i = 0; i < width * height; ++i) {
ofs << (unsigned char)(std::min(float(1), image[i].x) * 255) <<
(unsigned char)(std::min(float(1), image[i].y) * 255) <<
(unsigned char)(std::min(float(1), image[i].z) * 255);
}
ofs.close();
delete [] image;
}
 */