// header file for point class

#ifndef _Point_HPP
#define _Point_HPP

#include "shape.hpp"
#include <iostream>
#include <string>
#include <cmath>
using namespace std;

class Point : public Shape {
  public:
    // constructor
    Point();
    Point(const Point &p); // copy constructor, use const to make sure p is not changed
    Point(double x, double y); // constructor to set x y without using set function
    explicit Point(double num); // receive one number and set x and y both to be number; explicit will prevent implicitly conversion

    // destructor
    virtual ~Point();

    // get functions
    double X() const;
    double Y() const;
    
    // set functions
    inline void X(double x) {m_x = x;}
    inline void Y(double y) {m_y = y;}
    
    // convert to string
    string ToString() const;
    
    // distance functions
    double Distance() const;
    double Distance(const Point& p) const;
    
    // operators overload
    Point operator - () const; // negate the coordinates
    Point operator * (double factor) const; // scale the coordinates
    Point operator + (const Point& p) const; // add coordinates
    bool operator == (const Point& p) const; // compare coordinates
    Point& operator = (const Point& p); // assignment operator
    Point& operator *= (double factor); // scale the coordinates and assign
  // ostream
    friend ostream& operator << (ostream& os, const Point& p); // send to ostream

  // draw
    void Draw() const;
  private:
    double m_x;
    double m_y;
};

inline double Point::X() const {return m_x;}
inline double Point::Y() const {return m_y;}

#endif
