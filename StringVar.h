//DISPLAY 11.12 Implementation of StringVar
//This is the implementation of the class StringVar.
//The definition for the class StringVar is in Display 11.11.
#include <iostream>
#include <cstdlib>
#include <cstddef>
#include <cstring>
using namespace std;

class StringVar
{
  public:
    StringVar(int size);
    //Initializes the object so it can accept string values up to size
    //in length. Sets the value of the object equal to the empty string.

    StringVar( );
    //Initializes the object so it can accept string values of length 100
    //or less. Sets the value of the object equal to the empty string.

    StringVar(const char a[]);
    //Precondition: The array a contains characters terminated with '\0'.
    //Initializes the object so its value is the string stored in a and
    //so that it can later be set to string values up to strlen(a) in length

    StringVar(const StringVar& string_object);
    //Copy constructor.

    ~StringVar( );
    //Returns all the dynamic memory used by the object to the freestore.

    int length( ) const;
    //Returns the length of the current string value.

    void input_line(istream& ins);
    //Precondition: If ins is a file input stream, then ins has been
    //connected to a file.
    //Action: The next text in the input stream ins, up to '\n', is copied
    //to the calling object. If there is not sufficient room, then
    //only as much as will fit is copied.

    friend ostream& operator <<(ostream& outs, const StringVar& the_string);
    //Overloads the << operator so it can be used to output values
    //of type StringVar
    //Precondition: If outs is a file output stream, then outs
    //has already been connected to a file.

    // void operator = (const StringVar& right_side)
    StringVar& operator=(const StringVar &right);

  private:
    char *value; //pointer to dynamic array that holds the string value.
    int max_length; //declared max length of any string value.
};

//Uses cstddef and cstdlib:
StringVar::StringVar(int size) : max_length(size)
{
    value = new char[max_length + 1];//+1 is for '\0'.
    value[0] = '\0';
}

//Uses cstddef and cstdlib:
StringVar::StringVar( ) : max_length(100)
{
    value = new char[max_length + 1];//+1 is for '\0'.
    value[0] = '\0';
}

//Uses cstring, cstddef, and cstdlib:
StringVar::StringVar(const char a[]) : max_length(strlen(a))
{
    value = new char[max_length + 1];//+1 is for '\0'.
    strcpy(value, a);
}

//Uses cstring, cstddef, and cstdlib:
StringVar::StringVar(const StringVar& string_object)
                        : max_length(string_object.length( ))
{
    value = new char[max_length + 1];//+1 is for '\0'.
    strcpy(value, string_object.value);
}

StringVar::~StringVar( )
{
    delete [] value;
}

//Uses cstring:
int StringVar::length( ) const
{
    return strlen(value);
}

//Uses iostream:
void StringVar::input_line(istream& ins)
{
    ins.getline(value, max_length + 1);
}

//Uses iostream:
ostream& operator <<(ostream& outs, const StringVar& the_string)
{
    outs << the_string.value;
    return outs;
}

StringVar& StringVar::operator=(const StringVar &right)
{
  if (this != &right)
  {
    delete [] value;
    int new_length = right.length();
    max_length = new_length;
    value = new char[new_length + 1];

    for (int index = 0; index < new_length; index++)
    {
      value[index] = right.value[index];
    }

    value[new_length] = '\0';
  }
  return *this;
}
