// test shape base class

#include "point.hpp"
#include "line.hpp"
#include "circle.hpp"
#include <iostream>

using namespace std;

int main(void) {
    Shape s; // Create shape.
    Point p(10, 20); // Create point.
    Line l(Point(1,2), Point(3, 4)); // Create line.

    cout<<s.ToString()<<endl; // Print shape.
    cout<<p.ToString()<<endl; // Print point.
    cout<<l.ToString()<<endl; // Print line

    cout<<"Shape ID: "<<s.ID()<<endl; // ID of the shape. 16807
    cout<<"Point ID: "<<p.ID()<<endl; // ID of the point. Does this work?
                                      // work 282475249
    cout<<"Line ID: "<<l.ID()<<endl; // ID of the line. Does this work?
                                     // work 1144108930
    
    cout << endl;

    Shape* sp; // Create pointer to a shape variable.
    sp=&p; // Point in a shape variable. Possible?
           // possible
    cout<<sp->ToString()<<endl; // What is printed?
                                // ID is 282475249

    // Create and copy Point p to new point.
    Point p2;
    p2=p;
    cout<<p2<<", "<<p2.ID()<<endl; // Is the ID copied if you do not call
                                   // the base class assignment in point?
                                   // No, p2 has a different id 1457850878
                                   // I think the reason is that the assignment pointer does not rewrite the id, it only change the point's attribute

    return 0;
}