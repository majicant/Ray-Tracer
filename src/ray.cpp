#include <limits>

#include "material.h"
#include "random.h"
#include "ray.h"

Ray::Ray(const Vec3& o, const Vec3& d)
	: origin(o), direction(d)
{
}

Vec3 Ray::GetPointOnLine(double t) const
{
	return origin + t * direction;
}

Colour Ray::GetColour(const SphereList& spheres, int depth) const
{
	HitRecord rec;

	// Stop bouncing rays when we have exceeded the depth limit
	if (depth <= 0)
		return Colour();

	// If the ray hits a sphere it will bounce off of it
	// We use t_min = 0.001 to fix shadow acne in image
	if (spheres.Hit(*this, 0.001, std::numeric_limits<double>::infinity(), rec)) {
		Colour attenuation;
		Ray scattered;
		if (rec.material->Scatter(*this, rec, attenuation, scattered))
			return attenuation * scattered.GetColour(spheres, depth - 1);
		return Colour();
	}

	Vec3 unit_direction = direction.UnitVector();
	double t = 0.5 * (unit_direction.y + 1.0);
	return (1.0 - t) * Colour(1.0, 1.0, 1.0) + t * Colour(0.5, 0.7, 1.0);
}

Vec3 Ray::GetOrigin() const
{
	return origin;
}

Vec3 Ray::GetDirection() const
{
	return direction;
}