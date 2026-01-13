# pragma once

#include <iostream>
using namespace std;

//Creating / destroying
Arena* ArenaAlloc(void);
void ArenaRelease(Arena* arena);

//Pushing to the stack
void* ArenaPush(Arena *arena, U64 size);
void* ArenaPushZero(Arena *arena, U64 size);

// Popping from the stack
void ArenaPop(Arena* arena, U64 size);

//Get the curr # of bytes allocated
U64 GetArenaLoc(Arena arena);