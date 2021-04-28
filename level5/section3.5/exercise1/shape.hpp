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
        virtual ~Shape(); // use virtual, without virtual, delete bass pointer will not delete a derived object

        // assignment operator
        Shape& operator = (const Shape& shape);

        // string operation
        virtual string ToString() const; // make this a virtual function
        
        // accessor 
        int ID() const; // 
    private:
        int m_id;
};

#endif