// implement the point class

#include <iostream>
#include <sstream>
#include <string>
#include "point.hpp"

using namespace std;

    // constructor
    mynamespace::CAD::Point::Point() {
    }

    mynamespace::CAD::Point::Point(const Point &p) {
      m_x = p.m_x;
      m_y = p.m_y;
    }

    mynamespace::CAD::Point::Point(double x, double y) {
      m_x = x;
      m_y = y;
    }

    mynamespace::CAD::Point::Point(double num) { // do not need to use explit here
      m_x = num;
      m_y = num;
    }

    // destructor
    mynamespace::CAD::Point::~Point() {
    }

    // to string
    string mynamespace::CAD::Point::ToString() const {
      stringstream stream;
      stream << "Point(" << m_x << ", " << m_y << ")";
      return stream.str();
    }

    // distance functions
    // distance with origin
    double mynamespace::CAD::Point::Distance() const {
      return sqrt(pow(m_x, 2) + pow(m_y, 2));
    }

    // distance with other point
    double mynamespace::CAD::Point::Distance(const Point& p) const {
      double x_dif, y_dif;
      x_dif = m_x - p.m_x;
      y_dif = m_y - p.m_y;
      return sqrt(pow(x_dif, 2) + pow(y_dif, 2));
    }

    // operators overload
    mynamespace::CAD::Point mynamespace::CAD::Point::operator - () const { // negate the coordinates
      return Point(- m_x, - m_y);
    }

    mynamespace::CAD::Point mynamespace::CAD::Point::operator * (double factor) const { // scale the coordinates
      return Point(m_x * factor, m_y * factor);
    }

    mynamespace::CAD::Point mynamespace::CAD::Point::operator + (const Point& p) const { // add coordinates
      return Point(m_x + p.m_x, m_y + p.m_y);
    }

    bool mynamespace::CAD::Point::operator == (const Point& p) const { // compare coordinates
      if (m_x == p.m_x && m_y == p.m_y) {
        return true;
      }
      else {
        return false;
      }
    }

    mynamespace::CAD::Point& mynamespace::CAD::Point::operator = (const Point& p) { // assignment operator
      m_x = p.m_x;
      m_y = p.m_y;
      return *this;
    }

    mynamespace::CAD::Point& mynamespace::CAD::Point::operator*= (double factor) { // scale the coordinates and assign
      m_x *= factor;
      m_y *= factor;
      return *this;
    }

    ostream& mynamespace::CAD::operator << (ostream& os, const mynamespace::CAD::Point& p) {
      os <<  "Point (" << p.m_x << ", " << p.m_y << ")";
      return os;
    }