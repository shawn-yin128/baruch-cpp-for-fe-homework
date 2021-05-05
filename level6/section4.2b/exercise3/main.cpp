#include "point.hpp"
#include "point_array.hpp"
#include "array.hpp"
#include "shape.hpp"
#include <iostream>

using namespace std;

int main(void) {
    // Test constructors.
	PointArray pa1; // default constructor 
	cout << "PointArray1: " << endl << "size = " << pa1.Size() << endl;
	
	PointArray pa2(2); // input size
    pa2[0] = Point(1, 2);
    pa2[1] = Point(2, 3);
	cout << "PointArray2: " << endl;
	for (int i = 0; i < pa2.Size(); i++) {
		cout << pa2[i] << endl;
	}

	PointArray pa3(pa2); // copy
	cout << "PointArray3: " << endl;
	for (int i = 0; i < pa3.Size(); i++) {
		cout << pa3[i] << endl;
	}

	// Test assignment operator.
	PointArray pa4 = pa3;
	cout << "PointArray4: " << endl;
	for (int i = 0; i < pa4.Size(); i++) {
		cout << pa4[i] << endl;
	}

	// Test Length() function.
	cout << "Length of PointArray4 = " << pa4.Length() << endl;
    
    return 0;
}