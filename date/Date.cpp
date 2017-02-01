#include "Date.h"

Date::Date() : month_(1), day_(1), year_(1900) { }
Date::Date(short month, short day, int year) {
  // Try to set date
  if (!setYear(year) || !setMonth(month) || !setDay(day)) { // If date is invalid
    month_ = 1;
    day_ = 1;
    year_ = 1900;
  }
}

short Date::getMonth() const { return month_; }
short Date::getDay() const { return day_; }
int Date::getYear() const { return year_; }

bool Date::leapYear() {
  return (
      ((year_ % 4 == 0) && (year_ % 100 != 0)) // If year is divisible by 4
          || (year_ % 400 == 0) // If year is divisible by 400
  );
}

bool Date::setMonth(short month) {
  // There are only 12 months in a year
  if ((month < 1) || (month > 12))
    return false;

  month_ = month;
  return true;
}

bool Date::setDay(short day) {
  // Check minimum days
  if (day < 1)
    return false;

  // Check maximum days
  if ((month_ == 1 || month_ == 3 || month_ == 5 || month_ == 7 || month_ == 8 || month_ == 10 || month_ == 12)
      && day > 31) // 31 day months
    return false;
  else if ((month_ == 4 || month_ == 6 || month_ == 9 || month_ == 11) && day > 30) // 30 day months
    return false;
  else if (month_ == 2) { // February
    if (leapYear() && (day > 29)) // Leap year
      return false;
    else if (day > 28) // Non-leap year
      return false;
  }

  day_ = day;
  return true;
}

bool Date::setYear(int year) {
  // Negative years are not possible
  if (year < 0)
    return false;

  year_ = year;
  return true;
}

bool Date::sameMonth(const Date &other_date) {
  return (month_ == other_date.month_);
}

bool Date::operator==(const Date &otherDate) const {
  return this->getDay() == otherDate.getDay() &&
      this->getMonth() == otherDate.getMonth() &&
      this->getYear() == otherDate.getYear();
}

std::ostream &operator<<(std::ostream &os, const Date &date) {
  return os << date.getMonth() << '-' << date.getDay() << '-' << date.getYear();
}

Date operator+(const Date &date, int days) {
  Date temp = date;
  for (size_t i = 0; i < days; i++)
    temp++;

  return temp;
}

Date operator+(int days, const Date &date) {
  return date + days;
}

Date &Date::operator++() {
  // Try to increment the day
  if (!this->setDay(++day_)) { // If next day is the first day of the next month
    // Try to increment the month
    if (!this->setMonth(++month_)) { // If the next month is the first month of next year
      this->setYear(++year_); // Increment the year
      this->setMonth(1); // Set the month to January
    }

    this->setDay(1); // Set the day to the first
  }

  return *this;
}

Date Date::operator++(int) {
  Date temp = *this;
  ++*this;
  return temp;
}

Date &Date::operator--() {
  // Try to decrement the day
  if (!this->setDay(--day_)) { // If previous day is the last day of the previous month
    // Try to decrement the month
    if (!this->setMonth(--month_)) { // If the previous month is the last month of previous year
      this->setYear(--year_); // Decrement the year
      this->setMonth(12); // Set the month to December
    }

    this->setDay(last_day(month_)); // Set the day to the last day of the month
  }

  return *this;
}

Date Date::operator--(int i) {
  Date temp = *this;
  --*this;
  return temp;
}

short Date::last_day(short month) {
  // Check maximum days
  if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) // 31 day months
    return 31;
  else if (month == 4 || month == 6 || month == 9 || month == 11) // 30 day months
    return 30;
  else if (month == 2) { // February
    if (leapYear()) // Leap year
      return 29;
    else // Non-leap year
      return 28;
  }
}
