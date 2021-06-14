#include "EuropeanOption.hpp"
#include "PerpetualAmericanOption.hpp"
#include "MatrixPricer.hpp"
#include <string>
#include <vector>
#include <iostream>

using namespace std;

void TestOptionPricing(double r, double sig, double K, double T, double b, double S, string method, int batch_num) {// test option pricing for A1
    EuropeanOption opt(r, sig, K, T, b, "C", "EquityA");
    double callprice = opt.Price(S);
    double putprice = 0;

    if (method == "BS") {// calculate put price using BS formula
        opt.toggle();
        putprice = opt.Price(S);
    }
    else if (method == "PCP") {// calculate put price using put-call parity
        putprice = opt.PutCallParityPrice(S);
        opt.SatisfyPutCallParity(callprice, putprice, S); // check if satisfy put-call parity
    }
    // output results
    cout << "Batch " << batch_num << ":";
    cout << "T=" << T << ",K=" << K << ",sig=" << sig << ",r=" << r << ",S=" << S;
    cout << " (C=" << callprice << ",P=" << putprice << ")" << endl;
}

vector<double> mesh_array(int start, int end, int h) {
    vector<double> vec;
    for (int i = start; i <= end; i = i + h) {
        vec.push_back(i);
    }
    return vec;
}

int main() {
    cout << "A1(a)" << endl;
    TestOptionPricing(0.08, 0.3, 65, 0.25, 0.08, 60, "BS", 1);
    TestOptionPricing(0, 0.2, 100, 1, 0, 100, "BS", 2);
    TestOptionPricing(0.12, 0.5, 10, 1, 0.12, 5, "BS", 3);
    TestOptionPricing(0.08, 0.3, 100, 30, 0.08, 100, "BS", 4);

    cout << "A1(b)" << endl;
    TestOptionPricing(0.08, 0.3, 65, 0.25, 0.08, 60, "PCP", 1);
    TestOptionPricing(0, 0.2, 100, 1, 0, 100, "PCP", 2);
    TestOptionPricing(0.12, 0.5, 10, 1, 0.12, 5, "PCP", 3);
    TestOptionPricing(0.08, 0.3, 100, 30, 0.08, 100, "PCP", 4);

    cout << "A1(c)" << endl;
    EuropeanOption opt1(0.08, 0.3, 65, 0.25, 0.08, "C", "EquityA");
    vector<double> vS1 = mesh_array(60, 80, 5);
    vector<double> vCallPrice = opt1.Price(vS1);
    opt1.toggle();
    vector<double> vPutPrice = opt1.Price(vS1);
    for (int i = 0; i < vS1.size(); i++) {
        cout << "S=" << vS1[i] << ",C=" << vCallPrice[i] << ",P=" << vPutPrice[i] << endl;
    }

    cout << "A1(d)" << endl;
    vector<double> vec_r = {0.08, 0, 0.1};
    vector<double> vec_sig = {0.3, 0.2, 4};
    vector<double> vec_K = {65, 100, 100};
    vector<double> vec_T = {0.25, 1, 1};
    vector<double> vec_b = {0.08, 0, 0.1};
    vector<double> vec_S = {60, 100, 100};
    vector<double> vec_optClass = {0, 0, 0}; // 0: European, 1: PerpetualAmerican
    vector<double> vec_optType = {0, 1, 0}; // 0: Call, 1: Put

    MatrixPricer m_pricer;
    m_pricer.GenerateParameterMatrix(vec_r, vec_sig, vec_K, vec_T, vec_b, vec_S, vec_optClass, vec_optType);
    cout << "Option parameters:" << endl;
    m_pricer.PrintParameter();
    vector<double> vPrice = m_pricer.Price();
    for (int i = 0; i < vPrice.size(); i++) {
        cout << "Price=" << vPrice[i] << endl;
    }

    cout << "A2(a)" << endl;
    EuropeanOption opt2(0.1, 0.36, 100, 0.5, 0, "C", "EquityA");
    double calldelta = opt2.Delta(105);
    double callgamma = opt2.Gamma(105);
    opt2.toggle();
    double putdelta = opt2.Delta(105);
    double putgamma = opt2.Gamma(105);
    cout << "CallDelta=" << calldelta << ",PutDelta=" << putdelta << endl;
    cout << "CallGamma=" << callgamma << ",PutGamma=" << putgamma << endl;

    cout << "A2(b)" << endl;
    EuropeanOption opt3(0.08, 0.3, 65, 0.25, 0.08, "C", "EquityA");
    vector<double> vS2 = mesh_array(30, 100, 10);
    vector<double> vCallDelta = opt3.Delta(vS2);
    opt3.toggle();
    vector<double> vPutDelta = opt3.Delta(vS2);
    for (int i = 0; i < vS2.size(); i++) {
        cout << "S=" << vS2[i] << ",CallDelta=" << vCallDelta[i] << ",PutDelta=" << vPutDelta[i] << endl;
    }

    cout << "A2(c)" << endl;
    vector<double> vDelta = m_pricer.Delta();
    vector<double> vGamma = m_pricer.Gamma();
    for (int i = 0; i < vPrice.size(); i++) {
        cout << "Delta=" << vDelta[i] << ",Gamma=" << vGamma[i] << endl;
    }

    cout << "A2(d)" << endl;
    double d1 = opt3.Delta(105, 5);
    double d2 = opt3.Delta(105, 1);
    double d3 = opt3.Delta(105);;
    cout << "h=5, Delta=" << d1 << endl;
    cout << "h=1, Delta=" << d2 << endl;
    cout << "real Delta=" << d3 << endl;

    double g1 = opt3.Gamma(105, 5);
    double g2 = opt3.Gamma(105, 1);
    double g3 = opt3.Gamma(105);;
    cout << "h=5, Gamma=" << g1 << endl;
    cout << "h=1, Gamma=" << g2 << endl;
    cout << "real Gamma=" << g3 << endl;

    cout << "B(b)" << endl;
    PerpetualAmericanOption opt4(0.1, 0.1, 100, 1, 0.02, "C", "EquityA");
    double callprice = opt4.Price(110);
    opt4.toggle();
    double putprice = opt4.Price(110);
    cout << "K=" << 100 << ",sig=" << 0.1 << ",r=" << 0.1 << ",b=" << 0.02 << ",S=" << 110;
    cout << "(C=" << callprice << ",P=" << putprice << ")" << endl;

    cout << "B(c)" << endl;
    opt4.toggle();
    vector<double> vS3 = mesh_array(30, 100, 10);
    vCallPrice = opt4.Price(vS3);
    opt4.toggle();
    vPutPrice = opt4.Price(vS3);
    for (int i = 0; i < vS3.size(); i++) {
        cout << "S=" << vS3[i] << ",CallPrice=" << vCallPrice[i] << ",PutPrice=" << vPutPrice[i] << endl;
    }

    cout << "B(d)" << endl;
    vec_r = { 0.08, 0, 0.1 };
    vec_sig = { 0.3, 0.2, 0.1 };
    vec_K = { 65, 100, 100 };
    vec_T = { 0.25, 1, 1 };
    vec_b = { 0.08, 0, 0.02 };
    vec_S = { 60, 100, 110 };
    vec_optClass = { 0, 0, 1 }; // 0: European, 1: PerpetualAmerican
    vec_optType = { 0, 1, 0 }; // 0: Call, 1: Put

    m_pricer.GenerateParameterMatrix(vec_r, vec_sig, vec_K, vec_T, vec_b, vec_S, vec_optClass, vec_optType);
    cout << "Option parameters:" << endl;
    m_pricer.PrintParameter();
    vPrice = m_pricer.Price();
    for (int i = 0; i < vPrice.size(); i++) {
        cout << "Price=" << vPrice[i] << endl;
    }

    return 0;
}
