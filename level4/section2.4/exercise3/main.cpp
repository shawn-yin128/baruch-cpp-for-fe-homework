// test << operators

#include "point.hpp"
#include <iostream>
#include <string>
using namespace std;

int main(void) {
	Point p(1.0, 1.0);
	
	// case 1
	/*
	if (p==1.0) {
		cout<<"Equal!"<<endl;
	}
	else {
		cout<<"Not equal"<<endl;
	}
	*/
	// it put 1.0 in the if to a new Point object

	// case 2
	if (p == (Point)1.0) cout << "Equal!" << endl;
	return 0;
}
