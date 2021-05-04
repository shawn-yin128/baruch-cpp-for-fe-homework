#ifndef Array_HPP
#define Array_HPP

#include <iostream>
#include <string>

using namespace std;

template <typename T> 
class Array {
	private:
		int m_size; // size of the array
		static int default_size; // default size of the array
		T* m_data; // data member

	public:
		// constructors
		Array();      // default constructor
		Array(int size); // constructor with a size argument
		Array(const Array<T>& arr); // copy constructor

		// destructor
		~Array();

		// accessing functions
		int Size() const; // return the size of the array
		static int DefaultSize(); // return the default size
		T& GetElement(int index) const; // return the element by reference

		// modifiers
		static void DefaultSize(int size); // set default size of the array
		void SetElement(int index, const T& pt); // set an element in the array

		// member operator overloading
		Array<T>& operator = (const Array<T>& source); // assignment operator
		T& operator [] (int index); // set for both reading and writing elements
		const T& operator [] (int index) const;			
};

#ifndef Array_CPP 
#include "array.cpp"
#endif

#endif 
