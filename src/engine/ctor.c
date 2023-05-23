#include "engine.h"
#include "../utility/utility.h"
#include <stdlib.h>

#define SOLAS_SDL_INIT_FLAGS SDL_INIT_VIDEO		\
							| SDL_INIT_AUDIO	\
							| SDL_INIT_TIMER
#define SOLAS_DEFUALT_WINDOW_FLAGS SDL_WINDOW_ALLOW_HIGHDPI

SOLAS_Engine* SOLAS_CreateEngine(const SOLAS_EngineSettings* settings) {
	// Initialize SDL.
	int initCode = SDL_Init(SOLAS_SDL_INIT_FLAGS);
	if (initCode != 0) {
		const char* errorMessage = SOLAS_Format("SDL Initialization Error: %s", SDL_GetError());
		SOLAS_ErrorMessage(errorMessage);
		SOLAS_FreeFormat(errorMessage);
		
		return NULL;
	}

	SOLAS_Engine* engine = malloc(sizeof(SOLAS_Engine));
	if (!engine) SOLAS_ErrorMessage("Could not initialize engine (out of memory).");
	
	SDL_WindowFlags windowFlags = SOLAS_DEFUALT_WINDOW_FLAGS;

	if (settings->windowResizable) windowFlags |= SDL_WINDOW_RESIZABLE;
	if (settings->windowBorderless) windowFlags |= SDL_WINDOW_BORDERLESS;

	engine->window = SDL_CreateWindow(
		settings->title,
		SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
		settings->windowWidth, settings->windowHeight,
		windowFlags
	);

	return engine;
}

void SOLAS_DestroyEngine(SOLAS_Engine* engine) {
	if (!engine) return;

	// SDL Cleanup
	SDL_DestroyWindow(engine->window);
	SDL_DestroyRenderer(engine->renderer);
	SDL_Quit();

	free(engine);
}