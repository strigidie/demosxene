#pragma once

#include <stdexcept>
#include <memory>
#include <string>

#define SDL_MAIN_HANDLED
#include "SDL.h"

#include "Render.hpp"

#define M_WINDOW_NAME "Non-Euclidian Geometry"

using SDLWindowShPtr = std::shared_ptr<SDL_Window>;
using SDLContextShPtr = std::shared_ptr<void>;

// SDL2 Window
class Window
{
private:
	int _width;
	int _height;

	SDLWindowShPtr _window;
	SDLContextShPtr _context;
	RenderShPtr _render;

public:
	explicit Window(const RenderShPtr& render);
	~Window(void);

	void runMainLoop(void);
};

// Let's declare a window as unqiue resource
using WindowUqPtr = std::unique_ptr<Window>;
