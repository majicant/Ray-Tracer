#include <cmath>

#include "camera.h"

constexpr double CONVERT_TO_RADIANS = 0.0174533;

Camera::Camera(Vec3 lookfrom, Vec3 lookat, Vec3 vup, double vert_fov, double aspect_ratio)
	: origin(lookfrom)
{
	double height = 2.0 * std::tan((vert_fov * CONVERT_TO_RADIANS) / 2);
	double width = height * aspect_ratio;

	Vec3 z = (lookfrom - lookat).UnitVector();
	Vec3 x = Vec3::Cross(vup, z).UnitVector();
	Vec3 y = Vec3::Cross(z, x);

	horizontal = width * x;
	vertical = height * y;

	upper_left_corner = origin - horizontal / 2 + vertical / 2 - z;
}

Ray Camera::GetRay(double u, double v) const
{
	// Since we are traversing from the upper left corner, we add the offset vector u to move
	// right and subtract the offset vector v to move down.
	return Ray(origin, upper_left_corner + u * horizontal - v * vertical - origin);
}