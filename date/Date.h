#ifndef DATE_H
#define DATE_H

#include <iostream>

class Date {
 public:
  // Default date constructor.
  // Returns January 1, 1900
  Date();
  // Date constructor.
  // If any parameter is invalid, the default date is returned
  //
  // @param month the month
  // @param day the day
  // @param year the year
  Date(short month, short day, int year);

  // Get the month
  // @return The month
  short getMonth() const;

  // Get the day
  // @return The day
  short getDay() const;

  // Get the year
  // @return The year
  int getYear() const;

  // Determine if the year is a leap year
  // @return True if current year is a leap year
  bool leapYear();

  // Set the month
  // @param month the month
  // @return False if invalid month
  bool setMonth(short month);

  // Set the day
  // @param day the day
  // @return False if invalid day
  bool setDay(short day);

  // Set the year
  // @param year the year
  // @return False if invalid year
  bool setYear(int year);

  // Compare month to another date
  // @param other_date the other date
  // @return True if months are the same
  bool sameMonth(const Date &other_date);

  // Checks if dates are equal
  // @return True if the month, day, and year are equal
  bool operator==(const Date &otherDate) const;

  // Outputs the Date as a output stream
  friend std::ostream &operator<<(std::ostream &os, const Date &date);

  // Add Date + int
  // @return A new date with the number of days added
  friend Date operator+(const Date &date, int days);

  // Add int + Date
  // @return A new date with the number of days added
  friend Date operator+(int days, const Date &date);

  // Increments the date (prefix)
  // January 30, 2016 => January 31, 2016
  // January 31, 2016 => February 1, 2016
  // December 31, 2016 => January 1, 2017
  // @returns The incremented date
  Date &operator++();

  // Increment the date (postfix)
  // @returns A copy of the date before incrementing
  Date operator++(int);

  // Decrements the date (prefix)
  // January 31, 2016 => January 30, 2016
  // February 1, 2016 => January 31, 2016
  // January 1, 2017 => December 31, 2016
  // @returns The incremented date
  Date &operator--();

  // Decrements the date (postfix)
  // @returns A copy of the date before incrementing
  Date operator--(int);

 private:
  short month_;
  short day_;
  int year_;

  short last_day(short month);
};

#endif //DATE_H
