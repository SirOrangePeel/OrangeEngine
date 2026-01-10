# pragma once 

# include <iostream>
using namespace std;

template <class T> 
class VectorT
{
    private:
        //Data
        std::size_t capacity = 0;
        std::size_t size = 0;
        T* buffer = nullptr;

        static T* allocate(std::size_t nSize) {
            return (T*)operator new(sizeof(T) * nSize);
        }

        void deallocate() {
            operator delete(buffer);
        } 

        void EnsureCapacity() {
            if(size < capacity) return;
            std::size_t newCapacity = capacity + 1;
            GrowBuffer(newCapacity);
        }

        void GrowBuffer(std::size_t newCapacity) {
            T* newBuffer = allocate(newCapacity);

            std::size_t i = 0;
            try {
                for(; i < size; i++)
                    new (&newBuffer[i]) T(buffer[i]);
            } catch (...) {
                for(std::size_t j; j < i; j++) 
                    newBuffer[j].~T();

                operator delete(newBuffer);
                throw;
            }

            for(std::size_t i = 0; i < size; i++) {
                buffer[i].~T();
            }
            operator delete(buffer);

            buffer = newBuffer;
            capacity = newCapacity;
        }

    public:
        // Default contructor
        VectorT() = default;

        // Constructor with capacity
        VectorT(std::size_t capacity) {
            // Sets capacity and allocates space for elements 
            this->capacity = capacity;
            buffer = allocate(capacity);
        }

        ~VectorT() {
            Clear();
            deallocate();
        }

        std::size_t GetCapacity() {
            return capacity;
        }

        std::size_t GetSize() {
            return size;
        }

        /**
         * @brief Adds new Element to the vector
         * 
         * @param value The value of the new element to be added to the vector
         */
        void PushBack(const T& value) {
            EnsureCapacity();
            new (&buffer[size]) T(value);
            size++;
        }

        /**
         * @brief Removes the last value of the vector
         * 
         */
        void PopBack() {
            buffer[size].~T();
            size--;
        }

        /**
         * @brief Returns the value of the element from the buffer at the specified index
         * 
         * @param index The desired index of the value
         * @return T A template to allow returns from any class
         */
        T At(int index) {
            return buffer[index];
        }

        void Clear() {
            for(std::size_t i = 0; i < size; i++)
                buffer[i].~T();
            size = 0;
        }

        void Reserve(std::size_t newCapacity) {
            if(capacity >= newCapacity) return;
            GrowBuffer(newCapacity);
        }
};