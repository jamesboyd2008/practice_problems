//This is the header file salariedemployee.h.
//This is the interface for the class SalariedEmployee.
#ifndef SALARIEDEMPLOYEE_H
#define SALARIEDEMPLOYEE_H

#include <string>
#include "employee.cpp"

using namespace std;

    class SalariedEmployee : public Employee
    {
    public:
        SalariedEmployee( );
        SalariedEmployee (string the_name, string the_ssn,
                                  double the_weekly_salary);
        double get_salary( ) const;
        void set_salary(double new_salary);
        void print_check( );
        friend ostream &operator<<(ostream &out, const SalariedEmployee &employee);
        friend istream &operator>>(istream &in, SalariedEmployee &employee);
    private:
        double salary;//weekly
    };



#endif //SALARIEDEMPLOYEE_H
