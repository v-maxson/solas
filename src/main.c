#include "engine/engine.h"
#include "utility/utility.h"

int main(int argc, char* argv[]) {
	SOLAS_EngineSettings settings = {
		.title = "Solas",

		.windowWidth = 1280,
		.windowHeight = 720,
		.windowResizable = true,
		.windowBorderless = false
	};

	SOLAS_Engine* engine = SOLAS_CreateEngine(&settings);
	if (!engine) return 1;

	while (engine->active) {
		glViewport(0, 0, settings.windowWidth, settings.windowHeight);
		glClearColor(1.0f, 0.0f, 0.0f, 1.0f);
		glClear(GL_DEPTH_BUFFER_BIT | GL_COLOR_BUFFER_BIT);

		SDL_GL_SwapWindow(engine->window);

		SOLAS_ProcessEvents(engine);
	}

	SOLAS_DestroyEngine(engine);
	return 0;
}