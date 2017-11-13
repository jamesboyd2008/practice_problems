// The driver program for the DateTime class
#include <iomanip>
#include <iostream>
#include "DateTime.h"

using namespace std;

int main()
{
  int day = 1,
      month = 11,
      year = 2017,
      hour = 15,
      minute = 1,
      second = 30;

  DateTime today_now = DateTime(day, month, year, hour, minute, second);
  cout << "Here's the result of DateTime::getDateTime(): "
       << today_now.getDateTime() << endl;

  Date today = Date(day, month, year);
  cout << "Here's the result of Date::getMonth(): " << right << setw(9)
       << to_string(today.getMonth()) << endl;
  cout << "Here's the result of Date::getDay()  : " << right << setw(9)
       << to_string(today.getDay()) << endl;
  cout << "Here's the result of Date::getYear() : " << right << setw(9)
       << to_string(today.getYear()) << endl;

  Time now = Time(hour, minute, second);
  cout << "Here's the result of Time::getHour() : " << right << setw(9)
       << to_string(now.getHour()) << endl;
  cout << "Here's the result of Time::getMin()  : " << right << setw(9)
       << to_string(now.getMin()) << endl;
  cout << "Here's the result of Time::getSec()  : " << right << setw(9)
       << to_string(now.getSec()) << endl;


  return 0;
}
