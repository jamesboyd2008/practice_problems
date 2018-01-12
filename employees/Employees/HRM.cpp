/*
This is the application file for the Human Resource Management program.
This is the driver.
*/
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "hourlyemployee.cpp"
#include "tempemployee.cpp"
#include "salariedemployee.cpp"
#include "executiveemployee.cpp"

using namespace std;

int main()
{
	HourlyEmployee hourlies[100];
	TempEmployee temps[100];
	SalariedEmployee salarieds[100];
	ExecutiveEmployee executives[100];

	int hourly_count, temp_count, salaried_count, executive_count;
	hourly_count=temp_count=salaried_count=executive_count=0;

	HourlyEmployee hourly_employee;
	TempEmployee temp_employee;
	SalariedEmployee salaried_employee;
	ExecutiveEmployee executive_employee;

  int choice;
  bool keep_going = true;
	string name;

	// this keeps the user cycling through the menu until they choose to quit
	while (keep_going)
	{
  	cout << "---------------------------------------------------------" << endl;
    cout << "Pick a number:\n";
  	cout << "1: Enter an employee's information\n";
  	cout << "2: Modify an employee's information\n";
  	cout << "3: Display an employee's information\n";
  	cout << "4: Monthly Payroll: print cheques for all employees\n";
  	cout << "5: Employment Report: output all employee info to a file\n";
    cout << "6: exit\n";
    cout << "---------------------------------------------------------\n\n";

    cin >> choice;
		cout << endl;
		if (choice == 6) // exit
			keep_going = false;

		// create employee ----------------------------------------------
		else if (choice == 1)
		{
			cout << "You chose to create an employee.\n"
			     << "Choose an employee type:\n"
			     << "1: hourly employee\n"
					 << "2: salaried employee\n"
					 << "3: executive employee\n"
					 << "4: temp employee\n\n";

			cin >> choice;
			cout << endl;

			if (choice == 1) // hourly
			{
				cout << "You chose to create an hourly employee.\n";
				cin >> hourly_employee;
				cout << endl;
				hourlies[hourly_count] = hourly_employee;
				hourly_count++;
			}
			else if (choice == 2) // salaried
			{
				cout << "You chose to create a salaried employee.\n";
				cin >> salaried_employee;
				cout << endl;
				salarieds[salaried_count] = salaried_employee;
				salaried_count++;
			}
			else if (choice == 3) // executive
			{
				cout << "You chose to create an executive employee.\n";
				cin >> executive_employee;
				cout << endl;
				executives[executive_count] = executive_employee;
				executive_count++;
			}
			else if (choice == 4) // temp
			{
				cout << "You chose to create a temp employee.\n";
				cin >> temp_employee;
				cout << endl;
				temps[temp_count] = temp_employee;
				temp_count++;
			}
			else
				cout << "Please try again.\n";

		}

		// modify an employee ------------------------------------------------
		else if (choice == 2)
		{
			cout << "You chose to modify an employee.\n";
			cout << "Enter the employee's name: ";
			cin >> name;
			bool found = false;

			// search through all the hourlies
			for (int i = 0; i < hourly_count; i++)
			{
				if (hourlies[i].get_name() == name)
				{
					found = true;
					cout << "We found that employee.\nPlease enter their info:\n";
					cin >> hourlies[i];
					cout << endl;
					break;
				}
			}

			// search through all the temps
			if (!found)
			{
				for (int i = 0; i < temp_count; i++)
				{
					if (temps[i].get_name() == name)
					{
						found = true;
						cout << "We found that employee.\nPlease enter their info:\n";
						cin >> temps[i];
						cout << endl;
						break;
					}
				}
			}

			// search through all the salarieds
			if (!found)
			{
				for (int i = 0; i < salaried_count; i++)
				{
					if (salarieds[i].get_name() == name)
					{
						found = true;
						cout << "We found that employee.\nPlease enter their info:\n";
						cin >> salarieds[i];
						cout << endl;
						break;
					}
				}
			}

			// search through all the executives
			if (!found)
			{
				for (int i = 0; i < executive_count; i++)
						{
					if (executives[i].get_name() == name)
					{
						found = true;
						cout << "We found that employee.\nPlease enter their info:\n";
						cin >> executives[i];
						cout << endl;
						break;
					}
				}
			}

			if (!found)
				cout << "We could not find that employee\n\n";
		}

		// display an employee -----------------------------------------------
		else if (choice == 3)
		{
			cout << "You chose to display an employee.\n";
			cout << "Enter the employee's name: ";
			cin >> name;
			bool found = false;

			// search through all the hourlies
			for (int i = 0; i < hourly_count; i++)
			{
				if (hourlies[i].get_name() == name)
				{
					found = true;
					cout << "We found that employee.\nHere is their info:\n";
					cout << hourlies[i];
					cout << endl;
					break;
				}
			}

			// search through all the temps
			if (!found)
			{
				for (int i = 0; i < temp_count; i++)
				{
					if (temps[i].get_name() == name)
					{
						found = true;
						cout << "We found that employee.\nHere is their info:\n";
						cout << temps[i];
						cout << endl;
						break;
					}
				}
			}

			// search through all the salarieds
			if (!found)
			{
				for (int i = 0; i < salaried_count; i++)
				{
					if (salarieds[i].get_name() == name)
					{
						found = true;
						cout << "We found that employee.\nHere is their info:\n";
						cout << salarieds[i];
						cout << endl;
						break;
					}
				}
			}

			// search through all the executives
			if (!found)
			{
				for (int i = 0; i < executive_count; i++)
						{
					if (executives[i].get_name() == name)
					{
						found = true;
						cout << "We found that employee.\nHere is their info:\n";
						executives[i].print();
						cout << endl;
						break;
					}
				}
			}

			if (!found)
				cout << "We could not find that employee\n\n";
		}

		// print all checks --------------------------------------------------
		else if (choice == 4)
		{
			for (int i = 0; i < hourly_count; i++)
			{
				hourlies[i].print_check();
			}
			for (int i = 0; i < temp_count; i++)
			{
				temps[i].print_check();
			}
			for (int i = 0; i < salaried_count; i++)
			{
				salarieds[i].print_check();
			}
			for (int i = 0; i < executive_count; i++)
			{
				executives[i].print_check();
			}
		}

		// output full report to a text file --------------------------------------
		else if (choice == 5)
		{
			ofstream output_file;
			output_file.open("employee_data.txt");
			output_file << "\n";

			for (int i = 0; i < hourly_count; i++)
			{
				output_file << hourlies[i] << endl;;
			}
			for (int i = 0; i < temp_count; i++)
			{
				output_file << temps[i] << endl;;
			}
			for (int i = 0; i < salaried_count; i++)
			{
				output_file << salarieds[i] << endl;;
			}
			for (int i = 0; i < executive_count; i++)
			{
				output_file << executives[i] << endl;;
			}

			output_file.close();

			cout << "The employeed data is in employee_data.txt\n";
		}
	}

  return 0;
}
