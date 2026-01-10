# pragma once 

# include <iostream>
# include <stdexcept>
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
            std::size_t newCapacity = (capacity == 0) ? 1 : capacity * 2;
            GrowBuffer(newCapacity);
        }

        void GrowBuffer(std::size_t newCapacity) {
            T* newBuffer = allocate(newCapacity);

            std::size_t i = 0;
            try {
                for(; i < size; i++) {
                    new (&newBuffer[i]) T(buffer[i]);
                }
            } catch (...) {
                for(std::size_t j = 0; j < i; j++) 
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

        void Push(const T& value, std::size_t index) {
            if(index > size)
                index = size;
            new (&buffer[index]) T(value);
        }

        /**
         * @brief Removes the last value of the vector
         * 
         */
        void PopBack() {
            if (size == 0) return;
            buffer[size - 1].~T();
            size--;
        }

        void Remove(std::size_t index) {
            T* newBuffer = allocate(size - 1);

            std::size_t  newBufLoc = 0;
            try {
                for(std::size_t i = 0; i < size; i++) {
                    if(i == index) continue;

                    new (&buffer[newBufLoc]) T(buffer[i]);
                    newBufLoc++;
                }

            } catch (...) {
                for(std::size_t j = 0; j < newBufLoc; j++)
                    newBuffer[j].~T();

                operator delete(newBuffer);
                throw;
            }

            for(std::size_t i = 0; i < size; i++) {
                buffer[i].~T();
            }
            operator delete(buffer);

            buffer = newBuffer;
            capacity--;
            size--;
        }

        /**
         * @brief Returns the value of the element from the buffer at the specified index
         * 
         * @param index The desired index of the value
         * @return T A template to allow returns from any class
         */
        T At(std::size_t index) {
            if(index >= size) throw std::out_of_range("VectorT::At");
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