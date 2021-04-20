// test << operators

#include "point.hpp"
#include "line.hpp"
#include "circle.hpp"
#include <iostream>
#include <string>
using namespace std;

int main(void) {
	// Test Point class.
	Point p1(5, 10);
	// test <<
	cout << "p1 is " << p1 << endl;

	// Test Line class.
	const Point lp1(2, 5);
	const Point lp2(4, 7);
	Line l1(lp1, lp2);
	cout << "l1 is " << l1 << endl;

	// Test Circle class.
	const Point m_center(0, 0);
	double m_radius = 1.0;
	Circle c1(m_center, m_radius);
	cout << "c1 is " << c1 << endl;

    return 0;
}
