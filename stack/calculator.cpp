#include <iostream>
#include <cmath>
#include <cstdlib>
#include <deque>
#include <iterator>
#include <algorithm>
#include <sstream>

#include "Stack.h"

using namespace std;

int main(void) {
  stringstream input;
  deque<string> tokens;

  cout << "Input an expression then press Ctrl+d: ";
  input << cin.rdbuf();
  copy(istream_iterator<string>(input),
       istream_iterator<string>(),
       front_inserter(tokens));

  while (!tokens.empty()) {
    cout << tokens.front() << endl;
    tokens.pop_front();
  }

  Stack<float> result;

//  for (size_t i = 0; i < 7; ++i) {
//    float first;
//    float second;
//
//    const char *input_c_str = input[i].c_str();
//
//    switch (*input_c_str) {
//      case '/':
//        second = result.pop();
//        first = result.pop();
//        result.push(first / second);
//        break;
//      case '+':
//        second = result.pop();
//        first = result.pop();
//        result.push(first + second);
//        break;
//      case '-':
//        second = result.pop();
//        first = result.pop();
//        result.push(first - second);
//        break;
//      case '*':
//        second = result.pop();
//        first = result.pop();
//        result.push(first * second);
//        break;
//      case '^':
//        second = result.pop();
//        first = result.pop();
//        result.push(pow(first, second));
//        break;
//      default:
//        result.push(atof(input_c_str));
//        break;
//    }
//  }
//
//  cout << result.pop() << endl;

  return 0;
}
