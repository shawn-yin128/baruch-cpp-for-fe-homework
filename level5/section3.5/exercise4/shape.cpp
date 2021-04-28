// source file of shape class 

#include "shape.hpp"
#include <iostream>
#include <stdlib.h>
#include <sstream>

using namespace std;

// constructor
Shape::Shape() : m_id(rand()) {
}

Shape::Shape(const Shape& shape) : m_id(shape.m_id) {
}

// destructor
Shape::~Shape() {
}

// assignment operator
Shape& Shape::operator = (const Shape& shape) {
    if (this == &shape) {
        return *this;
    }
    else {
        m_id = shape.m_id;
    }
    return *this;
}

// string
string Shape::ToString() const {
    stringstream stream;
    stream << "ID is " << m_id;
    return stream.str();
}

// accessor
int Shape::ID() const {
    return m_id;
}
