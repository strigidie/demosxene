#include "Render.hpp"

// Base render class -----------------------------------------------------------

// Default methods -------------------------------------------------------------
Render::Render(const int width, const int height) :
	_width(width),
	_height(height)
{
	if (_width < 1 || _height < 1)
	{
		throw std::invalid_argument("The viewport size must be greater than one!");
	}

#ifdef _DEBUG
	// Init RenderDoc ....
#endif
}

Render::~Render(void) { }

// Sets methods ----------------------------------------------------------------
void Render::setViewportWidth(int width)
{
	if (width < 1)
	{
		throw std::invalid_argument("The viewport size must be greater than one!");
	}

	_width = width;
}

void Render::setViewportHeight(int height)
{
	if (height < 1)
	{
		throw std::invalid_argument("The viewport size must be greater than one!");
	}

	_height = height;
}

void Render::setCamera(const CameraShPtr& camera)
{
	if (!camera)
	{
		throw std::invalid_argument("The camera is undefined!");
	}

	_camera = camera;
}

// Gets methods ----------------------------------------------------------------
int Render::getViewportWidth(void)
{
	return _width;
}

int Render::getViewportHeight(void)
{
	return _height;
}

CameraShPtr Render::getCamera(void)
{
	return _camera;
}

// Euclidean Geomtry -----------------------------------------------------------

// Default methods -------------------------------------------------------------
RenderEuclidean::RenderEuclidean(const int width, const int height) :
	Render(width, height)
{ }

RenderEuclidean::~RenderEuclidean() { }

// Custom methods --------------------------------------------------------------
void RenderEuclidean::initRender(void)
{
	glViewport(0, 0, _width, _height);
}

void RenderEuclidean::updateFrame(const double deltaTime)
{
	
}

void RenderEuclidean::drawFrame(void)
{
	glClearColor(0.9f, 0.9f, 0.95f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);
}
