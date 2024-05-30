#pragma once

#include <stdexcept>
#include <memory>

#include "glew.h"
#include "SDL_opengl.h"

#include "Camera.hpp"
#include "Object.hpp"

#define M_VIEWPORT_WIDTH 800
#define M_VIEWPORT_HEIGHT 600

// Base class for further declaring of different geometries
class Render
{
protected:
	int _width;
	int _height;

	CameraShPtr _camera;

public:
	// Default methods ---------------------------------------------------------
	explicit Render(const int width, const int height);
	virtual ~Render(void);

	// Sets methods ------------------------------------------------------------
	void setViewportWidth(int width);
	void setViewportHeight(int height);
	void setCamera(const CameraShPtr& camera);

	// Gets methods ------------------------------------------------------------
	int getViewportWidth(void);
	int getViewportHeight(void);
	CameraShPtr getCamera(void);

	// Custom methods ----------------------------------------------------------
	virtual void initRender(void) = 0;
	virtual void updateFrame(const double delta_time) = 0;
	virtual void drawFrame(void) = 0;
};

// Default Euclidean geometry
class RenderEuclidean : public Render
{
public:
	// Default methods ---------------------------------------------------------
	explicit RenderEuclidean(const int width, const int height);
	~RenderEuclidean(void);

	// Custom methods ----------------------------------------------------------
	void initRender(void) override;
	void updateFrame(const double delta_time) override;
	void drawFrame(void) override;
};

// Declare Spherical Non-Euclidean geometry
class RenderSpherical;

// Let's declare a render as shared resource
using RenderShPtr = std::shared_ptr<Render>;
