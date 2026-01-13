#include "Arena.h"
#include <cstdlib>
#include <cassert>

Arena::Arena(U64 size) : 
    stackBase(static_cast<U8*>(malloc(size))),
    stackLocation(0),
    stackSize(size)

{
    assert(stackBase && "Arena malloc failed");
}

Arena::~Arena() {
    free(stackBase);
}

Arena::Push(U64 dataSize, U64 alignemnt = 8) {
    /*
        1. Ensure there is enough space
            - If there isn't, possibly grow the arena, I haven't decided
        2. Ensure the alignemnt is correct (Note: the stackLocation is the offset)
            - The stackLocation is the offset
            - 
    */
}