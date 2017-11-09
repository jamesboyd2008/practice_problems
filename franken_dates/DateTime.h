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
	DateTime(int dy, int mon, int yr, int hr, int mt, int sec); // Overloaded Constructor

	const string getDateTime()
	{
		string days =
		{
			"Monday",
			"",
			"",
			"",
			"",
			"",
			""
		}
		dateTimeString += getMonth();
		return dateTimeString;
	}
}; // End DateTime Frankenclass

#endif
