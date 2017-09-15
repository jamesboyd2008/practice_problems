//Sorts a list of numbers entered at the keyboard.
#include <iostream>
#include <cstdlib>
#include <cstddef>
using namespace std;

typedef int* IntArrayPtr;

void fill_array(int a[], int size);
//Precondition: size is the size of the array a.
//Postcondition: a[0] through a[size-1] have been
//filled with values read from the keyboard.

void sort(int a[], int size);
//Precondition: size is the size of the array a.
//The array elements a[0] through a[size-1] have values.
//Postcondition: The values of a[0] through a[size-1] have been rearranged
//so that a[0] <= a[1] <= ... <= a[size-1].

void swap_values(int& v1, int& v2);
//Interchanges the values of v1 and v2.

int index_of_smallest(const int a[], int start_index, int number_used);
//Precondition: 0 <= start_index < number_used. References array elements have
//values.
//Returns the index i such that a[i] is the smallest of the values
//a[start_index], a[start_index + 1], ..., a[number_used - 1].


int main( )
{
  cout << "This program sorts numbers from lowest to highest.\n";

  int array_size;
  cout << "How many numbers will be sorted? ";
  cin >> array_size;

  IntArrayPtr a;
  a = new int[array_size];

  fill_array(a, array_size);

  // swap_values(a[0], a[1]);
  // cout << "a[0]: " << a[0] << "\n";
  // cout << "a[1]: " << a[1] << "\n";

  // cout << "index of smallest: " << index_of_smallest(a, 0, 10) << "\n";

  // sort(a, array_size);
  //
  // cout << "In sorted order the numbers are:\n";
  // for (int index = 0; index < array_size; index++)
  //   cout << a[index] << " ";
  // cout << endl;
  //
	// system("pause");
  //   delete [] a;
	// system("pause");

  return 0;
}

//Uses the library iostream:
void fill_array(int a[], int size)
{
    using namespace std;
    cout << "Enter " << size << " integers.\n";
    for (int index = 0; index < size; index++)
        cin >> a[index];
}

//Interchanges the values of v1 and v2.
void swap_values(int& v1, int& v2)
{
  int temp;
  temp = v1;
  v1 = v2;
  v2 = temp;
}

//Precondition: 0 <= start_index < number_used. References array elements have
//values.
//Returns the index i such that a[i] is the smallest of the values
//a[start_index], a[start_index + 1], ..., a[number_used - 1].
int index_of_smallest(const int a[], int start_index, int number_used)
{
  int smallest_position = start_index;

  for (int i = start_index; i < number_used; i++)
  {
    if (a[i] < a[smallest_position])
      smallest_position = i;
  }
  return smallest_position;
}

//Precondition: size is the size of the array a.
//The array elements a[0] through a[size-1] have values.
//Postcondition: The values of a[0] through a[size-1] have been rearranged
//so that a[0] <= a[1] <= ... <= a[size-1].
void sort(int a[], int size)
{
  // use the two above functions to sort the input array
  
}
