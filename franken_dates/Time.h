// Specification file for the Time class
#ifndef TIME_H
#define TIME_H

class Time
{
public:
  Time();
  Time(int hour1, int minute1, int second1);
  int getHour();
  int getMin();
  int getSec();
protected:
  int hour, minute, second;
};

// default constructor
Time::Time()
{
  hour = 0;
  minute = 0;
  second = 0;
}

// overloaded constructor function
Time::Time(int hour1, int minute1, int second1)
{
  hour = hour1;
  minute = minute1;
  second = second1;
}

/**
 * an accessor function, returning an iteger, the hour
 * @returns int the hour
 */
int Time::getHour()
{
  return hour;
}

/**
 * an accessor function, returning an iteger, the minute
 * @returns int the minute
 */
int Time::getMin()
{
  return minute;
}

/**
 * an accessor function, returning an iteger, the second
 * @returns int the second
 */
int Time::getSec()
{
  return second;
}

#endif
