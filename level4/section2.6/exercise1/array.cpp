// source file of array class

// use namespace xxx {
//  namespace xx {
//  } 
// } instead of format in this cpp

#include "array.hpp"
#include "point.hpp"
#include <iostream>

using namespace std;

        // constructor
        mynamespace::Containers::Array::Array() { // default to create an array with 10 point
            m_data = new mynamespace::CAD::Point[10];
            m_size = 10;
        }

        mynamespace::Containers::Array::Array(int size) {
            m_data = new mynamespace::CAD::Point[size];
            m_size = size;
        }

        mynamespace::Containers::Array::Array(const Array& arr) {
            m_data = new mynamespace::CAD::Point[arr.m_size];
            m_size = arr.m_size;
            for (int i = 0; i < m_size; i++) {
                m_data[i] = arr.m_data[i];
            }
        }

        // destructor
        mynamespace::Containers::Array::~Array() {
            delete[] m_data;
        }

        // operator overloading
        mynamespace::Containers::Array& mynamespace::Containers::Array::operator = (const Array& arr) {
            if (this == &arr) {
                return *this;
            }
            delete[] m_data; // delete original object at first

            m_data = new mynamespace::CAD::Point[arr.m_size];
            m_size = arr.m_size;
            for (int i = 0; i < m_size; i++) {
                m_data[i] = arr.m_data[i];
            }
            return *this;
        }

        mynamespace::CAD::Point& mynamespace::Containers::Array::operator [] (int idx) {
            if (idx >= m_size | idx < 0) {
                cout << "index out of range." << endl;
                return m_data[0];
            }
            return m_data[idx];
        }

        const mynamespace::CAD::Point& mynamespace::Containers::Array::operator [] (int idx) const {
            if (idx >= m_size | idx < 0) {
                cout << "index out of range." << endl;
                return m_data[0];
            }
            return m_data[idx];
        }

        // accessor
        int mynamespace::Containers::Array::Size() const {
            return m_size;
        }

        mynamespace::CAD::Point& mynamespace::Containers::Array::GetElement(int idx) const {
            if (idx >= m_size | idx < 0) {
                cout << "index out of range." << endl;
                return m_data[0];
            }
            return m_data[idx];
        }

        // modifier
        void mynamespace::Containers::Array::SetElement(int idx, const mynamespace::CAD::Point& p) {
            if (idx >= m_size | idx < 0) {
                cout << "index out of range." << endl;
                return;
            }
            m_data[idx] = p;
        }