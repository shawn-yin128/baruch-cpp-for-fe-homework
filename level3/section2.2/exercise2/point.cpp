// implement the point class

#include <iostream>
#include <string>
#include <sstream>
#include <cmath>
#include "point.hpp"

using namespace std;

// constructor
Point::Point() {
}

// destructor
Point::~Point() {
}

// get functions
double Point::GetX() {
  return m_x;  
}

double Point::GetY() {
  return m_y;
}

// set functions
void Point::SetX(double x) {
  m_x = x;
}

void Point::SetY(double y) {
  m_y = y;
}

// to string
string Point::ToString() {
  stringstream stream;
  stream << "Point(" << m_x << ", " << m_y << ")";
  return stream.str();
}

// distance functions
double Point::DistanceOrigin() {
  return sqrt(pow(m_x, 2) + pow(m_y, 2));
}

double Point::Distance(Point p) {
  double x_dif, y_dif;
  x_dif = m_x - p.GetX();
  y_dif = m_y - p.GetY();
  return sqrt(pow(x_dif, 2) + pow(y_dif, 2));
}
