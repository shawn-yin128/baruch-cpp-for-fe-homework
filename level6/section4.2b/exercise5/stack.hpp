#ifndef Stack_HPP
#define Stack_HPP

#include "array.hpp"

using namespace std;

template <typename T>
class Stack {
    private:
        int m_current;
        Array<T> m_array;

    public:
        // constructor 
        Stack(); // default
        Stack(int size); // input stack size
        Stack(const Stack& source); // copy constructor

        // assignment operator
        Stack& operator = (const Stack& source);
        
        // destructor
        ~Stack();

        // Push
        void Push(T& value); 

        // Pop
        T Pop();
};

#ifndef Stack_CPP
#include "stack.cpp"
#endif

#endif