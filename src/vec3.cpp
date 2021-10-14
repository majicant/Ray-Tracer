#include <cmath>

#include "vec3.h"

Vec3::Vec3(double x, double y, double z)
	: x(x), y(y), z(z)
{
}

Vec3 Vec3::operator -() const
{
	return Vec3(-x, -y, -z);
}

double Vec3::Dot(const Vec3& v1, const Vec3& v2)
{
	return v1.x * v2.x + v1.y * v2.y + v1.z * v2.z;
}

Vec3 Vec3::Cross(const Vec3& v1, const Vec3& v2)
{
	return Vec3(v1.y * v2.z - v1.z * v2.y,
		v1.z * v2.x - v1.x * v2.z,
		v1.x * v2.y - v1.y * v2.x);
}

Vec3 operator +(const Vec3& v1, const Vec3& v2)
{
	return Vec3(v1.x + v2.x, v1.y + v2.y, v1.z + v2.z);
}

Vec3 operator -(const Vec3& v1, const Vec3& v2)
{
	return Vec3(v1.x - v2.x, v1.y - v2.y, v1.z - v2.z);
}

Vec3 operator *(double t, const Vec3& v)
{
	return Vec3(t * v.x, t * v.y, t * v.z);
}

Vec3 operator /(const Vec3& v, double t)
{
	return (1 / t) * v;
}

double Vec3::Length() const
{
	return std::sqrt(LengthSquared());
}

double Vec3::LengthSquared() const
{
	return x * x + y * y + z * z;
}

Vec3 Vec3::UnitVector() const
{
	return (*this) / Length();
}