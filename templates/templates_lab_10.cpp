//Program to demonstrate a function template.
#include <iostream>
#include "Pair.h"
using namespace std;

//Interchanges the values of variable1 and variable2.
template<class T>
void swap_values(T& variable1, T& variable2)
{
  T temp;
  temp = variable1;
  variable1 = variable2;
  variable2 = temp;
}

//Interchanges the values of variable1 and variable2.
template<class T1, class T2>
void swap_values(T1& variable1, T2& variable2)
{
  T2 temp;
  temp = static_cast<T2>(variable1);
  variable1 = static_cast<T1>(variable2);
  variable2 = temp;
}

template<class T>
T min(T arr[], int arr_size)
{
  T small = arr[0];
  for (int i = 0; i < arr_size; i++)
  {
    if (arr[i] < small)
      small = arr[i];
  }
  return small;
}

int main( )
{
  int integer1 = 1, integer2 = 90;
  // cout << "Original integer values are "
  //      << integer1 << " " << integer2 << endl;
  swap_values(integer1, integer2);
  // cout << "Swapped integer values are "
  //      << integer1 << " " << integer2 << endl;

  char symbol1 = 'A', symbol2 = 'B';
  // cout << "Original character values are "
  //      << symbol1 << " " << symbol2 << endl;
  swap_values(symbol1, symbol2);
  // cout << "Swapped character values are "
  //      << symbol1 << " " << symbol2 << endl;

   double v1 = 3.14; // Pi
   double v2 = 67.9;

	swap_values(v1, v2);
	// cout << "Swapped double values are "
	// 	<< v1 << " " << v2 << endl;

  cout << "Original int and char values are "
       << integer1 << " " << symbol1 << endl;
  swap_values(integer1, symbol1);
  cout << "Swapped int and char values are "
       << integer1 << " " << symbol1 << endl;

  cout << "Original double and char values are "
       << v1 << " " << symbol1 << endl;
  swap_values(v1, symbol1);
  cout << "Swapped double and char values are "
       << v1 << " " << symbol1 << endl;

  long big_num = 3141592653589793238;

  cout << "Original long and char values are "
       << big_num << " " << symbol1 << endl;
  swap_values(big_num, symbol1);
  cout << "Swapped long and char values are "
       << big_num << " " << symbol1 << endl;

  int arr1[4] = { 3, 1, 2 };
  cout << "Minimum value in an integer array is: " << min(arr1, 3) << endl;

  char arr2[4] = { 'b', 'c', 'a' };
  cout << "Minimum value in a character array is: " << min(arr2, 3) << endl;

  float arr3[4] = { 2.33, 1.2, 8.9 };
  cout << "Minimum value in a float array is: " << min(arr3, 3) << endl;

  return 0;
}
