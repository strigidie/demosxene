#pragma once

#include <stdexcept>
#include <memory>

#include "glew.h"

#include "Camera.hpp"

// Abstract class for further declaring of different geometries
class Render
{
private:
	// Viewport Size
	int _width;
	int _height;

	CameraShPtr _camera;

public:
	explicit Render(const CameraShPtr& camera, const int width, const int height);
	virtual ~Render(void);

	virtual void updateFrame(const double deltaTime) = 0;
	virtual void drawFrame(void) = 0;

	// Gets methods
	int getWidth(void);
	int getHeight(void);
	double getAspectRatio(void);

	CameraShPtr getCameraShPtr(void);

	// Sets methods
	void setWidth(int width);
	void setHeight(int height);
	void setCameraShPtr(const CameraShPtr& camera);
};

// Default Euclidean geometry
class RenderEuclidean : public Render
{
public:
	explicit RenderEuclidean(const CameraShPtr& camera, const int width, const int height);
	~RenderEuclidean(void);

	void updateFrame(const double deltaTime) override;
	void drawFrame(void) override;
};

// Let's declare a render as shared resource
using RenderShPtr = std::shared_ptr<Render>;
