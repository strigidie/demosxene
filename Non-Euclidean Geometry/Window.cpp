#include "Window.hpp"

Window::Window(const RenderShPtr& render) :
	_render(render),
	_width(render->getWidth()),
	_height(render->getHeight())
{
	// SDL initiliazing --------------------------------------------------------
	SDL_SetMainReady();
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
		throw std::runtime_error("Error: SDL_Init(): " +
			std::string(SDL_GetError()));
	atexit(SDL_Quit);

	// Window initiliazing -----------------------------------------------------
	_window = std::shared_ptr<SDL_Window>(
		SDL_CreateWindow(
			M_WINDOW_NAME,
			SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
			_width, _height,
			SDL_WINDOW_SHOWN | SDL_WINDOW_OPENGL
		),
		SDL_DestroyWindow
	);

	if (!_window)
		throw std::runtime_error("Error: SDL_CreateWindow(): " +
			std::string(SDL_GetError()));

	// OpenGL4.1 context initiliazing ------------------------------------------
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 4);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 1);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK,
		SDL_GL_CONTEXT_PROFILE_CORE);
	SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
	SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 24);

	_context = std::shared_ptr<void>(
		SDL_GL_CreateContext(_window.get()),
		SDL_GL_DeleteContext
	);

	if (!_context)
		throw std::runtime_error("Error: SDL_GL_CreateContext()" +
			std::string(SDL_GetError()));

	SDL_GL_MakeCurrent(_window.get(), _context.get());
	SDL_GL_SetSwapInterval(1);

	// GLEW initiliazing -------------------------------------------------------
	if (glewInit() != GLEW_OK)
		throw std::runtime_error("Error: glewInit()");
}

Window::~Window(void) { }

void Window::runMainLoop(void)
{
	unsigned int currTime = 0,
		lastTime = 0;
	double deltaTime = 0.0F;

	bool run = true;
	for (;run;)
	{
		lastTime = currTime; currTime = SDL_GetTicks();
		deltaTime = (currTime - lastTime) / 1000.0F;

		SDL_Event event;
		while (SDL_PollEvent(&event))
			if (event.type == SDL_QUIT || event.key.keysym.sym == SDLK_ESCAPE)
				run = false;

		glClearColor(0.9f, 0.9f, 0.95f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		_render->updateFrame(deltaTime);
		_render->drawFrame();

		SDL_GL_SwapWindow(_window.get());
	}
}