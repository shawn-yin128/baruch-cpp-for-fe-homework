// header file for point class

#ifndef _Point_HPP
#define _Point_HPP

#include <iostream>
#include <string>
#include <cmath>
using namespace std;

class Point {
  public:
    // constructor
    Point();
    Point(const Point &p); // copy constructor, use const to make sure p is not changed
    Point(double x, double y); // constructor to set x y without using set function
    // destructor
    ~Point();
    // get functions
    double X() const;
    double Y() const;
    // set functions
    void X(double x);
    void Y(double y);
    // convert to string
    string ToString() const;
    // distance functions
    double Distance() const;
    double Distance(const Point& p) const;
  private:
    double m_x;
    double m_y;
};

#endif
