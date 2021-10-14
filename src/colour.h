#pragma once

class Colour
{
public:
	Colour() = default;
	Colour(double r, double g, double b);

	Colour& operator +=(const Colour& c);
	Colour& operator /=(double t);

	Colour GammaCorrected() const;

	double r, g, b;
};

Colour operator +(const Colour& c1, const Colour& c2);
Colour operator *(const Colour& c1, const Colour& c2);
Colour operator *(double t, const Colour& c);