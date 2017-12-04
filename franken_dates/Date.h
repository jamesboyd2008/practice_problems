// Specification file for the Date class
#ifndef DATE_H
#define DATE_H

class Date
{
public:
  Date();
  Date(int aDay, int aMonth, int aYear);
  int getDay();
  int getMonth();
  int getYear();
protected:
  int day, month, year;
};

// default constructor
Date::Date()
{
  day = 0;
  month = 0;
  year = 0;
}

// overloaded constructor function
Date::Date(int aDay, int aMonth, int aYear)
{
  day = aDay;
  month = aMonth;
  year = aYear;
}

/**
 * an accessor function, returning an iteger, the day
 * @returns int the day
 */
int Date::getDay()
{
  return day;
}

/**
 * an accessor function, returning an iteger, the month
 * @returns int the month
 */
int Date::getMonth()
{
  return month;
}

/**
 * an accessor function, returning an iteger, the year
 * @returns int the year
 */
int Date::getYear()
{
  return year;
}

#endif
