// This file contains the implementation and definition of the Pair class

using namespace std;

template <class T1, class T2>
class Pair
{
public:
  Pair();
  Pair(T1 first_value, T2 second_value);
  void set_first(T1 value);
  void set_second(T2 value);
  // precondition: position is 1 or 2
  // postcondition: position indicated is set to value
  T1 get_first();
  T2 get_second();
  // precondition: position is 1 or 2
  // returns value in position indicated
  template <class U1, class U2>
  friend ostream &operator<<(ostream &out, Pair<U1, U2> value);
private:
  T1 first;
  T2 second;
};

// overloaded constructor function
template <class T1, class T2>
Pair<T1, T2>::Pair(T1 first_value, T2 second_value) :
  first(first_value), second(second_value)
{
  // this block intentionally left blank
}

// mutator function
template <class T1, class T2>
void Pair<T1, T2>::set_first(T1 value)
{
  first = value;
}

// mutator function
template <class T1, class T2>
void Pair<T1, T2>::set_second(T2 value)
{
  second = value;
}

// accessor function
template <class T1, class T2>
T1 Pair<T1, T2>::get_first()
{
  return first;
}

// accessor function
template <class T1, class T2>
T2 Pair<T1, T2>::get_second()
{
  return second;
}

// overloaded extraction operator
template <class T1, class T2>
ostream &operator<<(ostream& out, Pair<T1, T2> value)
{
  out << value.get_first() << endl << value.get_second() << endl;
  return out;
}
