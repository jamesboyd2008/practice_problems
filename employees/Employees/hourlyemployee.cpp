//This is the file: hourlyemployee.cpp
//This is the implementation for the class HourlyEmployee.
//The interface for the class HourlyEmployee is in
//the header file hourlyemployee.h.
#include <string>
#include <iostream>
#include "hourlyemployee.h"
using namespace std;



    HourlyEmployee::HourlyEmployee() : Employee(), wage_rate(0), hours(0)
    {
        //deliberately empty
    }

    HourlyEmployee::HourlyEmployee(string the_name, string the_number,
                                   double the_wage_rate, double the_hours)
    : Employee(the_name, the_number), wage_rate(the_wage_rate), hours(the_hours)
    {
        //deliberately empty
    }

    // mutator member
    void HourlyEmployee::set_rate(double new_wage_rate)
    {
        wage_rate = new_wage_rate;
    }

    // accessor member
    double HourlyEmployee::get_rate() const
    {
        return wage_rate;
    }

    // mutator member
    void HourlyEmployee::set_hours(double hours_worked)
    {
        hours = hours_worked;
    }

    // accessor member
    double HourlyEmployee::get_hours() const
    {
        return hours;
    }

    // log checks to console
    void HourlyEmployee::print_check()
    {
        set_net_pay(hours * wage_rate);

        cout << "\n________________________________________________\n";
        cout << "Pay to the order of " << get_name() << endl;
        cout << "The sum of " << get_net_pay() << " Dollars\n";
        cout << "________________________________________________\n";
        cout << "Check Stub: NOT NEGOTIABLE\n";
        cout << "Employee Number: " << get_ssn() << endl;
        cout << "Hourly Employee. \nHours worked: " << hours
             << " Rate: " << wage_rate << " Pay: " << get_net_pay() << endl;
        cout << "_________________________________________________\n";
    }

    // overloaded insertion operator
    ostream &operator<<(ostream& out, const HourlyEmployee &employee)
    {
      out << "name:                 " << employee.get_name() << endl
          << "ssn:                  " << employee.get_ssn() << endl
          << "wage rate:            " << employee.get_rate() << endl
          << "hours:                " << employee.get_hours() << endl;

      return out;
    }

    // overloaded extraction operator
    istream &operator>>(istream &in, HourlyEmployee &employee)
    {
      string name, ssn;
      int hours;
      double rate;
      cout << "Enter hourly Employee Name, without spaces: " ;
      in >> name;
      cout << "Enter hourly Employee SSN: ";
      in >> ssn;
      cout << "Enter number of Hours Worked: ";
      in >> hours;
      cout << "Enter hourly Rate: " ;
      in >> rate;

      employee.set_name(name);
      employee.set_hours(hours);
      employee.set_ssn(ssn);
      employee.set_rate(rate);

      return in;
    }
