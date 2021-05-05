#include "point_array.hpp"
#include "point.hpp"
#include "array.hpp"

using namespace std;

PointArray::PointArray() : Array<Point>() {
}

PointArray::PointArray(int size) : Array<Point>(size) {
}

PointArray::PointArray(const PointArray& pa) : Array<Point>(pa) {
}

PointArray::~PointArray() {
}

PointArray& PointArray::operator = (const PointArray& pa) {
    if (this == &pa) {
        return *this;
    }
    else {
    Array<Point>::operator = (pa);
    return *this;
    }
}

double PointArray::Length() const {
    double res = 0;
    for (int i = 0; i < this->Size() - 1; i++) {
        res += (this->GetElement(i)).Distance(this->GetElement(i + 1));
    }
    return res;
}
