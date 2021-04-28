// test shape base class

#include "point.hpp"
#include "line.hpp"
#include "circle.hpp"
#include <iostream>

using namespace std;

int main(void) {
    Shape* shapes[3];
    shapes[0]=new Shape;
    shapes[1]=new Point;
    shapes[2]=new Line;

    for (int i=0; i!=3; i++) {
        delete shapes[i];
    }

    // without virtual only shape destructor is called three times

    // with virtual 
    // shape destructor is called 5 times
    // point destructor is called 3 tiems 
    // line destructor is called 1 time

    return 0;
}