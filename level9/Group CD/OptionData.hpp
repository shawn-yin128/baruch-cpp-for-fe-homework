#ifndef OptionData_HPP
#define OptionData_HPP

#include <algorithm>

using namespace std;

struct OptionData {
	double K;
	double T;
	double r;
	double sig;

	double H;		// down and out barrier
	double D;		// dividend
	double betaCEV;	// elasticity factor (CEV model)
	double scale;	// scale factor in CEV model

	int type;		// 1 == call, -1 == put

	double myPayOffFunction(double S) { // Payoff function
		if (type == 1) { // Call
			return max(S - K, 0.0);
		}
		else { // Put
			return max (K - S, 0.0);
		}
	}
};

#endif