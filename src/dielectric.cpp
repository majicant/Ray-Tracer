#include <cmath>

#include "dielectric.h"
#include "random.h"

Dielectric::Dielectric(double index)
	: index_of_refraction(index)
{
}

bool Dielectric::Scatter(const Ray& ray, const HitRecord& rec, Colour& attenuation, Ray& scattered) const
{
	attenuation = Colour(1.0, 1.0, 1.0);

	Vec3 direction = ray.GetDirection().UnitVector();
	Vec3 normal;
	double index;
	if (Vec3::Dot(direction, rec.normal) > 0.0) {
		normal = -rec.normal;
		index = index_of_refraction;
	}
	else {
		normal = rec.normal;
		index = 1.0 / index_of_refraction;
	}

	double cos_theta = std::min(Vec3::Dot(-direction, normal), 1.0);
	double sin_theta = std::sqrt(1.0 - cos_theta * cos_theta);

	// If index * sin_theta > 1.0 then a solution can not exist and the glass can not refract
	// Therefore the ray must be reflected
	Vec3 scattered_direction = ((index * sin_theta > 1.0) || Reflectance(cos_theta, index) > Random::RandomDouble())
		? Reflect(direction, rec.normal) : Refract(direction, rec.normal, index);

	scattered = Ray(rec.point, scattered_direction);

	return true;
}

double Dielectric::Reflectance(double cosine, double index) const
{
	// Schlick's approximation for reflectance
	double r0 = (1 - index) / (1 + index);
	r0 *= r0;
	return r0 + (1 - r0) * std::pow((1 - cosine), 5);
}