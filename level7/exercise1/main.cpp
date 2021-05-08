// STL containers
#include <list>
#include <vector>
#include <map>
#include <iostream>

using namespace std;

int main(void) {
    // test list
    list<double> list1;
    // add at head
    list1.push_front(9.9);
    // add at tail
    list1.push_back(11.1);
    // access by front
    cout << "list front is " << list1.front() << endl;
    // access by back
    cout << "list back is " << list1.back() << endl;

    // test vector
    vector<double> vector1;
    // add elements
    for (int i = 0; i < 5; i++) {
        vector1.push_back(i);
    }
    // check the elements
    for (int i = 0; i < 5; i++) {
        cout << vector1[i] << endl;
    }
    // revise the elements
    for (int i = 0; i < 5; i++) {
        vector1[i] += 100;
        cout << vector1[i] << endl;
    }

    // test map
    map<string, double> map1;
    map1["key1"] = 1;
    map1["key2"] = 2;
    map1["key3"] = 3;
    cout << map1["key1"] << endl;

    return 0;
}