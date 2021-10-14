#pragma once

#include <vector>

#include "sphere.h"
#include "vec3.h"

class SphereList
{
public:
	SphereList();

	void Add(const Sphere& sphere);
	bool Hit(const Ray& ray, double t_min, double t_max, HitRecord& rec) const;

private:
	std::vector<Sphere> spheres;
};