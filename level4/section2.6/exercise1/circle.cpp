// implement circle class

// use namespace xxx {
//  namespace xx {
//  } 
// } instead of format in this cpp

#define _USE_MATH_DEFINES
#include <cmath>
#include <sstream>
#include "circle.hpp"
#include "point.hpp"

using namespace std;

    // constructrs
    mynamespace::CAD::Circle::Circle() {
    }

    mynamespace::CAD::Circle::Circle(const Point &p, double radius) {
      m_center = p;
      m_radius = radius;
    }

    mynamespace::CAD::Circle::Circle(const Circle &cir) {
      m_center = cir.m_center;
      m_radius = cir.m_radius;
    }

    // destructor
    mynamespace::CAD::Circle::~Circle() {
    }

    // selector
    mynamespace::CAD::Point mynamespace::CAD::Circle::CentrePoint() const {
      return m_center;
    }

    double mynamespace::CAD::Circle::Radius() const {
      return m_radius;
    }

    double mynamespace::CAD::Circle::Diameter() const {
      return 2.0 * m_radius;
    }

    double mynamespace::CAD::Circle::Area() const {
      return M_PI * pow(m_radius, 2);
    }

    double mynamespace::CAD::Circle::Circumference() const {
      return 2.0 * M_PI * m_radius;
    }

    // modifier
    void mynamespace::CAD::Circle::CentrePoint(const Point &p) {
      m_center = p;
    }

    void mynamespace::CAD::Circle::Radius(double radius) {
      m_radius = radius;
    }

    // to string
    string mynamespace::CAD::Circle::ToString() const {
      stringstream stream;
      stream << "The circle's center is at " << m_center.ToString() << " and the radius is " << m_radius;
      return stream.str();
    }

    // assignment operator
    mynamespace::CAD::Circle& mynamespace::CAD::Circle::operator = (const Circle& c) {
      if (this == &c) {
        return *this;
      }
      m_center = c.m_center;
      m_radius = c.m_radius;
      return *this;
    }

    ostream& mynamespace::CAD::operator << (ostream& os, const Circle& c) {
      os << c.ToString() << endl;
      return os;
    }