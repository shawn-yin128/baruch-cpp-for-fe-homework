#ifndef EuropeanOption_HPP
#define EuropeanOption_HPP

#include "Option.hpp"
#include <vector>
#include <string>

using namespace std;

class EuropeanOption : public Option {
    private:
        // Functions for option calculation
        double CallPrice(double U) const;
        double PutPrice(double U) const;

        double CallDelta(double U) const;
        double PutDelta(double U) const;

        double CallGamma(double U) const;
        double PutGamma(double U) const;

    public:
        // constructors
        EuropeanOption();
        EuropeanOption(double r_value, double sig_value, double K_value, double T_value, double b_value, string optType_value, string unam__value);
        EuropeanOption(const EuropeanOption& opt);

        // destructor
        virtual ~EuropeanOption();

        // operator overload
        EuropeanOption& operator = (const EuropeanOption& opt); // assignment operator

        // Functions for calculating price and sensitivities
        double Price(double U) const;
        vector<double> Price(vector<double> vU) const;
        double Delta(double U) const;
        double Delta(double U, double h) const;
        vector<double> Delta(vector<double> vU) const;
        double Gamma(double U) const;
        double Gamma(double U, double h) const;
        vector<double> Gamma(vector<double> vU) const;
        double PutCallParityPrice(double U) const;
        void SatisfyPutCallParity(double callprice, double putprice, double U) const;
};

#endif
