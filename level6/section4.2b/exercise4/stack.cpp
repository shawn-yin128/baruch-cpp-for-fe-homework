#ifndef Stack_CPP
#define Stack_CPP

#include "stack.hpp"

using namespace std;

template <typename T>
Stack<T>::Stack() : m_current(0), m_array(Array<T>()) {
}

template <typename T>
Stack<T>::Stack(int size) : m_current(0), m_array(Array<T>(size)) {
}

template <typename T>
Stack<T>::Stack(const Stack& source) : m_current(source.m_current), m_array(source.m_array) {
}

template <typename T>
Stack<T>::~Stack() {
}

template <typename T>
Stack<T>& Stack<T>::operator = (const Stack<T>& source) {
    if (this == &source) {
        return *this;
    }
    else {
        m_current = source.m_current;
        m_array = source.m_array;
        return *this;
    }
}

template <typename T>
void Stack<T>::Push(T& value) {
    m_array[m_current++] = value;
}

template <typename T>
T Stack<T>::Pop() {
    return m_array[--m_current];
}

#endif