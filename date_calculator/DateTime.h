// Specification file for the DateTime Class
#ifndef DATETIME_H
#define DATETIME_H

// we need to include both the date and time classes
#include "Date.h"
#include "Time.h"
#include<string>
using namespace std;

class DateTime : public Date, public Time
{
protected:
	string dateTimeString;
public:
	DateTime(int dy, int mon, int yr, int hr, int mt, int sec);
	const string getDateTime();
};

// Overloaded Constructor
DateTime::DateTime(int dy, int mon, int yr, int hr, int mt, int sec)
{
	day = dy;
	month = mon;
	year = yr;
	hour = hr;
	minute = mt;
	second = sec;
}

// returns a human-readable string representation of the date
const string DateTime::getDateTime()
{
	/*
	string days =
	{
		"Monday",
		"Tuesday",
		"Wednesday",
		"Thursday",
		"Friday",
		"Saturday",
		"Sunday"
	};

	string months =
	{
		"January",
		"February",
		"March",
		"April",
		"May",
		"June",
		"July",
		"August",
		"September",
		"October",
		"November",
		"December"
	};
	*/

	dateTimeString += to_string(getMonth()) + "/";
	dateTimeString += to_string(getDay()) + "/";
	dateTimeString += to_string(getYear()) + " ";

	dateTimeString += to_string(getHour()) + ":";
	dateTimeString += to_string(getMin()) + ":";
	dateTimeString += to_string(getSec());

	return dateTimeString;
}


#endif
