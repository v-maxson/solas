#include "engine/engine.h"
#include "utility/utility.h"

int main(int argv, const char* argc[]) {
	SOLAS_EngineSettings settings = {
		.title = "Solas",

		.windowWidth = 1280,
		.windowHeight = 720,
		.windowResizable = true,
		.windowBorderless = false
	};

	SOLAS_Engine* engine = SOLAS_CreateEngine(&settings);
	if (!engine) return 1;

	bool running = true;
	while (running) {
		SDL_Event event;
		while (SDL_PollEvent(&event)) {
			if (event.type == SDL_QUIT)
				running = false;
		}
	}

	SOLAS_DestroyEngine(&engine);
	return 0;
}