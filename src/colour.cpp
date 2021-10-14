#include <cmath>

#include "colour.h"

Colour::Colour(double r, double g, double b)
	: r(r), g(g), b(b)
{
}

Colour& Colour::operator +=(const Colour& c)
{
	r += c.r;
	g += c.g;
	b += c.b;
	return *this;
}

Colour& Colour::operator /=(double t)
{
	r /= t;
	g /= t;
	b /= t;
	return *this;
}

Colour operator +(const Colour& c1, const Colour& c2)
{
	return Colour(c1.r + c2.r, c1.g + c2.g, c1.b + c2.b);
}

Colour operator *(const Colour& c1, const Colour& c2)
{
	return Colour(c1.r * c2.r, c1.g * c2.g, c1.b * c2.b);
}

Colour operator *(double t, const Colour& c)
{
	return Colour(t * c.r, t * c.g, t * c.b);
}

Colour Colour::GammaCorrected() const
{
	return Colour(std::sqrt(r), std::sqrt(g), std::sqrt(b));
}