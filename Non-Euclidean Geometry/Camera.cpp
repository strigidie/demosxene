#include "Camera.hpp"

// Default methods -------------------------------------------------------------
Camera::Camera(void) :
	_proj(CameraProjectionType::CAMERA_PERSPECTIVE),
	_pos(Vector3(0.0F, 0.0F, 0.0F)),
	_dir(Vector3(0.0F, 0.0F, 1.0F)),
	_aspect_ratio(1.0F),
	_focus_length(1.0F),
	_speed(10.0F),
	_fov_deg(90)
{
	// By default, the camera looks along the Z-Axis and has a square aspect ratio
}

Camera::~Camera(void) { }

// Sets methods ----------------------------------------------------------------
void Camera::setPosition(const Vector3& pos)
{
	_pos = pos;
}

void Camera::setDirection(const Vector3& dir)
{
	if (_dir._x > 1 || _dir._x < -1 ||
		_dir._y > 1 || _dir._y < -1 ||
		_dir._z > 1 || _dir._z < -1)
	{
		throw std::invalid_argument("The vector is not normalized!");
	}

	_dir = dir;
}

void Camera::setAspectRatio(const double aspect_ratio)
{
	if (aspect_ratio <= 0)
	{
		throw std::invalid_argument("The aspect ratio must be greater than zero!");
	}

	_aspect_ratio = aspect_ratio;
}

void Camera::setFocusLength(const double focus_length)
{
	if (focus_length <= 0)
	{
		throw std::invalid_argument("The focus length must be greater than zero!");
	}

	_focus_length = focus_length;
}

void Camera::setSpeed(const double speed)
{
	_speed = speed;
}

void Camera::setFOV(const int fov_deg)
{
	_fov_deg = fov_deg % 360;
}

// Gets methods ----------------------------------------------------------------
Vector3 Camera::getPosition(void)
{
	return _pos;
}

Vector3 Camera::getDirection(void)
{
	return _dir;
}

double Camera::getAspectRatio(void)
{
	return _aspect_ratio;
}

double Camera::getFocusLength(void)
{
	return _focus_length;
}

double Camera::getSpeed(void)
{
	return _speed;
}

int Camera::getFOV(void)
{
	return _fov_deg;
}

// Custom methods --------------------------------------------------------------