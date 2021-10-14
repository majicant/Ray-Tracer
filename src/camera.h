#pragma once

#include "ray.h"
#include "vec3.h"

class Camera
{
public:
	Camera(Vec3 lookfrom, Vec3 lookat, Vec3 vup, double vert_fov, double aspect_ratio);

	Ray GetRay(double u, double v) const;

private:
	Vec3 horizontal;
	Vec3 vertical;
	Vec3 origin;
	Vec3 upper_left_corner;
};