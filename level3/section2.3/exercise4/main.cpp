// a test program for point class
#include <iostream>
#include "point.hpp"

using namespace std;

int main(void) {
  // create a point object
  Point p1, p2;
  
  // ask user to input coordinates
  double x, y;
  cout << "Please enter x coordinate:\n";
  cin >> x;
  cout << "Please enter y coordinate:\n";
  cin >> y;

  // set the coordinates
  p1.X(x);
  p1.Y(y);

  // print the description of point out
  cout << "Point has coordinates " << p1.ToString() << endl;

  // print the coordinates by using get function
  cout << "Point has coordinates (" << p1.X() << ", " << p1.Y() << ")" << endl;
  
  // ask user to input corrdinates for point2
  double x2, y2;
  cout << "Please enter x coordinate:\n";
  cin >> x2;
  cout << "Please enter y coordinate:\n";
  cin >> y2;

  // set the coordinates
  p2.X(x2);
  p2.Y(y2);

  // create point(1.5 3.9) and change the value
  const Point cp(1.5, 3.9);
  // cp.X(0.3); false because its constant
  cout << cp.X() << endl; 
  // false without changeing because the compiler does not know whether the function will change the object or not
  // it can work after changing the function with const

  // calculate the distance 
  cout << "distance to origin is " << p1.Distance() << endl;
  cout << "distance to " << p2.ToString() <<  "is " << p1.Distance(p2) << endl;
  
  return 0;
}
