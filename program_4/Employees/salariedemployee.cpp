
//This is the file salariedemployee.cpp.
//This is the implementation for the class SalariedEmployee.
//The interface for the class SalariedEmployee is in
//the header file salariedemployee.h.
// needs vector
#include <iostream>
#include <string>
#include "salariedemployee.h"
using namespace std;


    SalariedEmployee::SalariedEmployee( ) : Employee( )//, salary(0)
    {
      salary = 0;
      // grade[0] = "basic";
      // grade[1] = "medical";
      // grade[2] = "dental";
      grade = {"basic responsibility", "medical", "dental"};
    }

    SalariedEmployee::SalariedEmployee
    (
      string the_name,
      string the_number,
      double the_weekly_salary,
      vector<string> benefits
    )
                     : Employee(the_name, the_number)//, salary(the_weekly_salary)
    {
      salary = the_weekly_salary;
      grade = benefits;
    }

    double SalariedEmployee::get_salary( ) const
    {
      return salary;
    }

    void SalariedEmployee::set_salary(double new_salary)
    {
      salary = new_salary;
    }

    vector<string> SalariedEmployee::get_grade( ) const
    {
      return grade;
    }

    void SalariedEmployee::set_grade(vector<string> new_grade)
    {
      grade = new_grade;
    }

    void SalariedEmployee::print_check( )
    {
      set_net_pay(salary);
      cout << "\n__________________________________________________\n";
      cout << "Pay to the order of " << get_name( ) << endl;
      cout << "The sum of " << get_net_pay( ) << " Dollars\n";
      cout << "_________________________________________________\n";
      cout << "Check Stub NOT NEGOTIABLE \n";
      cout << "Employee Number: " << get_ssn( ) << endl;
      cout << "Salaried Employee. Regular Pay: "
           << salary << endl;
      cout << "_________________________________________________\n";
    }

    // overloaded insertion operator
    ostream &operator<<(ostream& out, const SalariedEmployee &employee)
    {
      vector<string> benefits = employee.get_grade();

      out << "name:                 " << employee.get_name() << endl
          << "ssn:                  " << employee.get_ssn() << endl
          << "salary:               " << employee.get_salary() << endl
          << "responsibility level: " << benefits[0] << endl;

      for (int i = 1; i < benefits.size(); i++)
      {
        out << "benefit:              " << benefits[i] << endl;
      }

      return out;
    }

    // overloaded extraction operator
    istream &operator>>(istream &in, SalariedEmployee &employee)
    {
      string name, ssn, responsibility, response, benefit;
      bool more = true;
      vector<string> benefits;
      double salary;
      cout << "Enter salaried employee name: ";
      in >> name;
      cout << "Enter salaried employee SSN: ";
      in >> ssn;
      cout << "Enter salary: " ;
      in >> salary;
      cout << "Enter responsibility level: ";
      in >> responsibility;
      benefits.push_back(responsibility);

      while (more)
      {
        cout << "Any more benefits? (y/n): ";
        in >> response;
        if (response == "y")
        {
          cout << "Enter the benefit: ";
          in >> benefit;
          benefits.push_back(benefit);
        }
        else
          more = false;
      }

      employee.set_name(name);
      employee.set_ssn(ssn);
      employee.set_salary(salary);
      employee.set_grade(benefits);

      return in;
    }
