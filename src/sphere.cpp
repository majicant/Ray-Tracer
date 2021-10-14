#include <cmath>

#include "material.h"
#include "ray.h"
#include "sphere.h"

Sphere::Sphere(const Vec3& c, double r, const Material& mat)
	: centre(c), radius(r), material(mat)
{
}

bool Sphere::Hit(const Ray& ray, double t_min, double t_max, HitRecord& rec) const
{
	Vec3 oc = ray.GetOrigin() - centre;
	double a = Vec3::Dot(ray.GetDirection(), ray.GetDirection());
	// b = 2h
	double h = Vec3::Dot(ray.GetDirection(), oc);
	// Vec3::Dot(oc, oc) = oc.LengthSquared()
	double c = oc.LengthSquared() - radius * radius;
	double discriminant = h * h - a * c;

	if (discriminant < 0.0)
		return false;

	double sqrt_dis = std::sqrt(discriminant);
	double root = (-h - sqrt_dis) / a;

	// Check if the root is in the acceptable range
	if (root < t_min || root > t_max) {
		root = (-h - sqrt_dis) / a;
		if (root < t_min || root > t_max)
			return false;
	}

	// The ray is a hit
	rec.point = ray.GetPointOnLine(root);
	rec.normal = (rec.point - centre) / radius;
	rec.t = root;
	rec.material = &material;
	return true;
}