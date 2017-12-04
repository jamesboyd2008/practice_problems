//This is the file executiveemployee.cpp.
//This is the implementation for the class ExecutiveEmployee.
//The interface for the class ExecutiveEmployee is in
//the header file executiveemployee.h.

#include <iostream>
#include <string>
#include "executiveemployee.h"
using namespace std;

ExecutiveEmployee::ExecutiveEmployee() : SalariedEmployee()
{
  title = "Executive";
  aor = "everything";
  supervisor = "nobody";
  annual_salary = 0;
  bailout_bonus = 0;
  // vector<string> benefits = {"basic responsibility", "medical", "dental"};
  // grade = benefits;
}

ExecutiveEmployee::ExecutiveEmployee
(
  string the_name,
  string the_number,
  double the_weekly_salary,
  vector<string> benefits,
  string the_title,
  string the_aor,
  string the_supervisor,
  double the_annual_salary,
  double the_bailout_bonus
) : SalariedEmployee(the_name, the_number, the_weekly_salary, benefits)
{
  // will the_name and the_number take car of themselves?
  annual_salary = the_annual_salary;
  title = the_title;
  aor = the_aor;
  supervisor = the_supervisor;
  bailout_bonus = the_bailout_bonus;
}

// accessor function
string ExecutiveEmployee::get_title() const
{
  return title;
}

// mutator function
void ExecutiveEmployee::set_title(string new_title)
{
  title = new_title;
}

// accessor function
string ExecutiveEmployee::get_aor() const
{
  return aor;
}

// mutator function
void ExecutiveEmployee::set_aor(string new_aor)
{
  aor = new_aor;
}

// accessor function
string ExecutiveEmployee::get_supervisor() const
{
  return supervisor;
}

// mutator function
void ExecutiveEmployee::set_supervisor(string new_supervisor)
{
  supervisor = new_supervisor;
}

// accessor function
double ExecutiveEmployee::get_annual_salary() const
{
  return annual_salary;
}

// mutator function
void ExecutiveEmployee::set_annual_salary(double new_annual_salary)
{
  annual_salary = new_annual_salary;
}

// accessor function
double ExecutiveEmployee::get_bailout_bonus() const
{
  return bailout_bonus;
}

// mutator function
void ExecutiveEmployee::set_bailout_bonus(double new_bailout_bonus)
{
  bailout_bonus = new_bailout_bonus;
}

// overloaded insertion operator
ostream &operator<<(ostream& out, const ExecutiveEmployee &employee)
{
  vector<string> benefits = employee.get_grade();

  out << "name:                 " << employee.get_name() << endl
       << "ssn:                  " << employee.get_ssn() << endl
       << "weekly salary:        " << employee.get_salary() << endl
       << "annual salary:        " << employee.get_annual_salary() << endl
       << "responsibility level: " << benefits[0] << endl
       << "title:                " << employee.get_title() << endl
       << "aor:                  " << employee.get_aor() << endl
       << "supervisor:           " << employee.get_supervisor() << endl;

  for (int i = 1; i < benefits.size(); i++)
  {
    out << "benefit:              " << benefits[i] << endl;
  }

  return out;
}


// overloaded extraction operator
istream &operator>>(istream &in, ExecutiveEmployee &employee)
{
  string name, ssn, responsibility, response, benefit, title, aor, supervisor;
  bool more = true;
  vector<string> benefits;
  double weekly_salary, annual_salary, bailout_bonus;
  cout << "Enter executive Employee Name, without spaces: ";
  in >> name;
  cout << "Enter executive employee SSN: ";
  in >> ssn;
  cout << "Enter weekly salary: " ;
  in >> weekly_salary;
  cout << "Enter annual salary: " ;
  in >> annual_salary;
  cout << "Enter responsibility level: ";
  in >> responsibility;
  benefits.push_back(responsibility);
  cout << "Enter area of responsibility: ";
  in >> aor;
  cout << "Enter title: ";
  in >> title;
  cout << "Enter supervisor: ";
  in >> supervisor;

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
  employee.set_salary(weekly_salary); // weekly salary
  employee.set_annual_salary(annual_salary);
  employee.set_grade(benefits);
  employee.set_title(title);
  employee.set_aor(aor);
  employee.set_supervisor(supervisor);

  return in;
}

// overloaded insertion operator
void ExecutiveEmployee::print()
{
  vector<string> benefits = this->get_grade();

  cout << "name:                 " << this->get_name() << endl
       << "ssn:                  " << this->get_ssn() << endl
       << "weekly salary:        " << this->get_salary() << endl
       << "annual salary:        " << this->get_annual_salary() << endl
       << "responsibility level: " << benefits[0] << endl
       << "title:                " << this->get_title() << endl
       << "aor:                  " << this->get_aor() << endl
       << "supervisor:           " << this->get_supervisor() << endl;

  for (int i = 1; i < benefits.size(); i++)
  {
    cout << "benefit:              " << benefits[i] << endl;
  }
}

// log checks to console
void ExecutiveEmployee::print_check()
{
  set_net_pay(annual_salary);
  cout << "\n__________________________________________________\n";
  cout << "Pay to the order of " << get_name() << endl;
  cout << "The sum of " << get_annual_salary() << " Dollars\n";
  cout << "_________________________________________________\n";
  cout << "Check Stub NOT NEGOTIABLE \n";
  cout << "Employee Number: " << get_ssn() << endl;
  cout << "Salaried Employee. Regular Pay: "
       << salary << endl;
  cout << "Swiss Bank Account No.: " << "CH93 0076 2011 6238 5295 7" << endl;
  cout << "_________________________________________________\n";
}
