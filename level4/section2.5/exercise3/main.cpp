// test array class

#include "point.hpp"
#include "array.hpp"
#include <iostream>
#include <string>

using namespace std;

int main(void) {
    // test constructor
    Array arr1;

    Array arr2(3);
    arr2[0] = Point(1, 1);
    arr2[1] = Point(2, 2);
    arr2[2] = Point(3, 3);

    Array arr3(arr2);

    // test assignment
    Array arr4 = arr2;
    cout << arr4[1] << endl;

    // test size
    cout << "size of arr4 is " << arr4.Size() << endl;

    // test get element
    cout << "the second element in arr3 is " << arr3.GetElement(2) << endl;

    // test set element
    cout << "the original first element in arr2 is " << arr2[0] << endl;
    Point p1(4, 4);
    arr2.SetElement(0, p1);
    cout << "after alteration, the first element in arr2 is " << arr2[0] << endl;

    return 0;
}