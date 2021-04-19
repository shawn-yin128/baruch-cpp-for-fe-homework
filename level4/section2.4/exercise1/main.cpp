// test operators

#include "point.hpp"
#include "line.hpp"
#include "circle.hpp"
#include <iostream>
#include <string>
using namespace std;

int main(void) {
	// Test Point class.
	Point p1(5, 10);
	Point p2(15, 20);
	cout << p1.ToString() << ", " << p2.ToString() << endl;
	// test -
	Point p3 = - p1;
	cout << "p1 is " << p1.ToString() << ", set p3 = - p1 and will get: " << p3.ToString() << endl;
    // test +
	Point p4 = p1 + p2;
	cout << p1.ToString() << " + " << p2.ToString() << " will result " << p4.ToString() << endl;
    // test *
	Point p5 = p1 * 5.0;
	cout << p1.ToString() << " * 5.0 will result " << p5.ToString() << endl;
    // test ==
	cout << "(" << p1.ToString() << " == " << p2.ToString() << "), result: " << (p1 == p2) << endl;
    // test assignemnt
	Point p6 = p1;
	cout << "p1 is " << p1.ToString() << ", set p6 = p1 and will result " << p6.ToString() << endl;
    // test *=
	p3 *= 5.0;
	cout << "p3 *= 5.0, p3 becomes " << p3.ToString() << endl;

	// Test Line class.
	const Point lp1(2, 5);
	const Point lp2(4, 7);
	Line l1(lp1, lp2);
	cout << "l1: " << endl << l1.ToString() << endl;
    // test assignment
	Line l2 = l1;
	cout << "l2 = l1" << endl << "l2: " << endl << l2.ToString() << endl;

	// Test Circle class.
	const Point m_center(0, 0);
	double m_radius = 1.0;
	Circle c1(m_center, m_radius);
	cout << "c1: " << endl << c1.ToString() << endl;
    // test assignment
	Circle c2 = c1;
	cout << "c2 = c1" << endl << "c2: " << endl << c2.ToString() << endl;
    
    return 0;
}
