// This file constains the Pedometer class and it's functions.
#include <iostream>
#include <sstream>
#include <string>

using namespace std;

/**
 *  This class is a pedometer simulator
 */
class Pedometer
{
  private:
    int stepsTaken, strideLength;
  public:
    Pedometer(); // default constructor (0 params)
    Pedometer(int steps, int stride);
    void setSteps(int);
    int getSteps();
    void setStride(int);
    int getStride();
    void reset();
    void increment(int);
    friend ostream &operator<<(ostream& outputs, const Pedometer meter);
};

/**
 *  A default constructor.  It sets the steps to zero and the stride to 100.
 */
Pedometer::Pedometer()
{
  stepsTaken = 0;
  strideLength = 100; // centimeters
}

/**
 *  An overloaded constructor.  It sets the steps and the stride from the
 *  arguments.
 *  @param steps an integer. This is how many steps the user has taken.
 *  @param stride an integer.  This is the length of the user's stride in cm.
 */
Pedometer::Pedometer(int steps, int stride)
{
  stepsTaken = steps;
  strideLength = stride; // centimeters
}

/**
 *  a mutator function taking an integer.
 *  @param steps an integer.  This is how many steps the user has taken.
 */
void Pedometer::setSteps(int steps)
{
  stepsTaken = steps;
}

/**
 *  an accessor function getting the number of steps walked and returning an
 *  integer.
 *  @return The steps that have been walked.
 */
int Pedometer::getSteps()
{
  return stepsTaken;
}

/**
 *  a mutator function setting the stride length of the user, taking an integer.
 *  @param centimeters an integer.
 */
void Pedometer::setStride(int centimeters)
{
  strideLength = centimeters;
}

/**
 *  an accessor function returning an integer value.
 *  @return The stride length.
 */
int Pedometer::getStride()
{
  return strideLength; // centimeters
}

// overloads the insertion operator (<<) to recognize an ostream object on the
// left, and a Pedometer object on the right so that when one cout's a
// Pedometer object, steps walked, km walked, and Calories burned are displayed.
ostream &operator<<(ostream& output, const Pedometer meter)
{
  output << "You've taken " << meter.stepsTaken << " steps.\n";
  output << "Your stride length is " << meter.strideLength << " cm.\n";
  return output;
}

// // inputs the steps taken and stride length returning a pedometer.
// istream& operator >>(istream& input)
// {
//   int steps, stride;
//   input >> steps >> stride;
//   Pedometer customMeter(steps, stride);
//   return customMeter;
// }

/**
 *  a mutator function that sets the steps to zero.
 */
void Pedometer::reset()
{
  stepsTaken = 0;
}

/**
 *  increments the steps by the amount of the singular argument, an integer.
 *  @param steps an integer.
 *  @return void.
 */
void Pedometer::increment(int steps)
{
  for (int i = 0; i < steps; i++)
  {
    stepsTaken++;
  }
}
