#ifndef NumericArray_HPP
#define NumericArray_HPP

#include "array.hpp"
#include <iostream>

using namespace std;

template <typename T>
class NumericArray : public Array<T> {
	public:
		// constructors
		NumericArray(); // default constructor
		NumericArray(int size); // constructor with a size argument
		NumericArray(const NumericArray<T>& arr); // copy constructor

		// destructor
		~NumericArray();

		T DotProduct(const NumericArray<T>& source) const;

		// member operator overloading
		NumericArray<T>& operator = (const NumericArray<T>& source); // assignment operator
		NumericArray<T> operator * (T multiplier) const;
		NumericArray<T> operator + (const NumericArray<T>& source) const;
};

#ifndef NumericArray_CPP 
#include "numeric_array.cpp"
#endif

#endif 
