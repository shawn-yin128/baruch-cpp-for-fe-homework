// implement circle class

#define _USE_MATH_DEFINES
#include <cmath>
#include <sstream>
#include "circle.hpp"
#include "point.hpp"

using namespace std;

// constructrs
Circle::Circle() {
}

Circle::Circle(const Point &p, double radius) {
 m_center = p;
 m_radius = radius;
}

Circle::Circle(const Circle &cir) {
  m_center = cir.m_center;
  m_radius = cir.m_radius;
}

// destructor
Circle::~Circle() {
}

// selector
Point Circle::CentrePoint() const {
  return m_center;
}

double Circle::Radius() const {
  return m_radius;
}

double Circle::Diameter() const {
  return 2.0 * m_radius;
}

double Circle::Area() const {
  return M_PI * pow(m_radius, 2);
}

double Circle::Circumference() const {
  return 2.0 * M_PI * m_radius;
}

// modifier
void Circle::CentrePoint(const Point &p) {
  m_center = p;
}

void Circle::Radius(double radius) {
  m_radius = radius;
}

// to string
string Circle::ToString() const {
  stringstream stream;
  stream << "The circle's center is at " << m_center.ToString() << " and the radius is " << m_radius;
  return stream.str();
}
