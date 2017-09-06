// This file constains the Pedometer class and it's functions
#include <iostream>

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

// // outputs the numbers of steps walked, km walked, and Calories burned,
// // returning a string.
// ostream& operator <<(ostream& output, const Pedometer& meter)
// {
//   output << "You've taken " << meter.stepsTaken << " steps.\n";
//   output << "Your stride is " << meter.strideLength << " cm.\n";
//   return output;
// }
//
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

// Increment – We are going to cheat a little bit and allow the pedometer to increment by any amount of steps, provided that it is a positive integer.

void Pedometer::increment(int steps)
{
  
}
