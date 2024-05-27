#include "Render.hpp"

// Abstract Class --------------------------------------------------------------
Render::Render(const CameraShPtr& camera, const int width, const int height) :
	_camera(camera),
	_width(width),
	_height(height)
{
	if (width < 1 || height < 1)
		throw std::runtime_error("Error: Render::Render()");

#ifdef _DEBUG
	// Init RenderDoc ....
#endif
}

Render::~Render(void) { }

int Render::getWidth(void)
{
	return _width;
}

int Render::getHeight(void)
{
	return _height;
}

double Render::getAspectRatio(void)
{
	if (_height != 0)
		return static_cast<double>(_width) / _height;
	return 0.0F;
}

CameraShPtr Render::getCameraShPtr(void)
{
	return _camera;
}

void Render::setWidth(int width)
{
	if (width < 1)
		throw std::runtime_error("Error: Render::setWidth()");
	_width = width;
}

void Render::setHeight(int height)
{
	if (height < 1)
		throw std::runtime_error("Error: Render::setHeight()");
	_height = height;
}

void Render::setCameraShPtr(const CameraShPtr& camera)
{
	if (!camera)
		throw std::runtime_error("Error: Render::setCameraShPtr()");
	_camera = camera;
}

// Euclidean Geomtry -----------------------------------------------------------
RenderEuclidean::RenderEuclidean(
	const CameraShPtr& camera,
	const int width,
	const int height) : Render(camera, width, height)
{

}

RenderEuclidean::~RenderEuclidean() { }

void RenderEuclidean::updateFrame(const double deltaTime)
{

}

void RenderEuclidean::drawFrame(void)
{

}