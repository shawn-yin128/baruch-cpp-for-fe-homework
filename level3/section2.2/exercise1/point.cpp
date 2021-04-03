// implement the point class

#include <iostream>
#include <string>
#include <sstream>
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
