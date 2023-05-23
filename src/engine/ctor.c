#include <stdlib.h>
#include "engine.h"
#include "../utility/utility.h"
#include "GLFW/glfw3.h"

#define SOLAS_SDL_INIT_FLAGS SDL_INIT_VIDEO		\
							| SDL_INIT_AUDIO	\
							| SDL_INIT_TIMER
#define SOLAS_DEFUALT_WINDOW_FLAGS SDL_WINDOW_ALLOW_HIGHDPI \
								 | SDL_WINDOW_OPENGL

SOLAS_Engine* SOLAS_CreateEngine(const SOLAS_EngineSettings* settings) {
	// Initialize SDL.
	int initCode = SDL_Init(SOLAS_SDL_INIT_FLAGS);
	if (initCode != 0) {
		const char* errorMessage = SOLAS_Format("SDL Initialization Error: %s", SDL_GetError());
		SDL_ClearError();
		SOLAS_ErrorMessage(errorMessage);
		SOLAS_FreeFormat(errorMessage);
		
		return NULL;
	}

	// Initialize GLFW
	if (!glfwInit())
		return NULL;

	SOLAS_Engine* engine = malloc(sizeof(SOLAS_Engine));
	if (!engine) {
		SOLAS_ErrorMessage("Could not initialize engine (out of memory).");
		return NULL;
	}

	engine->active = true;
	
	SDL_WindowFlags windowFlags = SOLAS_DEFUALT_WINDOW_FLAGS;

	if (settings->windowResizable) windowFlags |= SDL_WINDOW_RESIZABLE;
	if (settings->windowBorderless) windowFlags |= SDL_WINDOW_BORDERLESS;

	engine->window = SDL_CreateWindow(
		settings->title,
		SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
		settings->windowWidth, settings->windowHeight,
		windowFlags
	);
	if (!engine->window) {
		const char* errorMessage = SOLAS_Format("SDL Initialization Error: %s", SDL_GetError());
		SDL_ClearError();
		SOLAS_ErrorMessage(errorMessage);
		SOLAS_FreeFormat(errorMessage);

		free(engine);
		return NULL;
	}

	// OpenGL Setup
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 4);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 1);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);

	SDL_GL_SetAttribute(SDL_GL_RED_SIZE, 5);
	SDL_GL_SetAttribute(SDL_GL_GREEN_SIZE, 5);
	SDL_GL_SetAttribute(SDL_GL_BLUE_SIZE, 5);
	SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 16);
	SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);

	engine->glContext = SDL_GL_CreateContext(engine->window);
	if (!engine->glContext) {
		const char* errorMessage = SOLAS_Format("OpenGL Initialization Error: %s", SDL_GetError());
		SDL_ClearError();
		SOLAS_ErrorMessage(errorMessage);
		SOLAS_FreeFormat(errorMessage);

		free(engine);
		return NULL;
	}

	// Glad GL Loading
	gladLoadGL(SDL_GL_GetProcAddress);

	return engine;
}

void SOLAS_DestroyEngine(SOLAS_Engine* engine) {
	if (!engine) return;

	// SDL Cleanup
	SDL_DestroyWindow(engine->window);
	SDL_GL_DeleteContext(engine->glContext);
	SDL_Quit();

	// GLFW Cleanup
	glfwTerminate();

	free(engine);
}