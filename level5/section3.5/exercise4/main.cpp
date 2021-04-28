#include "point.hpp"
#include "line.hpp"
#include "circle.hpp"
#include <iostream>

using namespace std;

int main(void) {

    Shape* shapes[10];
	shapes[0] = new Line;
	shapes[1] = new Point;
	shapes[2] = new Line(Point(1.0, 2.5), Point(3.4, 5.2));
	shapes[3] = new Circle(Point(0.0, 0.0), 1.0);

	for (int i = 0; i != 4; i++) {
        shapes[i]->Draw();
    }
	for (int i = 0; i != 4; i++) {
        delete shapes[i];
    }
    // draw a line.
    // draw a point.
    // draw a line.
    // draw a circle.

    return 0;
}