#include <iostream>
#include <cmath>

using namespace std;

class twoD {
 protected:
  double x, y; // x and y  coordinates
 public:
  // inline implementation of constructor
  twoD() : x(0), y(0) {
    cout << "\tComment from within the twoD default constructor" << endl;
  }
  twoD(double i, double j) : x(i), y(j) {
    cout << "\tComment from within the twoD parametrized constructor" << endl;
  }

  // inline implementation of member functions
  void setX(double NewX) { x = NewX; }
  void setY(double NewY) { y = NewY; }
  double getX() const { return x; }
  double getY() const { return y; }
};

class threeD: public twoD {
 private:
  double z;
 public:
  // Inline implemenation of constructor.
  // Constructor of the base class is not inherited.
  // The following constructor of threeD class reuses the
  // constructor of the twoD class and the only way values
  // can be passed to the twoD constructor is via the use
  // of a member initialization list.
  threeD() : twoD(), z(0) {
    cout << "\tComment from within the threeD default constructor" << endl;
  }

  threeD(double i, double j, double k) : twoD(i, j), z(k) {
    cout << "\tComment from within the threeD parametrized constructor" << endl;
  }

  void setZ(double NewZ) { z = NewZ; }
  double getZ() { return z; }
};


int main() {
  cout << "TEST 1 Default Constructor - Create a 3D point object with default constructor" << endl;
  threeD point1;
  cout << endl;

  cout << "TEST 2 Set methods  - Set the xyz values for that object" << endl;
  cout << "Please enter the xyz coordinates for the start point" << endl;
  double x, y, z;
  bool valid = false;
  while (!valid) {
    cin >> x >> y >> z;
    if (cin.fail()) {
      valid = false;
      cin.clear();
      cin.ignore();
      cout << "\nInvalid coordinate!\n";
    } else
      valid = true;
  }
  point1.setX(x); point1.setY(y); point1.setZ(z);
  cout << endl;

  cout << "TEST 3 Parametrized Constructor - Create a 3D point object with input values" << endl;
  cout << "Please enter the xyz coordinates for the start point" << endl;
  valid = false;
  while (!valid) {
    cin >> x >> y >> z;
    if (cin.fail()) {
      valid = false;
      cin.clear();
      cin.ignore();
      cout << "\nInvalid coordinate!\n";
    } else
      valid = true;
  }
  cout << endl;
  threeD point2(x, y, z);
  cout << endl;

  cout << "TEST 4 Get methods - Using the get methods, determine the distance between these points in 3D space" << endl;
  double distance = sqrt(
      pow(point2.getX() - point1.getX(), 2) +
      pow(point2.getY() - point1.getY(), 2) +
      pow(point2.getZ() - point1.getZ(), 2));
  cout << "Distance is : " << distance << endl;

  return 0;
}
