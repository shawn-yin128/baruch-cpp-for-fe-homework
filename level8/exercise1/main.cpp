#include "array.hpp"
#include "circle.hpp"
#include "point.hpp"
#include "line.hpp"
#include "shape.hpp"
#include <iostream>
#include <boost/shared_ptr.hpp>

using namespace std;

typedef boost::shared_ptr<Shape> ShapePtr;
typedef Array<ShapePtr> ShapeArray;

int main(void) {
    ShapePtr p1(new Point(1, 2));
    ShapePtr l1(new Line(Point(1, 2), Point(2, 3)));
    ShapePtr c1(new Circle(Point(1, 2), 5));

    // count use times
    cout << "p1 reference count: " << p1.use_count() << endl;
	cout << "l1 reference count: " << l1.use_count() << endl;
	cout << "c1 reference count: " << c1.use_count() << endl;

    ShapeArray sa(3); // create a shape array that contains three elements

    // set each elements
    sa.SetElement(0, p1);
    sa.SetElement(1, l1);
    sa.SetElement(2, c1);

    // count use times again
    cout << "p1 reference count: " << p1.use_count() << endl;
	cout << "l1 reference count: " << l1.use_count() << endl;
	cout << "c1 reference count: " << c1.use_count() << endl;

    // print each element
    cout << "first element is " << (*sa[0]).ToString() << endl;
    cout << "second element is " << (*sa[1]).ToString() << endl;
    cout << "third element is " << (*sa[2]).ToString() << endl;


    // count use times again
    cout << "p1 reference count: " << p1.use_count() << endl;
	cout << "l1 reference count: " << l1.use_count() << endl;
	cout << "c1 reference count: " << c1.use_count() << endl;

    return 0;
}