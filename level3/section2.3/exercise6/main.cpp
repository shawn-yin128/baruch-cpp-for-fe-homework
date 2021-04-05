// test circle class

#include "point.hpp"
#include "circle.hpp"
#include <iostream>

using namespace std;

int main(void) {
  double x, y; // define coordinates
  
  // ask for coordinates
  cout << "Please enter the center coordinates x y:\n";
  cin >> x >> y;
  
  // define center
  Point center(x, y);

  // ask for radius
  double radius;
  cout << "Please enter the radius of the circle:\n";
  cin >> radius;

  // build the circle
  Circle cir(center, radius);
  
  // get the paramters
  cout << cir.ToString() << endl;
  cout << "The diameter of the circle is " << cir.Diameter() << endl;
  cout << "The area of the circle is " << cir.Area() << endl;
  cout << "The circumference of the circle is " << cir.Circumference() << endl;

  return 0;
}
