#include "PerpetualAmericanOption.hpp"
#include <cmath>
#include <vector>
#include <boost/math/distributions/normal.hpp>
#include <boost/math/distributions.hpp>

using namespace std;

PerpetualAmericanOption::PerpetualAmericanOption() : Option() {// default constructor
	optClass = "PerpetualAmerican";
}

PerpetualAmericanOption::PerpetualAmericanOption(double r_value, double sig_value, double K_value, double T_value, double b_value, string optType_value, string unam__value) : Option(r_value, sig_value, K_value, T_value, b_value, "PerpetualAmerican", optType_value, unam__value) {// constructor with arguments
}

PerpetualAmericanOption::PerpetualAmericanOption(const PerpetualAmericanOption& opt) : Option(opt) {// copy constructor
}

PerpetualAmericanOption::~PerpetualAmericanOption() {// destructor
}

PerpetualAmericanOption& PerpetualAmericanOption::operator = (const PerpetualAmericanOption& opt) {
	if (this == &opt) {
		return *this;
	}
	Option::operator = (opt);

	return *this;
}

double PerpetualAmericanOption::CallPrice(double U) const {
	double y1 = 0.5 - b / (sig * sig) + sqrt(pow(b/(sig * sig) - 0.5, 2) + (2 * r) / (sig * sig));
	return K / (y1 - 1) * pow((y1 - 1) * U / y1 / K, y1);
}

double PerpetualAmericanOption::PutPrice(double U) const {
	double y2 = 0.5 - b / (sig * sig) - sqrt(pow(b / (sig * sig) - 0.5, 2) + (2 * r) / (sig * sig));
	return K / (1 - y2) * pow((y2 - 1) * U / y2 / K, y2);
}

double PerpetualAmericanOption::Price(double U) const {// calculate price of option
	if (optType == "C") {
		return CallPrice(U);
	}
	else {
		return PutPrice(U);
	}
}

vector<double> PerpetualAmericanOption::Price(vector<double> vU) const {// calculate price of option
	vector<double> vOptPrice;
	vector<double>::iterator it = vU.begin();
	for (vector<double>::iterator it = vU.begin(); it != vU.end(); it++) {
		vOptPrice.push_back(Price(*it));
	}
	return vOptPrice;
}
