#include "array.hpp"
#include "arrayexception.hpp"
#include <iostream>
#include <string>

using namespace std;

int main(void) {
	Array array(2);
	
	try {
		cout << array[3] << endl;
	}
	catch (ArrayException& ex) {
		cout << ex.GetMessage() << endl;
	}
	return 0;
}