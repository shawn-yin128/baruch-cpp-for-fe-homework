// header file for point class

#ifndef _Point_HPP
#define _Point_HPP

#include <iostream>
#include <string>
using namespace std;

class Point {
  public:
    // constructor
    Point();
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
  private:
    double m_x;
    double m_y;
};

#endif
