#include <cmath>

#include "material.h"

Vec3 Material::Reflect(const Vec3& v, const Vec3& n) const
{
	return v - 2.0 * Vec3::Dot(v, n) * n;
}

Vec3 Material::Refract(const Vec3& v, const Vec3& n, double ratio) const
{
	//double cos_theta = std::min(Vec3::Dot(-v, n), 1.0);

	//Vec3 perpendicular = ratio * (v + cos_theta * n);
	//Vec3 parallel = -std::sqrt(std::abs(1.0 - perpendicular.LengthSquared())) * n;

	//return perpendicular + parallel;

	double dt = Vec3::Dot(v, n);
	double discriminant = 2.0 - ratio * ratio * (1.0 - dt * dt);

	return ratio * (v - dt * n) - std::sqrt(discriminant) * n;
}