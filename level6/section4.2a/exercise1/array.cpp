// source file of array class

#include "array.hpp"
#include "outofboundsexception.hpp"
#include <iostream>

using namespace std;

// constructor
template <class T>
Array<T>::Array() : m_data(new T[10]), m_size(10) { // default to create an array with 10 point
}

template <class T>
Array<T>::Array(int size) : m_data(new T[size]), m_size(size) {
}

template <class T>
Array<T>::Array(const Array<T>& arr) : m_data(new T[arr.m_size]), m_size(arr.m_size) {
    for (int i = 0; i < m_size; i++) {
        m_data[i] = arr.m_data[i];
    }
}

// destructor
template <class T>
Array<T>::~Array() {
    delete[] m_data;
}

// operator overloading
template <class T>
Array<T>& Array<T>::operator = (const Array<T>& arr) {
    if (this == &arr) {
        return *this;
    }
    delete[] m_data; // delete original object at first

    m_data = new T[arr.m_size];
    m_size = arr.m_size;
    for (int i = 0; i < m_size; i++) {
        m_data[i] = arr.m_data[i];
    }
    return *this;
}

template <class T>
T& Array<T>::operator [] (int idx) {
    if (idx >= m_size | idx < 0) {
        throw OutOfBoundsException(idx);
    }
    return m_data[idx];
}

template <class T>
const T& Array<T>::operator [] (int idx) const {
    if (idx >= m_size | idx < 0) {
        throw OutOfBoundsException(idx);
    }
    return m_data[idx];
}

// accessor
template <class T>
int Array<T>::Size() const {
        return m_size;
}

template <class T>
T& Array<T>::GetElement(int idx) const {
    if (idx >= m_size | idx < 0) {
        throw OutOfBoundsException(idx);
    }
    return m_data[idx];
}

// modifier
template <class T>
void Array<T>::SetElement(int idx, const T& p) {
    if (idx >= m_size | idx < 0) {
        throw OutOfBoundsException(idx);
    }
    m_data[idx] = p;
}