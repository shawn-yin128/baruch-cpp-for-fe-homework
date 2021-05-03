#include "array.cpp"
#include <iostream>

using namespace std;

int main(void) {
	// create arrays
	Array<int> intArray1;
	Array<int> intArray2;
	Array<double> doubleArray;

	// test size
	cout<<intArray1.DefaultSize()<<endl; // 10
	cout<<intArray2.DefaultSize()<<endl; // 10
	cout<<doubleArray.DefaultSize()<<endl; // 10

	intArray1.DefaultSize(15); // reset default size

	// retest size
	cout<<intArray1.DefaultSize()<<endl; // 15
	cout<<intArray2.DefaultSize()<<endl; // 15
	cout<<doubleArray.DefaultSize()<<endl; // 10
	// the DefaultSize function changes the Array<int>'s defaultsize instead of Array<double> because they are two different types

	return 0;
}