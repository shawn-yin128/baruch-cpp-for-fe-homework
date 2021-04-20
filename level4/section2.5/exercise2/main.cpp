// implement array of points pointers

#include "point.hpp"
#include <iostream>
#include <string>

using namespace std;

int main(void) {
    // create an array of point pointers
    Point** aop = new Point*[3]; // ** pointer of pointer

    // create a point for each position
    aop[0] = new Point(1.0, 1.0); // not *aop[0] because it already dereference
    aop[1] = new Point(2.0, 2.0);
    aop[2] = new Point(3.0, 3.0);

    // print the array out
    for (int i = 0; i < 3; i++) {
        cout << *aop[i] << endl;
    }

    // delete the point in array
    for (int i = 0; i < 3; i++) {
        delete aop[i];
    }

    // delete array
    delete[] aop;
    
    return 0;
}