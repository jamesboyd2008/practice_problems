//This is the header file tempemployee.h.
//This is the interface for the class TempEmployee.
#ifndef TEMPEMPLOYEE_H
#define TEMPEMPLOYEE_H

#include <string>
#include "hourlyemployee.h"

using namespace std;

class TempEmployee : public HourlyEmployee
{
public:
    TempEmployee();
    TempEmployee
    (
      string the_name,
      string the_ssn,
      double the_wage_rate,
      double the_hours,
      string termination_date
    );
    string get_termination_date() const;
    void set_termination_date(string new_termination_date);
    friend ostream &operator<<(ostream &out, const TempEmployee &employee);
    friend istream &operator>>(istream &in, TempEmployee &employee);
private:
    double wage_rate;
    double hours;
    string termination_date;
};


#endif //TEMPEMPLOYEE_H
