#include "point.hpp"
#include "line.hpp"
#include "circle.hpp"
#include "visitor.hpp"
#include <boost/variant.hpp>
#include <boost/variant/apply_visitor.hpp>
#include <string>

using namespace std;

typedef boost::variant<Point, Line, Circle> ShapeType;

ShapeType Create() {
    ShapeType shape;

    // ask for specific type
    cout << "choose the type between (Point, Line, Circle):" << endl;
    string type;
    cin >> type;

    // based on type return different value
    if (type == "Point") {
        shape = Point();
        return shape;
    }
    else if (type == "Line") {
        shape = Line();
        return shape;
    }
    else if (type == "Circle") {
        shape = Circle();
        return shape;
    }
}

int main() {
    ShapeType res = Create();
    cout << res << endl;

    // assign with get function
    try {
        Line l1 = boost::get<Line>(res); // if the variant's current type is not line, exception will occur
    }
    catch (boost::bad_get& err) {
        cout << "Error: " << err.what() << endl;
    }

    // change the shape.
    Visitor visitor(1.0, 2.0);
    boost::apply_visitor(visitor, res);
    cout << res << endl;
}