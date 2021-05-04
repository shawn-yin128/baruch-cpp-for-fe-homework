#include "array.hpp"
#include "NumericArray.hpp"
#include "ArrayException.hpp"
#include <iostream>

using namespace std;

int main(void) {	
	try {		
		NumericArray<int> int_array1(3);
		NumericArray<int> int_array2(3);
		NumericArray<int> int_array3(3);		

		// test base class function
		for (int i = 0; i < int_array1.Size(); i++) {
			int_array1.SetElement(i, i + 1);
			cout << int_array1.GetElement(i) << endl;
			cout << int_array1[i] << endl;
		}
		// test assignment operator, * operator
		int_array2 = int_array1 * 3;
		for (int i = 0; i < int_array2.Size(); i++) {	
			cout << int_array2[i] << endl;
		}
		//  test + operator
		int_array3 = int_array1 + int_array2;
		for (int i = 0; i < int_array3.Size(); i++) {
			cout << int_array3[i] << endl;
		}
		//  test DotProduct
		int product = int_array1.DotProduct(int_array2);
		cout << "dot product: " << product << endl;
		
	}
	catch (ArrayException & ex) {
		cout << "ArrayException has occurred: " << ex.GetMessage() << endl;
	}

	return 0;
}
