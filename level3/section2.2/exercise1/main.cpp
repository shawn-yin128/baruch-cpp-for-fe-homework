// a test program for point class
#include <iostream>
#include "point.hpp"

using namespace std;

int main(void) {
  // create a point object
  Point p1;
  
  // ask user to input coordinates
  double x, y;
  cout << "Please enter x coordinate:\n";
  cin >> x;
  cout << "Please enter y coordinate:\n";
  cin >> y;

  // set the coordinates
  p1.SetX(x);
  p1.SetY(y);

  // print the description of point out
  cout<< "Point has cordinates " << p1.ToString() << endl;

  // print the coordinates by using get function
  cout << "Point has coordinates (" << p1.GetX() << ", " << p1.GetY() << ")" << endl;
  return 0;
}
