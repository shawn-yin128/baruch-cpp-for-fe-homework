#ifndef Option_HPP
#define Option_HPP

#include <string>

using namespace std;

class Option {
    public:
        // Member data public for convenience
        double r;		// Interest rate
        double sig;		// Volatility
        double K;		// Strike price
        double T;		// Expiry date
        double b;		// Cost of carry

        string optClass;
        string optType;	// Option name (call, put)
        string unam;	// Name of underlying asset

        // constructors
        Option();
        Option(double r_value, double sig_value, double K_value, double T_value, double b_value, string optClass_value, string optType_value, string unam__value);
        Option(const Option& opt); // copy constructor

        // destructor
        virtual ~Option();

        // operator overload
        Option& operator = (const Option& opt);

        // Modifier functions
        void toggle();		// Change option type (C/P, P/C)

        // Functions for calculating price and sensitivities
        virtual double Price(double U) const;
        virtual double Delta(double U) const;
        virtual double Delta(double U, double h) const; // numerical methods
        virtual double Gamma(double U) const;
	    virtual double Gamma(double U, double h) const; // numerical methods
};

#endif
