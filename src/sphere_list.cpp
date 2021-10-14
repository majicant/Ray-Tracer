#include "sphere_list.h"

SphereList::SphereList()
{
}

void SphereList::Add(const Sphere& sphere)
{
	spheres.push_back(sphere);
}

bool SphereList::Hit(const Ray& ray, double t_min, double t_max, HitRecord& rec) const
{
	HitRecord temp_rec;
	bool hit_anything = false;
	double closest_so_far = t_max;

	for (const auto& sphere : spheres) {
		if (sphere.Hit(ray, t_min, closest_so_far, temp_rec)) {
			hit_anything = true;
			closest_so_far = temp_rec.t;
			rec = temp_rec;
		}
	}

	return hit_anything;
}