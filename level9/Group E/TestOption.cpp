#include "UtilitiesDJD/ExcelDriver/ExcelDriverLite.hpp"
#include "UtilitiesDJD/ExcelDriver/Utilities.hpp"
#include "Group AB/Group AB/EuropeanOption.hpp"
#include <cmath>
#include <list>
#include <string>
#include <vector>

vector<double> mesh_array(int start, int end, int h) {
	vector<double> vec;
	for (int i = start; i <= end; i = i + h) {
		vec.push_back(i);
	}
	return vec;
}

int main() {
	cout << "E(b)" << endl;
	EuropeanOption opt1(0.08, 0.3, 65, 0.25, 0.08, "C", "EquityA");
	vector<double> vS1 = mesh_array(20, 80, 10);
	vector<double> vCallPrice = opt1.Price(vS1);	
	
	auto x = vS1;
	auto y = vCallPrice;

	ExcelDriver xl; xl.MakeVisible(true);
	xl.CreateChart(x, y, "Options prices curve");

	return 0;
}
