#ifndef SOLAS_ENGINE_SETTINGS_H
#define SOLAS_ENGINE_SETTINGS_H

#include <SDL.h>
#include <stdint.h>
#include <stdbool.h>

typedef struct SOLAS_EngineSettings {
	// Information
	const char* title;

	// Window Settings
	uint32_t windowWidth;
	uint32_t windowHeight;
	bool windowResizable;
	bool windowBorderless;
} SOLAS_EngineSettings;

#endif // !SOLAS_ENGINE_SETTINGS_H
