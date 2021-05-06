#ifndef Stack_CPP
#define Stack_CPP

#include "stack.hpp"
#include "stack_exception.hpp"
#include "array_exception.hpp"

using namespace std;

template <typename T, int size>
Stack<T, size>::Stack() : m_current(0), m_array(Array<T>(size)) {
}

/*
template <typename T, int size>
Stack<T>::Stack(int size) : m_current(0), m_array(Array<T>(size)) {
}
*/

template <typename T, int size>
Stack<T, size>::Stack(const Stack<T, size>& source) : m_current(source.m_current), m_array(source.m_array) {
}

template <typename T, int size>
Stack<T, size>::~Stack() {
}

template <typename T, int size>
Stack<T, size>& Stack<T, size>::operator = (const Stack<T, size>& source) {
    if (this == &source) {
        return *this;
    }
    else {
        m_current = source.m_current;
        m_array = source.m_array;
        return *this;
    }
}

template <typename T, int size>
void Stack<T, size>::Push(T& value) {
    try {
        m_array[m_current++] = value;
    }
    catch (ArrayException& ex) {
        throw StackFullException();
    }
}

template <typename T, int size>
T Stack<T, size>::Pop() {
    try {
        return m_array[--m_current];
    }
    catch (ArrayException& ex) {
        m_current = 0;
        throw StackEmptyException();
    }
}

#endif