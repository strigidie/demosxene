#include "Window.hpp"

Window::Window(const RenderShPtr& render) :
	_render(render),
	_width(render->getViewportWidth()),
	_height(render->getViewportHeight())
{
	// SDL initiliazing --------------------------------------------------------
	SDL_SetMainReady();
	if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_TIMER) < 0)
	{
		throw std::runtime_error(std::string(SDL_GetError()));
	}

	atexit(SDL_Quit);

	// Window initiliazing -----------------------------------------------------
	_window = std::shared_ptr<SDL_Window>(
		SDL_CreateWindow(
			M_WINDOW_NAME,
			SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
			_width, _height,
			SDL_WINDOW_OPENGL | SDL_WINDOW_RESIZABLE | SDL_WINDOW_ALLOW_HIGHDPI
		),
		SDL_DestroyWindow
	);

	if (!_window)
	{
		throw std::runtime_error(std::string(SDL_GetError()));
	}

	// OpenGL4.1 context initiliazing ------------------------------------------
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 4);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 1);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK,
		SDL_GL_CONTEXT_PROFILE_CORE);
	SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
	SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 24);
	SDL_GL_SetAttribute(SDL_GL_STENCIL_SIZE, 8);

	_context = std::shared_ptr<void>(
		SDL_GL_CreateContext(_window.get()),
		SDL_GL_DeleteContext
	);

	if (!_context)
	{
		throw std::runtime_error(std::string(SDL_GetError()));
	}

	SDL_GL_MakeCurrent(_window.get(), _context.get());
	SDL_GL_SetSwapInterval(1);

	// GLEW initiliazing -------------------------------------------------------
	const GLenum glew_status = glewInit();
	if (glew_status != GLEW_OK)
	{
		throw std::runtime_error(std::string(
			reinterpret_cast<const char*>(glewGetErrorString(glew_status))));
	}

	// Render initiazing -------------------------------------------------------
	_render->initRender();
}

Window::~Window(void) { }

void Window::runMainLoop(void)
{
	unsigned int curr_time = 0,
		last_time = 0;
	double delta_time = 0.0F;

	bool run = true;
	for (;run;)
	{
		last_time = curr_time; curr_time = SDL_GetTicks();
		delta_time = (curr_time - last_time) / 1000.0F;

		SDL_Event event;
		while (SDL_PollEvent(&event))
			if (event.type == SDL_QUIT || event.key.keysym.sym == SDLK_ESCAPE)
				run = false;

		_render->updateFrame(delta_time);
		_render->drawFrame();

		SDL_GL_SwapWindow(_window.get());
	}
}