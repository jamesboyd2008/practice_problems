// This program is a pointer experiment.
#include <iostream>

using namespace std;

int main() {

  // Declare a pointer of type integer called p1.
  int *p1;

  // Declare an integer called v1.
  int v1;

  // Set v1 equal to 42.
  v1 = 42;

  // Use the address operator, &, to have p1 point to v1.
  p1 = &v1;

  // Change the value of what p1 is pointing at
  // to 43 using the dereferencing operator.
  *p1 = 43;

  // Output the values for v1, p1, &v1 and *p1.
  cout << "v1: " << v1 << endl;
  cout << "p1: " << p1 << endl;
  cout << "&v1: " << &v1 << endl;
  cout << "*p1: " << *p1 << endl;

  // Add the command `p1 = new int` after your output from part 1.
  p1 = new int;

  // Prompt user for input.
  cout << "Gimme dat value: ";

  // Use cin to obtain a value for what p1 is pointing at.
  cin >> *p1;

  // Output the values for v1, p1, &v1 and *p1.
  cout << "After using the \'new\' command: \n";
  cout << "v1: " << v1 << endl;
  cout << "p1: " << p1 << endl;
  cout << "&v1: " << &v1 << endl;
  cout << "*p1: " << *p1 << endl;

  delete p1;
  p1 = nullptr;

  // Use typedef to make an integer pointer type.
  typedef int *IntPtr;

  // Declare two integer pointers p1 and p2.
  IntPtr p2, p3;

  // Declare an integer variable called v1.
  int v2;

  // Allocate memory locations for p1 and p2 using the new command.
  p2 = new int;
  p3 = new int;

  // Prompt user for input.
  cout << "Please input a value: ";

  // Get input for v1.
  cin >> v2;

  // Set p1 to point to v1.
  p2 = &v2;

  // Set p2 to point to p1.
  // p3 = &p2; //==> throws an error
  // *p3 = p2; //==> throws an error
  p3 = p2;

  // Output the values of v1, p1, p2, &v1, *p1 and *p2.
  cout << "v2: " << v2 << endl;
  cout << "p2: " << p2 << endl;
  cout << "p3: " << p3 << endl;
  cout << "&v2: " << &v1 << endl;
  cout << "*p2: " << *p2 << endl;
  cout << "*p3: " << *p3 << endl;

  // delet p1.
  // pickup here
  // delete p2;
  // p2 = nullptr;
  //
  // p3 = new int;

  // Output the values of v1, p1, p2, &v1, *p1 and *p2.
  //==> throws an error.
  cout << "v2: " << v2 << endl;
  cout << "p2: " << p2 << endl;
  cout << "p3: " << p3 << endl;
  cout << "&v2: " << &v1 << endl;
  cout << "*p2: " << *p2 << endl;
  cout << "*p3: " << *p3 << endl;

  return 0;
}
