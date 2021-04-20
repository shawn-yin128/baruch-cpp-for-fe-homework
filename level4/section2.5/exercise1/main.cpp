// test the dynamic object

#include "point.hpp"
#include <iostream>
#include <string>

using namespace std;

int main(void) {
    // test constructor
    Point* p1 = new Point(); // by default constructor
    Point* p2 = new Point(10, 10); // by input value
    Point* p3 = new Point(*p2); // by copy constructor 

    cout << *p1 << ", " << *p2 << ", " << *p3 << endl;

    // test distance
    cout << "the distance between " << *p2 << " and " << *p1 << " is "
        << (*p2).Distance(*p1) << endl;

    // delete useless object
    delete p1;
    delete p2;
    delete p3;

    // create array of points
    // ask for size of array
    int size;
    cout << "Please enter the size of array:" << endl;
    cin >> size;

    // create on stack
    // Point aop1[size];

    // create on heap
    Point* aop2 = new Point[size];
    delete[] aop2;

    return 0;
}