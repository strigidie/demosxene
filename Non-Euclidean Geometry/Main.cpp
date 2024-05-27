#include <iostream>

#include "Camera.hpp"
#include "Render.hpp"
#include "Window.hpp"

// Entry Point -----------------------------------------------------------------
int main(
	const int argc,
	const char* argv[])
{
	CameraShPtr camera = std::make_shared<Camera>();
	RenderShPtr render = std::make_shared<RenderEuclidean>(camera, 800, 600);
	WindowUqPtr window = std::make_unique<Window>(render);
	window->runMainLoop();

	return EXIT_SUCCESS;
}
