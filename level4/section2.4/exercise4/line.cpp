// implement of line class

#include <iostream>
#include <string>
#include <sstream>
#include "line.hpp"
#include "point.hpp"

using namespace std;

// constructor
Line::Line() {
}

Line::Line(const Point &p_start, const Point &p_end) {
  p1 = p_start;
  p2 = p_end;
}

Line::Line(const Line &l) {
  p1 = l.p1;
  p2 = l.p2;
}

// destructor
Line::~Line() {
}

// get functions
const Point& Line::P1() const {
  return p1;
}

const Point& Line::P2() const {
  return p2;
}

// set functions
void Line::P1(const Point &p) {
  p1 = p;
}

void Line::P2(const Point &p) {
  p2 = p;
}

// length
double Line::Length() const {
  return p1.Distance(p2);
}

// To string
string Line::ToString() const {
  stringstream stream;
  stream << "Line starts at " << p1.ToString() << " and end at " << p2.ToString() << ".\n";
  return stream.str();
}

// assignment operator
Line& Line::operator = (const Line& l) {
  p1 = l.p1;
  p2 = l.p2;
  return *this;
}

ostream& operator << (ostream& os, const Line& l) {
  os <<  "Line starts at " << l.p1 << ", " << "and ends at " << l.p2;
  return os;
}