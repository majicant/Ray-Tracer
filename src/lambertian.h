#pragma once

#include "material.h"

class Lambertian : public Material
{
public:
	Lambertian(const Colour& a);

	bool Scatter(const Ray& ray, const HitRecord& rec, Colour& attenuation, Ray& scattered) const override;

private:
	Colour albedo;
};