//This is the file executiveemployee.cpp.
//This is the implementation for the class ExecutiveEmployee.
//The interface for the class ExecutiveEmployee is in
//the header file executiveemployee.h.

#include <iostream>
#include <string>
#include "executiveemployee.h"
using namespace std;

ExecutiveEmployee::ExecutiveEmployee( ) : SalariedEmployee( )
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
