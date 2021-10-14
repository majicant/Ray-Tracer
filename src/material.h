#pragma once

#include "colour.h"
#include "ray.h"

struct HitRecord;

class Material
{
public:
	virtual bool Scatter(const Ray& ray, const HitRecord& rec, Colour& attenuation, Ray& scattered) const = 0;

	virtual Vec3 Reflect(const Vec3& v, const Vec3& n) const;
	virtual Vec3 Refract(const Vec3& v, const Vec3& n, double ratio) const;
};