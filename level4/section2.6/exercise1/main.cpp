// test namespace

#include "point.hpp"
#include "line.hpp"
#include "circle.hpp"
#include "array.hpp"
#include <iostream>
#include <string>

using namespace std;

int main(void) {
    // test point class
    mynamespace::CAD::Point p1(5, 5);
    mynamespace::CAD::Point p2(10, 10);
    cout << p1.ToString() << endl;
    cout << "Distance between" << p1 << " and " << p2 << " is " << p1.Distance(p2) << endl;

    // test line class
    mynamespace::CAD::Point p3(20, 20);
    mynamespace::CAD::Point p4(30, 30);
    mynamespace::CAD::Line l1(p3, p4);
    cout << l1 << endl;

    // test circle
    mynamespace::CAD::Point p5(2, 2);
    mynamespace::CAD::Circle c1(p5, 3.0);
    cout << c1.ToString() << endl;

    // test array
    mynamespace::Containers::Array aop(5);
    aop[0] = p1;
    aop[1] = p2;
    aop[2] = p3;
    aop[3] = p4;
    aop[4] = p5;
    for (int i = 0; i < aop.Size(); i++) {
        cout << aop[i] << endl;
    }

    return 0;
}