#include "point.hpp"
#include "line.hpp"
#include "circle.hpp"
#include <iostream>

using namespace std;

int main(void) {

    Point p(1, 2);
	Line l(Point(3, 4), Point(5, 6));
	p.Print(); // Point(1, 2) ID is 16807
	l.Print(); // Line starts at Point(3, 4) ID is 1144108930 and end at Point(5, 6) ID is 470211272. ID is 984943658

    return 0;
}