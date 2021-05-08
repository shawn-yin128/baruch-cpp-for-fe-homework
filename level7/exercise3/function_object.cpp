#ifndef FunctionObject_CPP
#define FunctionObject_CPP

#include "function_object.hpp"

// Constructors
template <typename T>
FunctionObject<T>::FunctionObject() { // Default constructor.
}

template <typename T>
FunctionObject<T>::FunctionObject(const T& t) : target(t) { // Constructor with the limit value as input.
}

template <typename T>
FunctionObject<T>::FunctionObject(const FunctionObject<T>& source) : target(source.target) { // Copy constructor.
}

template <typename T>
FunctionObject<T>::~FunctionObject() { // Destructor.
}

template <typename T>
FunctionObject<T>& FunctionObject<T>::operator = (const FunctionObject<T>& source) { // Assignment operator
	if (this == &source) {
		return *this;
	}
	this->target = source.target;
	return *this;
}

template <typename T>
bool FunctionObject<T>::operator () (const T& t) const { // () operator
	return t < this->target;
}

#endif