#include <boost/tuple/tuple.hpp>
#include <string>
#include <iostream>

using namespace std;

typedef boost::tuple<string, int, double> Person;

void print_person(const Person& p) {
    cout << "name is " << p.get<0>() << endl;
    cout << "age is " << p.get<1>() << endl;
    cout << "length is " << p.get<2>() << endl;
}

int main() {
    Person stu1(string("Shawn"), 23, 1.7);
    Person stu2(string("Anna"), 22, 1.6);

    print_person(stu1);
    print_person(stu2);

    stu1.get<1>() = stu1.get<1>() + 1;
    print_person(stu1);

    return 0;
}