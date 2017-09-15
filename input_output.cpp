#include <iostream>
#include <sstream>
#include <string>

using namespace std;

int main ()
{
  cout << "Input two integers: ";
  string numbers;
  // getline(cin >> ws, numbers);
  getline(cin, numbers);

  istringstream istr(numbers);
  ostringstream ostr;

  int num_one, num_two;
  istr >> num_one >> num_two;

  ostr << "The two integers, and their average: "
       << (float)(num_one) << " "
       << (float)(num_two) << " "
       << (num_one + num_two) / 2.0 << "\n";
  
  cout << ostr.str();
  return 0;
}
