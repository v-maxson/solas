#include "engine.h"

void SOLAS_ProcessEvents(SOLAS_Engine* engine) {
	SDL_Event event;
	while (SDL_PollEvent(&event)) {
		if (event.type == SDL_QUIT)
			engine->active = false;
	}
}