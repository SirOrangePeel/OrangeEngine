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

        int hasCapacity() {
            try {
                if (capacity == size) throw (100); 
                return 1;
            } catch (int errorCode) {
                cout << "Error Code " << errorCode << ": Vector is at capacity" << endl;
                return 0;
            }
        }
        

    public:
        // Default contructor
        VectorT() = default;

        // Constructor with capacity
        VectorT(std::size_t capacity) {
            // Sets capacity and allocates space for elements 
            this->capacity = capacity;
            buffer = (T*)operator new(sizeof(T) * capacity);
        }

        ~VectorT() {
            // Deallocates the memory, Using operator delete instead of delete because of operator new
            for(std::size_t i = 0; i < size; i++) {
                buffer[i].~T();
            }

            operator delete(buffer);
        }

        /**
         * @brief Adds new Element to the vector
         * 
         * @param value The value of the new element to be added to the vector
         */
        void push_back(const T& value) {
            if(hasCapacity()) {
                new (&buffer[size]) T(value);
                ++size;
            }
        }

        /**
         * @brief Removes the last value of the vector
         * 
         */
        void pop() {
            buffer[size].~T();
            --size;
        }

        /**
         * @brief Returns the value of the element from the buffer at the specified index
         * 
         * @param index The desired index of the value
         * @return T A template to allow returns from any class
         */
        T get(int index) {
            return buffer[index];
        }

        std::size_t get_capacity() {
            return capacity;
        }

        std::size_t get_size() {
            return size;
        }
};