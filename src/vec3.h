#pragma once

class Vec3
{
public:
	Vec3() = default;
	Vec3(double x, double y, double z);

	Vec3 operator -() const;

	double Length() const;
	double LengthSquared() const;
	Vec3 UnitVector() const;

	static double Dot(const Vec3& v1, const Vec3& v2);
	static Vec3 Cross(const Vec3& v1, const Vec3& v2);

	double x, y, z;
};

Vec3 operator +(const Vec3& v1, const Vec3& v2);
Vec3 operator -(const Vec3& v1, const Vec3& v2);
Vec3 operator *(double t, const Vec3& v);
Vec3 operator /(const Vec3& v, double t);