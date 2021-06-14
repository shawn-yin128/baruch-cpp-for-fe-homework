#include "EuropeanOption.hpp"
#include <cmath>
#include <vector>
#include <boost/math/distributions/normal.hpp>
#include <boost/math/distributions.hpp>

using namespace std;

EuropeanOption::EuropeanOption() : Option() {// default constructor
	optClass = "European";
}

EuropeanOption::EuropeanOption(double r_value, double sig_value, double K_value, double T_value, double b_value, string optType_value, string unam__value) : Option(r_value, sig_value, K_value, T_value, b_value, "European", optType_value, unam__value) {// constructor with arguments
}

EuropeanOption::EuropeanOption(const EuropeanOption& opt) : Option(opt) {// copy constructor
}

EuropeanOption::~EuropeanOption() {// destructor
}

EuropeanOption& EuropeanOption::operator = (const EuropeanOption& opt) {
	if (this == &opt) {
		return *this;
	}
	Option::operator = (opt);
	return *this;
}

double EuropeanOption::CallPrice(double U) const {
	using namespace boost::math;
	normal_distribution<> myNormal(0, 1);

	double tmp = sig * sqrt(T);
	double d1 = (log(U / K) + (b + (sig * sig) * 0.5) * T) / tmp;
	double d2 = d1 - tmp;

	return (U * exp((b - r) * T) * cdf(myNormal, d1)) - (K * exp(-r * T) * cdf(myNormal, d2));
}

double EuropeanOption::PutPrice(double U) const {
	using namespace boost::math;
	normal_distribution<> myNormal(0, 1);

	double tmp = sig * sqrt(T);
	double d1 = (log(U / K) + (b + (sig * sig) * 0.5) * T) / tmp;
	double d2 = d1 - tmp;

	return (K * exp(-r * T) * cdf(myNormal, -d2)) - (U * exp((b - r) * T) * cdf(myNormal, -d1));
}

double EuropeanOption::CallDelta(double U) const {
	using namespace boost::math;
	normal_distribution<> myNormal(0, 1);

	double tmp = sig * sqrt(T);
	double d1 = (log(U / K) + (b + (sig * sig) * 0.5) * T) / tmp;	

	return exp((b - r) * T) * cdf(myNormal, d1);
}

double EuropeanOption::PutDelta(double U) const {
	using namespace boost::math;
	normal_distribution<> myNormal(0, 1);

	double tmp = sig * sqrt(T);
	double d1 = (log(U / K) + (b + (sig * sig) * 0.5) * T) / tmp;	

	return  - exp((b - r) * T) * cdf(myNormal, -d1);
}


double EuropeanOption::CallGamma(double U) const {
	using namespace boost::math;
	normal_distribution<> myNormal(0, 1);

	double tmp = sig * sqrt(T);
	double d1 = (log(U / K) + (b + (sig * sig) * 0.5) * T) / tmp;	

	return (exp((b - r) * T) * pdf(myNormal, d1)) / (U * tmp);
}

double EuropeanOption::PutGamma(double U) const {
	return CallGamma(U);
}

double EuropeanOption::Price(double U) const {// calculate price of option
	if (optType == "C") {
		return CallPrice(U);
	}
	else {
		return PutPrice(U);
	}
}

vector<double> EuropeanOption::Price(vector<double> vU) const {// calculate price of option

	vector<double> vOptPrice;
	vector<double>::iterator it = vU.begin();
	for (vector<double>::iterator it = vU.begin(); it != vU.end(); it++) {
		vOptPrice.push_back(Price(*it));
	}
	return vOptPrice;
}

double EuropeanOption::Delta(double U) const {// calculate gamma of option
	if (optType == "C") {
		return CallDelta(U);
	}
	else {
		return PutDelta(U);
	}
}

double EuropeanOption::Delta(double U, double h) const {// numerical methods to calculate delta
	return (Price(U + h) - Price(U - h)) / (2 * h);
}

vector<double> EuropeanOption::Delta(vector<double> vU) const {// calculate price of option
	vector<double> vOptDelta;
	vector<double>::iterator it = vU.begin();
	for (vector<double>::iterator it = vU.begin(); it != vU.end(); it++) {
		vOptDelta.push_back(Delta(*it));
	}
	return vOptDelta;
}

double EuropeanOption::Gamma(double U) const {// calculate gamma of option
	if (optType == "C") {
		return CallGamma(U);
	}
	else {
		return PutGamma(U);
	}
}

double EuropeanOption::Gamma(double U, double h) const {// numerical methods to calculate gamma
	return (Price(U + h) - 2 * Price(U) + Price(U - h)) / (h * h);
}

vector<double> EuropeanOption::Gamma(vector<double> vU) const {// calculate price of option
	vector<double> vOptGamma;
	vector<double>::iterator it = vU.begin();
	for (vector<double>::iterator it = vU.begin(); it != vU.end(); it++) {
		vOptGamma.push_back(Gamma(*it));
	}
	return vOptGamma;
}


double EuropeanOption::PutCallParityPrice(double U) const {// calculate put/call price of option using put-call parity form call/put price
	if (optType == "C") {// using call price to calculate put price
		return CallPrice(U) + K * exp(-r * T) - U;
	}
	else {// using put price to calculate call price
		return PutPrice(U) + U - K * exp(-r * T);
	}
}

void EuropeanOption::SatisfyPutCallParity(double callprice, double putprice, double U) const {
	if ((callprice + K * exp(-r * T)) == (putprice + U)) {
		cout << "Satisfy put-call parity." << endl;
	}
	else {
		cout << "Not satisfy put-call parity." << endl;
	}
}
