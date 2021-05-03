#ifndef _Array_Exception_HPP_
#define _Array_Exception_HPP_

#include <iostream>

using namespace std;

class ArrayException {
    public:
        ArrayException() {
        };
        virtual ~ArrayException() {
        };
        virtual string GetMessage() = 0;
};

#endif