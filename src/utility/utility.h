#ifndef SOLAS_UTILITY_H
#define SOLAS_UTILITY_H

#include "arena.h"
#include <stdint.h>
#include <stdbool.h>

/// Formats a string, returns NULL if allocation failed. Returned String must be freed with SOLAS_FreeFormat.
const char* SOLAS_Format(const char* fmt, ...);

/// Frees a string formatted with SOLAS_Format.
void SOLAS_FreeFormat(const char* str);

/// Serves an error popup.
#define SOLAS_ErrorMessage(message) SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR, "Solas Error", message, NULL);

#endif // !SOLAS_UTILITY_H
