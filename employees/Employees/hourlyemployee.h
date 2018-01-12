//This is the header file hourlyemployee.h.
//This is the interface for the class HourlyEmployee.
#ifndef HOURLYEMPLOYEE_H
#define HOURLYEMPLOYEE_H

#include <string>
#include "employee.h"

using namespace std;



    class HourlyEmployee : public Employee
    {
    public:
        HourlyEmployee();
        HourlyEmployee(string the_name, string the_ssn,
                           double the_wage_rate, double the_hours);
        void set_rate(double new_wage_rate);
        double get_rate() const;
        void set_hours(double hours_worked);
        double get_hours() const;
        virtual void print_check() ;
        friend ostream &operator<<(ostream &out, const HourlyEmployee &employee);
        friend istream &operator>>(istream &in, HourlyEmployee &employee);
    private:
        double wage_rate;
        double hours;
    };


#endif //HOURLYMPLOYEE_H
