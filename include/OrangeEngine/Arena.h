# pragma once
# include <cstdint>

using U8 = std::uint8_t;
using U64 = std::uint64_t;

class Arena {

    private:
        U8* stackBase;
        U64 stackLocation;
        U64 stackSize;

    public:
        //Full implementations
        template<typename T>
        T* PushArray(U64 arrSize) {
            return static_cast<T*>(push(sizeof(T) * arrSize, alignof(T)));
        }

        //Prototypes
        explicit Arena(U64 newStackSize);

        ~Arena();

        void* Push(U64 dataSize, U64 alignment = 8);

        void HardReset();
        void Rewind(U64 resetLocation);
        U64 MarkLocation() const;
};