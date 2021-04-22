// header file of shape class

#ifndef _Shape_HPP
#define _Shape_HPP

#include <iostream>

using namespace std;

class Shape {
    public:
        // constructor
        Shape(); // default constructor
        Shape(const Shape& shape); // copy constructor

        // destructor
        ~Shape(); // destructor

        // assignment operator
        Shape& operator = (const Shape& shape);

        // string operation
        string ToString() const;
        
        // accessor 
        int ID() const; // 
    private:
        int m_id;
};

#endif