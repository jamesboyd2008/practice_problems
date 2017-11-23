#include <iostream>
#include <string>
#include <vector>
#include "hourlyemployee.cpp"
#include "salariedemployee.cpp"
#include "executiveemployee.cpp"
using namespace std;

void menu(int& choice, bool entered);

int main()
{
	string name;
	string ssn;
	int hours;
	double salary, rate;
	vector<string> benefits = { "basic responsibility", "medical", "dental" };

	// SalariedEmployee CEO("Todd Davis", "457-55-5462", 54.62, benefits);
	SalariedEmployee CEO;
	cin >> CEO;
	cout << endl;
	// CEO.print_check();

  HourlyEmployee joe;
	cin >> joe;
	cout << endl;

	ExecutiveEmployee doinkles;
	cin >> doinkles;
	// joe.set_name(name);
	// joe.set_hours(hours);
	// joe.set_ssn(ssn);
	// joe.set_rate(rate);


  cout << "Check for " << joe.get_name()
       << " for " << joe.get_hours() << " hours.\n";
  joe.print_check();

	cout << joe << "\n";
	cout << CEO << "\n";
	doinkles.print();
	cout << "\n";

	cout << "Check for " << doinkles.get_name() << ":\n";
	doinkles.print_check();

  return 0;
}

void menu(int& choice, bool entered)
{
	if (entered)
	{
	cout << "Menu" << endl;
	cout << "-------" << endl;
	cout << "1: View Employee";
	cout << "2: Print Cheque";
	}
	else
	{
		cout << "1: Enter an employee" << endl;
	}
}
