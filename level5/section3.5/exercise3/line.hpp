// line class header file

#ifndef _Line_HPP
#define _Line_HPP

#include <iostream>
#include <string>
#include "point.hpp"
#include "shape.hpp"

using namespace std;

class Line : public Shape {
  public:
    // constructor
    Line(); // default construstor
    Line(const Point &p_start, const Point &p_end); // constructor with value
    Line(const Line &l); // copy constructor

    // destructor
    virtual ~Line(); 

    // get functions
    const Point& P1() const; // get start point
    const Point& P2() const; // get end point
    
    // set functions
    void P1(const Point &p); // set start point
    void P2(const Point &p); // set end point

    // length
    double Length() const; // return the distance between start and end

    // to string
    string ToString() const; // return string of description of the line

    // operator
    Line& operator = (const Line& l); // assignment
    
    // ostream
    friend ostream& operator << (ostream& os, const Line& l); // send to ostream
  private:
    Point p1; // start point
    Point p2; // end point
};

#endif
