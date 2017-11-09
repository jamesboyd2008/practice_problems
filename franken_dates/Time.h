// Specification file for the Time class
#ifndef TIME_H
#define TIME_H

class Time
{
public:
  Time(int hour1, int minute1, int second1);
  int getHour();
  int getMin();
  int getSec();
protected:
  int hour, minute, second;
};

// overloaded constructor function
Time::Time(int hour1, int minute1, int second1)
{
  hour = aHour;
  minute = aMinute;
  second = aSecond;
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
