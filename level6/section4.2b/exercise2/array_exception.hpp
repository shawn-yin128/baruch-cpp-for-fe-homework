#ifndef ArrayException_HPP
#define ArrayException_HPP

#include <iostream>
#include <sstream>
#include <string>

using namespace std;

class ArrayException {//  ArrayException base class
	public:
		virtual string GetMessage() const = 0; // an abstract GetMessage() function
};


class OutOfBoundsException : public ArrayException {// OutOfBoundsException derived class
	private:
		int m_index;
	public:	
		OutOfBoundsException() : m_index(0), ArrayException() {
		} // default constructor
		OutOfBoundsException(int idx) : m_index(idx) {
		} // constructor with index
		virtual ~OutOfBoundsException() {
		} // destructor	
		string GetMessage() const {
			stringstream my_sstream;
			my_sstream << "Index " << m_index << " is out of bounds." <<endl;
			return my_sstream.str();
		}
};


class SizeMismatchException : public ArrayException {// SizeMismatchException derived class
	public:	
		SizeMismatchException() : ArrayException() {
		} // default constructor	
		virtual ~SizeMismatchException() {
		} // destructor	
		string GetMessage() const {
			stringstream my_sstream;
			my_sstream << "Array size mismatch." << endl;
			return my_sstream.str();
		}
};

#endif
