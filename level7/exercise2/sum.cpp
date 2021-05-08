// source file of sum functions

#ifndef Sum_CPP
#define Sum_CPP

#include <map>
#include "sum.hpp"

using namespace std;

template <typename T>
double Sum(const T& source) {
    double res = 0.0;
    for (typename T::const_iterator i = source.begin(); i != source.end(); i++) {
        res += *i;
    }
    return res;
} 

template <typename T>
double Sum(const typename T::const_iterator& source1, const typename T::const_iterator& source2) {
    double res = 0.0;
    for (source1; source1 != source2; source1++) {
        res += *source1;
    }
    return res;
}

template <typename T1, typename T2>
double Sum(const map<T1, T2>& source) {
    double res = 0.0;
    for (typename map<T1, T2>::const_iterator i = source.begin(); i != source.end(); i++) {
        res += (*i).second;
    }
    return res;
} 

template <typename T1, typename T2>
double Sum(const typename map<T1, T2>::const_iterator& source1, const typename map<T1, T2>::const_iterator& source2) {
    double res = 0.0;
    for (source1; source1 != source2; source1++) {
        res += (*source1).second;
    }
    return res;
}

#endif