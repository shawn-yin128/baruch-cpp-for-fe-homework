// header file for circle class

#ifndef _Circle_HPP
#define _Circle_HPP

#include <iostream>
#include <string>
#include "point.hpp"

using namespace std;

namespace mynamespace {
  namespace CAD {  
    class Circle {
      public:
        // constructor
        Circle(); // default
        Circle(const Point &p, double radius); // constructor with input
        Circle(const Circle &cir); // copy consrtuctor

        // destructor
        ~Circle();

        // selector
        Point CentrePoint() const; // get the center point
        double Radius() const; // get the radius

        // modifier
        void CentrePoint(const Point &p); // reset the center
        void Radius(double radius); // reset radius

        // get other elements
        double Diameter() const; // get diameter
        double Area() const; // get area of circle
        double Circumference() const; // get the circumference

        // to string
        string ToString() const; // return string of description
        
        // assignment operator
        Circle& operator = (const Circle& c);
      private:
        Point m_center;
        double m_radius;
    };

    ostream& operator << (ostream& os, const Circle& c); // send to ostream
  }
}

#endif
