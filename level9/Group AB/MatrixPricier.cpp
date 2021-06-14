#include "Option.hpp"
#include "MatrixPricer.hpp"
#include "EuropeanOption.hpp"
#include "PerpetualAmericanOption.hpp"
#include <vector>
#include <string>
#include <iostream>
#include <iomanip>

using namespace std;

MatrixPricer::MatrixPricer() {
	m_len = 0;
}

MatrixPricer::~MatrixPricer() {
}

vector<vector<double>> MatrixPricer::GenerateParameterMatrix(vector<double> r, vector<double> sig, vector<double> K, vector<double> T, vector<double> b, vector<double> S, vector<double> optClass, vector<double> optType) {
	m_len = r.size();
	m_parameter.clear();
	m_opt.clear();

	m_parameter.push_back(r);
	m_parameter.push_back(sig);
	m_parameter.push_back(K);
	m_parameter.push_back(T);
	m_parameter.push_back(b);
	m_parameter.push_back(S);
	m_parameter.push_back(optClass);
	m_parameter.push_back(optType);

	InitializeOptions();

	return m_parameter;	
}

void MatrixPricer::InitializeOptions() {// generate options according to parameters
	for (int i = 0; i < m_len; i++) {
		double optClass = m_parameter[6][i];
		string optType = "";

		if (m_parameter[7][i] == 0) {
			optType = "C";
		}
		else if (m_parameter[7][i] == 1) {
			optType = "P";
		}
		else {
			cout << "Invalid option type." << endl;
		}

		if (optClass == 0) {
			m_opt.push_back(new EuropeanOption(m_parameter[0][i], m_parameter[1][i], m_parameter[2][i], m_parameter[3][i], m_parameter[4][i], optType, "Equity"));
		}
		else if (optClass == 1) {
			m_opt.push_back(new PerpetualAmericanOption(m_parameter[0][i], m_parameter[1][i], m_parameter[2][i], m_parameter[3][i], m_parameter[4][i], optType, "Equity"));
		}
		else {
			cout << "Invalid option class." << endl;
		}
	}	
}

vector<double> MatrixPricer::Price() {// calculate theoretical price for options
	vector<double> opt_price(m_len);

	for (int i = 0; i < m_len; i++) {
		opt_price[i] = m_opt[i]->Price(m_parameter[5][i]);
	}
	return opt_price;
}


vector<double> MatrixPricer::Delta() {// calculate theoretical price for options
	vector<double> opt_delta(m_len);

	for (int i = 0; i < m_len; i++) {
		opt_delta[i] = m_opt[i]->Delta(m_parameter[5][i]);
	}
	return opt_delta;
}

vector<double> MatrixPricer::Gamma() {// calculate theoretical price for options
	vector<double> opt_gamma(m_len);

	for (int i = 0; i < m_len; i++) {
		opt_gamma[i] = m_opt[i]->Gamma(m_parameter[5][i]);
	}
	return opt_gamma;
}

void MatrixPricer::PrintParameter() {
	cout << setw(8) << "OptClass" <<
		setw(8) << "OptType" <<
		setw(5) << "r" <<
		setw(5) << "sig" <<
		setw(5) << "K" <<
		setw(5) << "T" <<
		setw(5) << "b" <<
		setw(5) << "S" << endl;	
	for (int i = 0; i < m_len; i++) {
		cout << setw(8) << m_parameter[6][i] <<
			setw(8) << m_parameter[7][i] <<
			setw(5) << m_parameter[0][i] <<
			setw(5) << m_parameter[1][i] <<
			setw(5) << m_parameter[2][i] <<
			setw(5) << m_parameter[3][i] <<
			setw(5) << m_parameter[4][i] <<
			setw(5) << m_parameter[5][i] << endl;
	}
}
