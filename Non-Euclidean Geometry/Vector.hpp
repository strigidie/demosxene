#pragma once

// Vectors and Matrices

class Vector3
{
public:
	double _x;
	double _y;
	double _z;

public:
	Vector3(void) : _x(0.0F), _y(0.0F), _z(0.0F) { }
	Vector3(const double x, const double y, const double z) :
		_x(x), _y(y), _z(z)
	{ }

	~Vector3(void) { }
};

