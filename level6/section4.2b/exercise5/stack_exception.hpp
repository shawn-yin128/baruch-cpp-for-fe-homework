#ifndef StackException_HPP
#define StackException_HPP

#include <iostream>
#include <sstream>
#include <string>

using namespace std;

class StackException {//  ArrayException base class
	public:
		virtual string GetMessage() const = 0; // an abstract GetMessage() function
};

class StackFullException : public StackException {// OutOfBoundsException derived class
	public:	
		StackFullException() : StackException() {
		} // default constructor
		virtual ~StackFullException() {
		} // destructor	
		string GetMessage() const {
			stringstream my_sstream;
			my_sstream << "Stack is full." <<endl;
			return my_sstream.str();
		}
};

class StackEmptyException : public StackException {// OutOfBoundsException derived class
	public:	
		StackEmptyException() : StackException() {
		} // default constructor
		virtual ~StackEmptyException() {
		} // destructor	
		string GetMessage() const {
			stringstream my_sstream;
			my_sstream << "Stack is empty." <<endl;
			return my_sstream.str();
		}
};

#endif
