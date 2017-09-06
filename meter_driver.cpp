// This program simulates a pedometer.
#include "meter.h"

int main()
{
  cout << "The driver is running.\n";

  Pedometer meter;
  cout << "Your default stride length is " << meter.getStride() << " centimeters.\n";

  Pedometer customMeter(42, 1000);
  cout << "Your custom step count is: " << customMeter.getSteps() << endl;
  cout << "Your custom stride length is: " << customMeter.getStride() << endl;

  customMeter.reset();
  cout << "Your custom step count, after reset, is: " <<
       customMeter.getSteps() << endl;

}
