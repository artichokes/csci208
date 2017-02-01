#include <iostream>
#include "Date.h"

using namespace std;

// Outputs the date in a nice format
// @param date The date to output
void print_date(const Date& date);

int main() {
  short input_month = 0;
  short input_day = 0;
  short input_year = 0;
  bool valid = false;

  // Check default date constructor
  Date date1 = Date();
  cout << "Default date constructor:" << endl;
  print_date(date1);
  cout << endl;

  // Check setters
  while (!valid) {
    cout << "Please enter a date (Month Day Year): ";
    cin >> input_month >> input_day >> input_year;

    if (date1.setYear(input_year)
        && date1.setMonth(input_month)
        && date1.setDay(input_day))
      valid = true;
    else
      cout << "Invalid date!" << endl;
  }

  // Check three argument date constructor
  cout << "Please enter a second date (Month Day Year): ";
  cin >> input_month >> input_day >> input_year;
  Date date2 = Date(input_month, input_day, input_year);
  cout << endl;

  // Output both dates
  cout << "Printing the two days:" << endl;
  print_date(date1);
  print_date(date2);
  cout << endl;

  // Check two months are same
  date1 = Date(11, 03, 1976);
  date2 = Date(11, 02, 1972);
  if (date1.sameMonth(date2))
    cout << "The months are the same:" << endl;
  else
    cout << "The months are different:" << endl;
  print_date(date1);
  print_date(date2);
  cout << endl;

  // Check two months are different
  date1 = Date(11, 03, 1976);
  date2 = Date(12, 03, 1976);
  if (date1.sameMonth(date2))
    cout << "The months are the same:" << endl;
  else
    cout << "The months are different:" << endl;
  print_date(date1);
  print_date(date2);
  cout << endl;

  // Check if two dates are the same
  date1 = Date(11, 03, 1976);
  date2 = Date(11, 03, 1976);
  if (date1 == date2)
    cout << "The dates are the same:" << endl;
  else
    cout << "The dates are different:" << endl;
  print_date(date1);
  print_date(date2);
  cout << endl;

  // Check if two dates are different
  date1 = Date(11, 03, 1976);
  date2 = Date(12, 03, 1976);
  if (date1 == date2)
    cout << "The dates are the same:" << endl;
  else
    cout << "The dates are different:" << endl;
  print_date(date1);
  print_date(date2);
  cout << endl;

  // Check increment day
  date1 = Date(1, 30, 2016);
  cout << "Increment date to the next day" << endl;
  print_date(date1);
  date1++;
  print_date(date1);
  cout << endl;

  date1 = Date(1, 31, 2016);
  cout << "Increment date to the next day" << endl;
  print_date(date1);
  date1++;
  print_date(date1);
  cout << endl;

  date1 = Date(12, 31, 2016);
  cout << "Increment date to the next day" << endl;
  print_date(date1);
  date1++;
  print_date(date1);
  cout << endl;

  cout << "Increment date five days" << endl;
  print_date(date1);
  print_date(date1 + 5);
  cout << endl;

  cout << "Increment date four days" << endl;
  print_date(date1);
  print_date(4 + date1);
  cout << endl;

  // Check decrement day
  date1 = Date(1, 31, 2016);
  cout << "Decrement date to the previous day" << endl;
  print_date(date1);
  date1--;
  print_date(date1);
  cout << endl;

  date1 = Date(2, 1, 2016);
  cout << "Decrement date to the previous day" << endl;
  print_date(date1);
  date1--;
  print_date(date1);
  cout << endl;

  date1 = Date(1, 1, 2017);
  cout << "Decrement date to the previous day" << endl;
  print_date(date1);
  date1--;
  print_date(date1);
  cout << endl;
}

void print_date(const Date &date) {
  // Check getters
  cout << "The date is (M-D-Y): " << date << endl;
}
