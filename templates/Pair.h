// This file contains the implementation and definition of the Pair class

using namespace std;

template <class T>
class Pair
{
public:
  Pair();
  Pair(T first_value, T second_value);
  void set_element(int position, T value);
  // precondition: position is 1 or 2
  // postcondition: position indicated is set to value
  T get_element(int position);
  // precondition: position is 1 or 2
  // returns value in position indicated
private:
  T first;
  T second;
};

/*
template <class T>
Pair<T>::Pair(T first_value, T second_value) :
  first(first_value), second(second_value)
{
  // this block intentionally left blank
}
*/
