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
  ExecutiveEmployee();
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
  string get_title() const;
  void set_title(string new_title);
  string get_aor() const;
  void set_aor(string new_aor);
  string get_supervisor() const;
  void set_supervisor(string new_supervisor);
  double get_annual_salary() const;
  void set_annual_salary(double new_annual_salary);
  double get_bailout_bonus() const;
  void set_bailout_bonus(double new_bailout_bonus);
  friend istream &operator>>(istream &in, ExecutiveEmployee &employee);
  void print();
  virtual void print_check();
private:
  string title;
  string aor; // area of responsibility
  string supervisor;
  double annual_salary;
  double bailout_bonus;
};

#endif // EXECUTIVEEMPLOYEE_H
