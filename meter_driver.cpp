#include "meter.h"

int main()
{
  cout << "The driver is running.\n";

  Pedometer meter;
  cout << "Your default stride length is " <<
       meter.getStride() << " centimeters.\n";
}
