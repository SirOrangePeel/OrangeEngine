# include "Arena.h"
# include <cstdlib>
# include <cassert>
# include <iostream>

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

        2. Ensure the alignemnt is correct, and is a power of 2
            - alignment % 2 == 0 && (stackBase + stackLocation) % alignment == 0
                - If it isn't, we need to add padding so that it is:
                    -  If % returns the remainder, then we can take that value and 
                        add it to the offset, then it should be aligned.

        3. Return the address that we can then store to.

        Note: There is an argument for added the storing logic here, but then it would have to 
        be a template. I think the best way to handle it would be to return the pointer, and then 
        the user will use that pointer to save what is needed
    */
}

Arena::EnsureSpace(U64 spaceNeeded) {
    if(sapceNeeded > (size - stackLocation)) {
        cout << "More Space is needed" << endl;
    }
}