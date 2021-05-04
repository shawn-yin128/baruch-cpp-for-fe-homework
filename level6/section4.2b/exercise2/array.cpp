#ifndef Array_CPP
#define Array_CPP

#include "array.hpp"
#include "ArrayException.hpp"
#include <sstream>
#include <cmath>
#include <iostream>

using namespace std;

template <typename T>
int Array<T>::default_size = 10;

template <typename T>
Array<T>::Array() : m_size(default_size), m_data(new T[default_size]) { // default constructor
}

template <typename T>
Array<T>::Array(int size) : m_size(size), m_data(new T[size]) { // constructor with a size argument						
}

template <typename T>
Array<T>::Array(const Array<T>& arr) : m_size(arr.m_size), m_data(new T[arr.m_size]) { // copy constructor			
	for (int i = 0; i < m_size; i++) {
		m_data[i] = arr.m_data[i];
	}
}

template <typename T>
Array<T>::~Array() {// destructor, delete memory
	delete[] m_data;
}

template <typename T>
int Array<T>::Size() const {// size of the array
	return m_size;
}

template <typename T>
int Array<T>::DefaultSize() {// default size of the array
	return default_size;
}

template <typename T>
T& Array<T>::GetElement(int index) const {// return the element by reference
	if (index > (m_size - 1) || index < 0) {
		throw OutOfBoundsException(index);
	}
	else {
		return m_data[index];
	}
}

template <typename T>
void Array<T>::DefaultSize(int size) {// set default size of the array
	default_size = size;
}

template <typename T>
void Array<T>::SetElement(int index, const T& pt) {// set an element in the array
	if (index > (m_size - 1) || index < 0) {
		throw OutOfBoundsException(index);
	}
	else {
		m_data[index] = pt;
	}
}

template <typename T>
Array<T>& Array<T>::operator = (const Array<T>& source) {// assignment operator
	if (this == &source) {//preclude self-assignment
		return *this;
	}
	m_size = source.m_size;
	delete[] m_data;
	m_data = new T[m_size];
	for (int i = 0; i < m_size; i++) {
		m_data[i] = source.m_data[i];
	}
	return *this;
}

template <typename T>
T& Array<T>::operator [] (int index) {// used for both reading and writing elements
	if (index > (m_size - 1) || index < 0) {
		throw OutOfBoundsException(index);
	}
	else {
		return m_data[index];
	}
}

template <typename T>
const T& Array<T>::operator [] (int index) const {// used for both reading and writing elements
	if (index > (m_size - 1) || index < 0) {
		throw OutOfBoundsException(index);
	}
	else {
		return m_data[index];
	}
}

#endif
