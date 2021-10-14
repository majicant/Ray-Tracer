#include "metal.h"
#include "random.h"

Metal::Metal(const Colour& a, double fuzz)
	: albedo(a), fuzziness(fuzz < 1.0 ? fuzz : 1.0)
{
}

bool Metal::Scatter(const Ray& ray, const HitRecord& rec, Colour& attenuation, Ray& scattered) const
{
	attenuation = albedo;
	Vec3 reflected = Reflect(ray.GetDirection(), rec.normal);
	scattered = Ray(rec.point, reflected + fuzziness * Random::RandomPointInUnitSphere());
	return Vec3::Dot(scattered.GetDirection(), rec.normal) > 0;
}