// source file of visitor class

#include "visitor.hpp"

Visitor::Visitor(): m_dx(0), m_dy(0) {
}

Visitor::Visitor(double x, double y): m_dx(x), m_dy(y) {
}

Visitor::~Visitor() {
}

void Visitor::operator () (Point &p) const {
    p.X(p.X() + m_dx);
    p.Y(p.Y() + m_dy);
}

void Visitor::operator () (Line& l) const {
    Point p1(l.P1().X() + m_dx, l.P1().Y() + m_dy);
    l.P1(p1);
    Point p2(l.P2().X() + m_dx, l.P2().Y() + m_dy);
    l.P2(p2);
}

void Visitor::operator () (Circle &c) const {
    Point p(c.CentrePoint().X() + m_dx, c.CentrePoint().Y() + m_dy);
    c.CentrePoint(p);
}

