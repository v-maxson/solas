#ifndef SOLAS_ENGINE_H
#define SOLAS_ENGINE_H

#include <SDL.h>
#include <stdint.h>
#include <stdbool.h>
#include "engine_settings.h"

/// Defines an active engine state.  
typedef struct SOLAS_Engine {
	// SDL
	SDL_Window* window;
	SDL_GLContext glContext;

	// State
	bool active;
} SOLAS_Engine;

/// Create a SOLAS_Engine. Must be destroyed with SOLAS_DestroyEngine.
SOLAS_Engine* SOLAS_CreateEngine(const SOLAS_EngineSettings* settings);

/// Properly disposes of a SOLAS_Engine.
void SOLAS_DestroyEngine(SOLAS_Engine* engine);

/// Processes SOLAS_Engine events.
void SOLAS_ProcessEvents(SOLAS_Engine* engine);

#endif // !SOLAS_ENGINE_H
