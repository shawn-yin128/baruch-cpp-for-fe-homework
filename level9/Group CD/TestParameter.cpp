#include "OptionData.hpp"
#include "UtilitiesDJD/RNG/NormalGenerator.hpp"
#include "UtilitiesDJD/Geometry/Range.cpp"
#include <vector>
#include <cmath>
#include <iostream>

template <class T>
void print(const std::vector<T>& myList) {
	std::cout << std::endl << "Size of vector is " << l.size() << "\n[";

	std::vector<T>::const_iterator i;
	for (i = myList.begin(); i != myList.end(); ++i) {
		std::cout << *i << ",";

	}
	std::cout << "]\n";
}

namespace SDEDefinition {
	OptionData* data;
	double drift(double t, double X) { // Drift term
		return (data->r) * X; // r - D
	}

	double diffusion(double t, double X) { // Diffusion term
		double betaCEV = 1.0;
		return data->sig * pow(X, betaCEV);

	}

	double diffusionDerivative(double t, double X) { // Diffusion term, needed for the Milstein method
		double betaCEV = 1.0;
		return 0.5 * (data->sig) * (betaCEV)*pow(X, 2.0 * betaCEV - 1.0);
	}
}

double SD(vector<double> price, double r, double T) {// standard deviation
	double price_sum = 0;
	double price2_sum = 0;
	double M = price.size();
	for (int i = 0; i < price.size(); i++) {
		price_sum += price[i];
		price2_sum += (price[i] * price[i]);
	}
	//calculating the SD and SE
	return sqrt((price2_sum - price_sum * price_sum / M) / (M - 1)) * exp(-r * T);
}

double SE(vector<double> price, double r, double T) {// standard error
	double M = price.size();
	return SD(price, r, T) / sqrt(M);
}

int main() {
	std::cout << "1 factor MC with explicit Euler\n";
	OptionData myOption;
	myOption.K = 100;
	myOption.T = 1;
	myOption.r = 0;
	myOption.sig = 0.2;
	myOption.type = -1;	// Put -1, Call +1
	double S_0 = 100;

	vector<long> vNT = { 100, 200, 300, 500, 1000, 5000 };
	vector<long> vNSIM = { 100, 500, 1000, 5000, 10000, 20000 };

	for (int i = 0; i < vNT.size(); i++) {
		for (int j = 0; j < vNSIM.size(); j++) {
			long N = vNT[i];
			long NSim = vNSIM[j];
			// Create the basic SDE (Context class)
			Range<double> range(0.0, myOption.T);
			double VOld = S_0;
			double VNew;

			std::vector<double> x = range.mesh(N);

			double k = myOption.T / double(N);
			double sqrk = sqrt(k);

			// Normal random number
			double dW;
			double price = 0.0;	// Option price
			vector<double> vPrice;

			// NormalGenerator is a base class
			NormalGenerator* myNormal = new BoostNormal();

			using namespace SDEDefinition;
			SDEDefinition::data = &myOption;

			std::vector<double> res;
			int coun = 0; // Number of times S hits origin
			// A.
			for (long i = 1; i <= NSim; ++i) { // Calculate a path at each iteration
				if ((i / 10000) * 10000 == i) {// Give status after each 1000th iteration
					// std::cout << i << std::endl;
				}
				VOld = S_0;
				for (unsigned long index = 1; index < x.size(); ++index) {
					// Create a random number
					dW = myNormal->getNormal();

					// The FDM (in this case explicit Euler)
					VNew = VOld + (k * drift(x[index - 1], VOld))
						+ (sqrk * diffusion(x[index - 1], VOld) * dW);

					VOld = VNew;

					// Spurious values
					if (VNew <= 0.0) coun++;
				}

				double tmp = myOption.myPayOffFunction(VNew);
				price += (tmp) / double(NSim);
				vPrice.push_back(tmp);
			}

			// D. Finally, discounting the average price
			price *= exp(-myOption.r * myOption.T);

			// Cleanup; V2 use scoped pointer
			delete myNormal;

			std::cout << "NT=" << N << ",NSIM=" << NSim << ",Price=" << price << ",SD=" << SD(vPrice, myOption.r, myOption.T) << ",SE=" << SE(vPrice, myOption.r, myOption.T) << std::endl;
		}
	}
	return 0;
}