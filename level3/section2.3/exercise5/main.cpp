// test line class

#include <iostream>
#include "point.hpp"
#include "line.hpp"

using namespace std;

int main(void) {
  double x1, y1; // variables for start point
  double x2, y2; // variables for end point 
  
  // ask for coordinates of start point
  cout << "Please enter x y coordinates for start point.\n";
  cin >> x1 >> y1;

  // ask for coordinates of end point
  cout << "Please enter x y coordinates for end point.\n";
  cin >> x2 >> y2;

  // define two points
  Point p_start(x1, y1);
  Point p_end(x2, y2);

  // define line
  Line line(p_start, p_end);

  // test to string
  cout << line.ToString();

  // test length
  cout << "The length is " << line.Length() << endl;
  return 0;
}
