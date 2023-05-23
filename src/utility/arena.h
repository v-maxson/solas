#ifndef SOLAS_ARENA_H
#define SOLAS_ARENA_H

#include <stdint.h>

typedef struct SOLAS_Arena {
	uint8_t* data;
	size_t offset;
	size_t size;
} SOLAS_Arena;

/// Creates and initializes a SOLAS_Arena with the given size.
SOLAS_Arena SOLAS_CreateArena(size_t size);

/// Destroys a given SOLAS_Arena.
void SOLAS_DestroyArena(SOLAS_Arena* arena);

/// Allocates data in a SOLAS_Arena and returns a pointer to it, or NULL if allocation failed.
void* SOLAS_ArenaAlloc(SOLAS_Arena* arena, size_t size);

#endif // !SOLAS_ARENA_H
