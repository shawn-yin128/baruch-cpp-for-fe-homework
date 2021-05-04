#ifndef NumericArray_CPP
#define NumericArray_CPP

#include "NumericArray.hpp"
#include "ArrayException.hpp"
#include <iostream>

using namespace std;

template <typename T>
NumericArray<T>::NumericArray(): Array<T>() { // default constructor
}

template <typename T>
NumericArray<T>::NumericArray(int size) : Array<T>(size) { // constructor with a size argument
}

template <typename T>
NumericArray<T>::NumericArray(const NumericArray<T>& arr) : Array<T>(arr) { // copy constructor
}

template <typename T>
NumericArray<T>::~NumericArray() { // destructor
}

template <typename T>
T NumericArray<T>::DotProduct(const NumericArray<T>& source) const { // dot product
	if (this->Size() != source.Size()) {
		throw SizeMismatchException();
	}
	else {
		T sum = 0;
		for (int i = 0; i < this->Size(); i++) {
			sum = sum + (*this)[i] * source[i];
		}
		return sum;
	}
}

template <typename T>
NumericArray<T>& NumericArray<T>::operator = (const NumericArray<T>& source) {// assignment operator
	if (this == &source) {//preclude self-assignment
		return *this;
	}
	Array<T>::operator = (source);
	return *this;
}
		
template <typename T>
NumericArray<T> NumericArray<T>::operator * (T multiplier) const {
	NumericArray<T> arr(this->Size());
	for (int i = 0; i < this->Size(); i++) {
		arr[i] = (*this)[i] * multiplier;
	}
	return arr;
}

template <typename T>
NumericArray<T> NumericArray<T>::operator + (const NumericArray<T>& source) const {
	if (this->Size() != source.Size()) {
		throw SizeMismatchException();
	}
	else {
		NumericArray<T> arr(this->Size());
		for (int i = 0; i < this->Size(); i++) {
			arr[i] = (*this)[i] + source[i];
		}
		return arr;
	}
}

#endif
