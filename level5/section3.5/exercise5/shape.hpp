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
        virtual string ToString() const;
        
        // accessor 
        int ID() const; // 

        // Draw function
        virtual void Draw() const = 0;

        // PRINT
        void Print() const;
    private:
        int m_id;
};

#endif