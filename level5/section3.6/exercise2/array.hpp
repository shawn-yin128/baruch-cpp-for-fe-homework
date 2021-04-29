// header file for array class

#ifndef _Array_HPP
#define _Array_HPP

#include "point.hpp"
using namespace std;

class Array {
    public:
        // constructor
        Array(); // default constructor
        Array(int size); // constructor with input array size
        Array(const Array& arr); // copy construtor

        // destructor
        ~Array();

        // operator overloading
        Array& operator = (const Array& arr); // assignment operator
        Point& operator [] (int idx); // get or assign point at certain index
        const Point& operator [] (int idx) const; // make sure that the object does not change and the return reference unchangeable

        // accessor
        int Size() const; // return the size of array
        Point& GetElement(int idx) const; // return the element at certain index

        // modifier
        void SetElement(int idx, const Point& p); // set point in certain index

    private:
        Point* m_data; // dynamic C array
        int m_size; // size of array
};

#endif