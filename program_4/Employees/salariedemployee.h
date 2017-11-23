//This is the header file salariedemployee.h.
//This is the interface for the class SalariedEmployee.
#ifndef SALARIEDEMPLOYEE_H
#define SALARIEDEMPLOYEE_H

#include <string>
#include <vector>
#include "employee.cpp"

using namespace std;

    class SalariedEmployee : public Employee
    {
    public:
        SalariedEmployee();
        SalariedEmployee
        (
          string the_name,
          string the_ssn,
          double the_weekly_salary,
          vector<string> benefits
        );
        double get_salary() const;
        void set_salary(double new_salary);
        vector<string> get_grade() const;
        void set_grade(vector<string> new_grade);
        virtual void print_check();
        friend ostream &operator<<(ostream &out, const SalariedEmployee &employee);
        friend istream &operator>>(istream &in, SalariedEmployee &employee);
    protected:
        double salary;//weekly
        vector<string> grade; // grade[0] is the grade, grade[1+] is benefits
    };



#endif //SALARIEDEMPLOYEE_H
