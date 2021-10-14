#pragma once

#include "colour.h"
#include "sphere_list.h"
#include "vec3.h"

class Ray
{
public:
	Ray() = default;
	Ray(const Vec3& o, const Vec3& d);

	Vec3 GetPointOnLine(double t) const;
	Colour GetColour(const SphereList& sphere, int depth) const;

	Vec3 GetOrigin() const;
	Vec3 GetDirection() const;

private:
	Vec3 origin;
	Vec3 direction;
};