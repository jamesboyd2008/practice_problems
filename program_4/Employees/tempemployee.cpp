//This is the file: tempemployee.cpp
//This is the implementation for the class TempEmployee.
//The interface for the class TempEmployee is in
//the header file tempemployee.h.
#include <string>
#include <iostream>
#include "tempemployee.h"
using namespace std;



    TempEmployee::TempEmployee() : HourlyEmployee(),
                                   wage_rate(0),
                                   hours(0),
                                   termination_date("August 21, 2099")
    {
        //deliberately empty
    }

    TempEmployee::TempEmployee
    (
      string the_name,
      string the_number,
      double the_wage_rate,
      double the_hours,
      string the_termination_date
    ) : HourlyEmployee(the_name, the_number, the_wage_rate, the_hours),
        wage_rate(the_wage_rate),
        hours(the_hours),
        termination_date(the_termination_date)
    {
        //deliberately empty
    }

    string TempEmployee::get_termination_date() const
    {
      return termination_date;
    }

    void TempEmployee::set_termination_date(string new_termination_date)
    {
      termination_date = new_termination_date;
    }

    // overloaded insertion operator
    ostream &operator<<(ostream& out, const TempEmployee &employee)
    {
      out << "name:                 " << employee.get_name() << endl
          << "ssn:                  " << employee.get_ssn() << endl
          << "wage rate:            " << employee.get_rate() << endl
          << "hours:                " << employee.get_hours() << endl
          << "termination date:     " << employee.get_termination_date() << endl;

      return out;
    }

    // overloaded extraction operator
    istream &operator>>(istream &in, TempEmployee &employee)
    {
      string name, ssn, termination_date;
      int hours;
      double rate;
      cout << "Enter temp Employee Name: " ;
      in >> name;
      cout << "Enter temp Employee SSN: ";
      in >> ssn;
      cout << "Enter number of Hours Worked: ";
      in >> hours;
      cout << "Enter Rate: " ;
      in >> rate;
      cout << "Enter termination date: " ;
      in >> termination_date;

      employee.set_name(name);
      employee.set_hours(hours);
      employee.set_ssn(ssn);
      employee.set_rate(rate);
      employee.set_termination_date(termination_date);

      return in;
    }
