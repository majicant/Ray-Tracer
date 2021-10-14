#pragma once

#include "vec3.h"

class Material;
class Ray;

struct HitRecord
{
	Vec3 point;
	Vec3 normal;
	double t;
	const Material* material;
};

class Sphere
{
public:
	Sphere(const Vec3& c, double r, const Material& mat);

	bool Hit(const Ray& ray, double t_min, double t_max, HitRecord& rec) const;

private:
	Vec3 centre;
	double radius;
	const Material& material;
};