// test << operators

#include "point.hpp"
#include "line.hpp"
#include <iostream>
#include <string>
using namespace std;

int main(void) {
	// define point and line
	Point p1(1, 2);
	Point p2(3, 4);
	Line l1(p1, p2);
	
	// Test << operator in Point class.
	cout << p1 << endl;

	// Test << operator in Line class.
	cout << l1 << endl;

	return 0;
}
