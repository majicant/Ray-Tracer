#pragma once

#include "material.h"

class Dielectric : public Material
{
public:
	Dielectric(double index);

	bool Scatter(const Ray& ray, const HitRecord& rec, Colour& attenuation, Ray& scattered) const override;

private:
	double Reflectance(double cosine, double index) const;

	double index_of_refraction;
};