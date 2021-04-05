// test for inline functions

#include <iostream>
#include "point.hpp"

using namespace std;

int main(void) {
  double x, y;
  // ask for input
  cout << "Please enter coordinates:\n";
  cin >> x >> y;

  // build point
  Point p(x, y);
  cout << p.ToString() << endl;

  // test for get function
  cout << "x is " << p.X() << " and y is " << p.Y() << endl;

  // test for modifier
  double x2, y2;
  cout << "Please enter new coordinates:\n";
  cin >> x2 >> y2;
  p.X(x2);
  p.Y(y2);
  cout << p.ToString() << endl;
  return 0;
}
