#include <random>

#include "random.h"

double Random::RandomDouble()
{
	static std::uniform_real_distribution<double> dist(0.0, 1.0);
	static std::mt19937 gen;
	return dist(gen);
}

Vec3 Random::RandomVec3()
{
	return Vec3(RandomDouble(), RandomDouble(), RandomDouble());
}

Vec3 Random::RandomPointInUnitSphere()
{
	Vec3 random_point;
	do {
		random_point = RandomVec3();
	} while (random_point.LengthSquared() >= 1);

	return random_point;
}