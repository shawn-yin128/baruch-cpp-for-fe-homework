// header file of sum functions

#ifndef Sum_HPP
#define Sum_HPP

#include <map>

using namespace std;

// sum of complete container
template <typename T>
double Sum(const T& source);

// sum of elements between iterators
template <typename T>
double Sum(const typename T::const_iterator& source1, const typename T::const_iterator& source2);

// sum for map
template <typename T1, typename T2>
double Sum(const map<T1, T2>& source);

// sum for map elemebts between iterators
template <typename T1, typename T2>
double Sum(const typename map<T1, T2>::const_iterator& source1, const typename map<T1, T2>::const_iterator& source2);

#ifndef Sum_CPP
#include "sum.cpp"
#endif

#endif