# pragma once 

# include <stdexcept>
using namespace std;

template <class T> 
class VectorT
{
    private:
        //Data
        size_t capacity = 0;
        size_t size = 0;
        T* buffer = nullptr;

        static T* allocate(size_t nSize) {
            return (T*)operator new(sizeof(T) * nSize);
        }

        void deallocate() {
            operator delete(buffer);
        } 

        void EnsureCapacity() {
            if(size < capacity) return;
            size_t newCapacity = (capacity == 0) ? 1 : capacity * 2;
            GrowBuffer(newCapacity);
        }

        void GrowBuffer(size_t newCapacity) {
            T* newBuffer = allocate(newCapacity);

            size_t i = 0;
            try {
                for(; i < size; i++) {
                    new (&newBuffer[i]) T(buffer[i]);
                }
            } catch (...) {
                for(size_t j = 0; j < i; j++) 
                    newBuffer[j].~T();

                operator delete(newBuffer);
                throw;
            }

            for(size_t i = 0; i < size; i++) {
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
        VectorT(size_t capacity) {
            // Sets capacity and allocates space for elements 
            this->capacity = capacity;
            buffer = allocate(capacity);
        }

        ~VectorT() {
            Clear();
            deallocate();
        }

        size_t GetCapacity() {
            return capacity;
        }

        size_t GetSize() {
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

        void Insert(const T& value, size_t index) {
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

        void Remove(size_t index) {
            T* newBuffer = allocate(size - 1);

            size_t newBufLoc = 0;
            try {
                for(size_t i = 0; i < size; i++) {
                    if(i == index) continue;

                    new (&newBuffer[newBufLoc]) T(buffer[i]);
                    newBufLoc++;
                }
            } catch (...) {
                for(size_t j = 0; j < newBufLoc; j++)
                    newBuffer[j].~T();

                operator delete(newBuffer);
                throw;
            }


            for(size_t i = 0; i < size; i++) {
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
        T At(size_t index) {
            if(index >= size) throw out_of_range("VectorT::At");
            return buffer[index];
        }

        void Clear() {
            for(size_t i = 0; i < size; i++)
                buffer[i].~T();
            size = 0;
        }

        void Reserve(size_t newCapacity) {
            if(capacity >= newCapacity) return;
            GrowBuffer(newCapacity);
        }
};