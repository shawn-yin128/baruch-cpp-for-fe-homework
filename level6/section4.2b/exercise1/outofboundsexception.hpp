#ifndef _OutOfBoundsException_HPP_
#define _OutOfBoundsException_HPP_

#include "arrayexception.hpp"
#include <sstream>
#include <iostream>

using namespace std;

class OutOfBoundsException : public ArrayException {
    private:
        int m_index;

    public:
        // Constructors and destructor
        OutOfBoundsException() { 
        }

        OutOfBoundsException(int index) {
            m_index = index;
        }

        virtual ~OutOfBoundsException() { 
        }

        string GetMessage() {
            stringstream stream;
            stream << "Index " << m_index << " is out of bound.";
            return stream.str();
        }
};

#endif