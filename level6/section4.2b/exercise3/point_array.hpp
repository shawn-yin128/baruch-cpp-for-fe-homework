#ifndef PointArray_HPP
#define PointArray_HPP

#include "point.hpp"
#include "array.hpp"

using namespace std;

class PointArray : public Array<Point> {
	public:
    // constructor
    PointArray(); // default constructor
    PointArray(int size); // constructor with input size
    PointArray(const PointArray& pa); // copy constructor
    // destructor
    ~PointArray();
    // assignment operator
    PointArray& operator = (const PointArray& pa);
    // length
    double Length() const;
};

#endif 
