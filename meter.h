// #ifndef
#include <iostream>

using namespace std;

class Pedometer
{
  private:
    int stepsTaken, strideLength;
  public:
    Pedometer(); // constructor
    void setSteps(int);
    int getSteps();
    void setStride(int);
    int getStride();
};


Pedometer::Pedometer()
{
  stepsTaken = 0;
  strideLength = 100; // centimeters
}

void Pedometer::setSteps(int steps)
{
  stepsTaken = steps;
}

int Pedometer::getSteps()
{
  return stepsTaken;
}

void Pedometer::setStride(int centimeters)
{
  strideLength = centimeters;
}

int Pedometer::getStride()
{
  return strideLength;
}
