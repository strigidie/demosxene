#pragma once

#include <memory>
#include <stdexcept>

#include "Vector.hpp"

// Type of the camera projection method
enum class CameraProjectionType
{
	CAMERA_PERSPECTIVE,
	CAMERA_PARALLEL
};

// TODO
class CameraProjPerspective;
class CameraProjParallel;

// 3D Camera for the single render scene
class Camera
{
private:
	CameraProjectionType _proj;
	Vector3 _pos;
	Vector3 _dir;
	double _aspect_ratio;
	double _focus_length;
	double _speed;
	int _fov_deg;

public:
	// Default methods ---------------------------------------------------------
	explicit Camera(void);
	~Camera(void);

	// Sets methods ------------------------------------------------------------
	void setPosition(const Vector3& pos);
	void setDirection(const Vector3& dir);
	void setAspectRatio(const double aspect_ratio);
	void setFocusLength(const double focus_length);
	void setSpeed(const double speed);
	void setFOV(const int fov_deg);

	// Gets methods ------------------------------------------------------------
	Vector3 getPosition(void);
	Vector3 getDirection(void);
	double getAspectRatio(void);
	double getFocusLength(void);
	double getSpeed(void);
	int getFOV(void);

	// Custom methods ----------------------------------------------------------
	void moveX(const double x);
	void moveY(const double x);
	void moveZ(const double x);

	void rotatePitch(const int x_deg);
	void rotateYaw(const int y_deg);
	void rotateRoll(const int z_deg);
};

// Let's declare a camera as shared resource
using CameraShPtr = std::shared_ptr<Camera>;