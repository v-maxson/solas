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

	while (engine->active)
		SOLAS_ProcessEvents(engine);
	
	SOLAS_DestroyEngine(engine);
	return 0;
}