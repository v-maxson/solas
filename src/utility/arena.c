#include "arena.h"

#include <stdlib.h>

SOLAS_Arena SOLAS_CreateArena(size_t size) {
	SOLAS_Arena arena = {
		.data = malloc(size),
		.offset = 0,
		.size = size
	};

	return arena;
}

void SOLAS_DestroyArena(SOLAS_Arena* arena) {
	if (!arena) return;
	if (arena->data) free(arena->data);
}

void* SOLAS_ArenaAlloc(SOLAS_Arena* arena, size_t size) {
	if ((arena->offset + size) > arena->size) return NULL;

	uint8_t* ptr = arena->data + arena->offset;
	arena->offset += size;

	return ptr;
}