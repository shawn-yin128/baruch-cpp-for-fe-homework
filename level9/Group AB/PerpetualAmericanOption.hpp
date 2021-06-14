#ifndef PerpetualAmericanOption_HPP
#define PerpetualAmericanOption_HPP

#include "Option.hpp"
#include <vector>
#include <string>

using namespace std;

class PerpetualAmericanOption : public Option {
    private:
        // Functions for option calculation
        double CallPrice(double U) const;
        double PutPrice(double U) const;

    public:
        // constructors
        PerpetualAmericanOption();
        PerpetualAmericanOption(double r_value, double sig_value, double K_value, double T_value, double b_value, string optType_value, string unam__value);
        PerpetualAmericanOption(const PerpetualAmericanOption& opt);

        // destructor
        virtual ~PerpetualAmericanOption();

        // operator overload
        PerpetualAmericanOption& operator = (const PerpetualAmericanOption& opt); // assignment operator

        // Functions for calculating price and sensitivities
        double Price(double U) const;
        vector<double> Price(vector<double> vU) const;
};

#endif
