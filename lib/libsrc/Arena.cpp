# pragma once

#include <iostream>
using namespace std;

class Arena {
    private:
        /* Uses default values for the arena
        problem is idk what the default values should be if any.
        Maybe the best way to do it is have an size inital size, but then
        the user needs to determine what that initial size is. */
        U8* stackBase = nullptr;
        U64 stackLocation = 0;
        U64 size = 0;

    public:
        Arena() = default;

        /* Do I want to define an original size? also how do I know how large to make it?
        Ok so it can be defined either w/ or w/o size. Not very safe to do it w/o size tho
        */
        explicit Arena(U64 size) :
            stackBase(static_cast<U8*>(std::malloc(static_cast<std::size_t>(size)))),
            stackLocation(0),
            size()
        {
            assert(stackBase && "Arena malloc failed");
        }

        ~Arena() { 
            free(stackBase);
        }

        /* Possible methods */
        void* push(U64 dataSize, int alignment = 8) {
            /*
            Treats stackLocation as used offset with clear invariants

            Computes padding to reach alignment (not “make modulo 0”)

            Validates alignment (positive, power-of-two)

            Checks capacity using used + padding + request

            Returns raw storage (caller writes the data)

            Has a defined failure behavior

            Has a plan for rewind/reset semantics under alignment padding
            */

        }

        template <typename T> T* pushArray();
        void Rewind();
        void Reset();
        U64 Remaining();
};