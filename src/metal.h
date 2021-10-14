#pragma once

#include "material.h"

class Metal : public Material
{
public:
	Metal(const Colour& a, double fuzz);

	bool Scatter(const Ray& ray, const HitRecord& rec, Colour& attenuation, Ray& scattered) const override;

private:
	Colour albedo;
	double fuzziness;
};