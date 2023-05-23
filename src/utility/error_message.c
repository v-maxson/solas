#include "utility.h"

#include <SDL.h>

void SOLAS_ErrorMessage(const char* message) {
	SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR, "Solas Error", message, NULL);
}