// this example uses wiring from examples/wiring.png

#include "d_3641AS.h"

using namespace d_3641AS;
using namespace DefaultSoftDrivers_3641AS;

// pins for module
uint8_t pins_3641AS[12] = {
  2, 3, 4, 5, 6, 8, 11, 12,   // segments (0-7)
  7, 9, 10, 13,               // digits (8-11)
};



DefaultSoftDrivers_3641AS::DirectPinsSoft_3641AS n = DefaultSoftDrivers_3641AS::DirectPinsSoft_3641AS(pins_3641AS);


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  n.setupPins();
}

void loop() {
  // put your main code here, to run repeatedly:
  display4(n, 0b10000000, 0b01000000, 0b00100000, 0b00010000);
}
