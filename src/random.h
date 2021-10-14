#pragma once

#include "vec3.h"

class Random
{
public:
	Random() = delete;

	static double RandomDouble();
	static Vec3 RandomVec3();
	static Vec3 RandomPointInUnitSphere();
};