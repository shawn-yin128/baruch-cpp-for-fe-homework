#include <vector>
#include <algorithm>
#include <iostream>
#include "function_object.cpp"
using namespace std;

// Global function checking the input is less than a certain value.
int Compare(double input) {
	const double limit = 5.0;
	return input < limit;
}

int main(void) {
	vector<int> vector1;
	for (int i = 0; i < 20; i++)
	{
		vector1.push_back(i);
	}

	// function
	int res1 = count_if(vector1.begin(), vector1.end(), Compare);
	cout << "The number of elements that are less than 5 is " << res1 << endl;

	// function object
	double target = 5.0;
	int res2 = count_if(vector1.begin(), vector1.end(), FunctionObject<int>(target));
	cout << "The number of elements that are less than 5 is " << res2 << endl;
    
    return 0;
}