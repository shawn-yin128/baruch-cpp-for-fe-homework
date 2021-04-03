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
    double GetX();
    double GetY();
    // set functions
    void SetX(double x);
    void SetY(double y);
    // convert to string
    string ToString();
    // distance functions
    double DistanceOrigin();
    double Distance(Point p);
  private:
    double m_x;
    double m_y;
};

#endif
