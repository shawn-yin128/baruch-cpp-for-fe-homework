// header file of visitor class

#ifndef VISITOR_HPP
#define VISITOR_HPP

#include "point.hpp"
#include "line.hpp"
#include "circle.hpp"
#include <boost/variant.hpp>

class Visitor: public boost::static_visitor<> {
private:
    double m_dx;
    double m_dy;
public:
    Visitor();
    Visitor(double x, double y);
    ~Visitor();

    void operator () (Point& p) const;
    void operator () (Line& l) const;
    void operator () (Circle& c) const;
};

#endif
