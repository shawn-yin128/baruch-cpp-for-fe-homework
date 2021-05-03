#include "array.cpp"
#include "point.hpp"
#include <iostream>

using namespace std;

int main(void) {
	int size = 5;

	// Create array of points
	Array<Point> points(size);
	
	// Test [] operator for writing.
	points[0] = Point(1, 2);
	points[1] = Point(2, 3);
	points[2] = Point(3, 4);
    points[3] = Point(4, 5);
	points[4] = Point(5, 6);

	// test assignment operator
    Array<Point> points2(size);
	points2 = points;
	for (int i = 0; i < size; i++)
	{
		cout << points2[i] << endl;
	}

	// Test GetElement().
	cout << "First Elements: " << points.GetElement(0) << endl;

	// Test SetElement() and [] operator.
	points2.SetElement(0, Point(7, 8));
	cout << "First Elements: " << points2[0] << endl;

	// Using copy constructor.
	Array<Point> points3(points2);
	cout << "First Elements: " << points3[0] << endl;

    return 0;
}