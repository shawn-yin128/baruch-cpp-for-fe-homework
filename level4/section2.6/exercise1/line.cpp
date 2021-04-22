// implement of line class

#include <iostream>
#include <string>
#include <sstream>
#include "line.hpp"
#include "point.hpp"

using namespace std;

    // constructor
    mynamespace::CAD::Line::Line() {
    }

    mynamespace::CAD::Line::Line(const Point &p_start, const Point &p_end) {
      p1 = p_start;
      p2 = p_end;
    }

    mynamespace::CAD::Line::Line(const Line &l) {
      p1 = l.p1;
      p2 = l.p2;
    }

    // destructor
    mynamespace::CAD::Line::~Line() {
    }

    // get functions
    const mynamespace::CAD::Point& mynamespace::CAD::Line::P1() const {
      return p1;
    }

    const mynamespace::CAD::Point& mynamespace::CAD::Line::P2() const {
      return p2;
    }

    // set functions
    void mynamespace::CAD::Line::P1(const Point &p) {
      p1 = p;
    }

    void mynamespace::CAD::Line::P2(const Point &p) {
      p2 = p;
    }

    // length
    double mynamespace::CAD::Line::Length() const {
      return p1.Distance(p2);
    }

    // To string
    string mynamespace::CAD::Line::ToString() const {
      stringstream stream;
      stream << "Line starts at " << p1.ToString() << " and end at " << p2.ToString() << ".\n";
      return stream.str();
    }

    // assignment operator
    mynamespace::CAD::Line& mynamespace::CAD::Line::operator = (const Line& l) {
      if (this == &l) {
        return *this;
      }
      p1 = l.p1;
      p2 = l.p2;
      return *this;
    }

    ostream& mynamespace::CAD::operator << (ostream& os, const Line& l) {
      os <<  "Line starts at " << l.p1 << ", " << "and ends at " << l.p2;
      return os;
    }