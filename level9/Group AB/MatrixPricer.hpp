#ifndef MatrixPricer_HPP
#define MatrixPricer_HPP

#include "Option.hpp"
#include <vector>
#include <string>

using namespace std;

class MatrixPricer {
    private:
        vector<vector<double> > m_parameter; // matrix to store option parameters
        vector<Option*> m_opt;
        int m_len;

    public:
        // constructors
        MatrixPricer();

        // destructor
        ~MatrixPricer();

        vector<vector<double>> GenerateParameterMatrix(vector<double> r, vector<double> sig, vector<double> K, vector<double> T, vector<double> b, vector<double> S, vector<double> optClass, vector<double> optType);

        void InitializeOptions(); // generate options according to parameters

        vector<double> Price(); // calculate theoretical price for options
        vector<double> Delta(); // calculate theoretical price for options
        vector<double> Gamma(); // calculate theoretical price for options

        void PrintParameter();
};

#endif
