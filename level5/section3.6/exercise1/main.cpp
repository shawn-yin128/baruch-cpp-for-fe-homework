#include "array.hpp"
#include <iostream>
#include <string>
using namespace std;

int main(void) {
	Array array(2);

	try {
		cout << array[3] << endl;
	}
	catch (int err_message) {
		if (err_message == -1) {
			cout << "Index out of range." << endl;
		}
	}
}