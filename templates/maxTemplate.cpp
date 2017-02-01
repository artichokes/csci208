/****************************************************
 *
 *  FileName:    ~/domanm2/maxTemplate.cpp
 *  Purpose:     Demonstrate the use of function templates
 *
 ********************************************************/
#include <iostream>
#include <string>
using namespace std;

//Make a template out of the prototype
template<typename Type>
Type myMax(Type one, Type two);

int main() {
  cout << " TEMPLATE LAB - FUNCTIONS " << endl;

  int i_one = 3, i_two = 5;
  cout << endl << "Test 1:  int" << endl;
  cout << "The max of " << i_one << " and " << i_two << " is "
      << myMax(i_one, i_two) << endl;

  char c_one = 'a', c_two = 'b';
  cout << endl << "Test 1:  char" << endl;
  cout << "The max of " << c_one << " and " << c_two << " is "
      << myMax(c_one, c_two) << endl;

  double d_one = 3.1, d_two = 5.1;
  cout << endl << "Test 1:  double" << endl;
  cout << "The max of " << d_one << " and " << d_two << " is "
      << myMax(d_one, d_two) << endl;

  string s_one = "Help", s_two = "Me";
  cout << endl << "Test 1:  string" << endl;
  cout << "The max of " << s_one << " and " << s_two << " is "
      << myMax(s_one, s_two) << endl;

  return 0;
}


//Make a template out of this function. Don't forget the return type.
template<typename Type>
Type myMax(Type one, Type two) {
  Type bigger;
  if (one < two) {
    bigger = two;
  }
  else {
    bigger = one;
  }
  return bigger;
}
