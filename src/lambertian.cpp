#include "lambertian.h"
#include "random.h"

Lambertian::Lambertian(const Colour& a)
	: albedo(a)
{
}

bool Lambertian::Scatter(const Ray& ray, const HitRecord& rec, Colour& attenuation, Ray& scattered) const
{
	attenuation = albedo;
	Vec3 target = rec.point + rec.normal + Random::RandomPointInUnitSphere().UnitVector();
	scattered = Ray(rec.point, target - rec.point);
	return true;
}