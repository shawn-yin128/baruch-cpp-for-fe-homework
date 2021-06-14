#include "Option.hpp"
#include <string>

using namespace std;

Option::Option() : r(0.02), sig(0.1), K(100.0), T(1), b(0.01), optClass(""), optType("C"), unam("") {// default constructor
}

Option::Option(double r_value, double sig_value, double K_value, double T_value, double b_value, string optClass_value, string optType_value, string unam_value) : r(r_value), sig(sig_value), K(K_value), T(T_value), b(b_value), optClass(optClass_value), optType(optType_value), unam(unam_value) {// constructor with arguments
}

Option::Option(const Option& opt) : r(opt.r), sig(opt.sig), K(opt.K), T(opt.T), b(opt.b), optClass(opt.optClass), optType(opt.optType), unam(opt.unam) {// copy constructor
}

Option::~Option() {// destructor
}

Option& Option::operator = (const Option& opt) {// assignment operator overload
	if (this == &opt) {
		return *this;
	}
	r = opt.r;
	sig = opt.sig;
	K = opt.K;
	T = opt.T;
	b = opt.b;
	optClass = opt.optClass;
	optType = opt.optType;
	unam = opt.unam;

	return *this;
}

// Modifier functions
void Option::toggle() { // Change option type (C/P, P/C)
	if (optType == "C")
		optType = "P";
	else
		optType = "C";
}

double Option::Price(double U) const {
	return 0;
}

double Option::Delta(double U) const {
	return 0;
}

double Option::Delta(double U, double h) const {
	return (Price(U+h) - Price(U-h)) / (2 * h);
}

double Option::Gamma(double U) const {
	return 0;
}

double Option::Gamma(double U, double h) const {
	return (Price(U+h) - 2 * Price(U) + Price(U-h)) / (h * h);
}