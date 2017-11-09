// The driver program for the DateTime class

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

  Date today = (day, month, year);
  Time now = (hour, minute, second);
  DateTime today_now = DateTime(today, now);

  cout << today_now.getDateTime() << endl;

  return 0;
}
