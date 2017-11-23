// This is the header file executiveemployee.h
// This is the interface for the class ExecutiveEmployee.
#ifndef EXECUTIVEEMPLOYEE_H
#define EXECUTIVEEMPLOYEE_H

#include <string>
#include "salariedemployee.h"

using namespace std;

class ExecutiveEmployee : public SalariedEmployee
{
public:
  ExecutiveEmployee( );
  ExecutiveEmployee
  (
    string the_name,
    string the_ssn,
    double the_weekly_salary,
    vector<string> benefits,
    string the_title,
    string the_aor,
    string the_supervisor,
    double the_annual_salary,
    double the_bailout_bonus
  );
private:
  string title;
  string aor; // area of responsibility
  string supervisor;
  double annual_salary;
  double bailout_bonus;
};

#endif // EXECUTIVEEMPLOYEE_H
