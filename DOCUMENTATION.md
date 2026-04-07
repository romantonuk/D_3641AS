# DOCUMENTATION

## struct ISoft_3641AS
DESCRIPTION : Simple driver interface for using 3641AS module.
PLACEMENT : Inside d_3641AS namespace.

## void display1(driver, digit, value)
DESCRIPTION : Function to turn on or off segments of specific digit. Each bit in a value represents a desired state of segment.
PLACEMENT : Inside d_3641AS namespace.
USAGE : display1(my_driver, 1, 0b00000001);

## void display4(driver, digit1value, digit2value, digit3value, digit4value)
DESCRIPTION : Function to turn on or off segments of all 4 digits. Each bit in a value of specific digit represents a desired state of segment on that digit.
PLACEMENT : Inside d_3641AS namespace.
USAGE : display4(my_driver, 0b00000001, 0b00000001, 0b00000001, 0b00000001);

## struct DirectPinsSoft_3641AS
DESCRIPTION : Driver for 3641AS module used for communicating with module using direct pins connections (without anything in-betwen like shift register).
PLACEMENT : Inside DefaultSoftDrivers_3641AS namespace.


### Check this [example] for detailed usage.

[example]: https://github.com/romantonuk/D_3641AS/blob/main/examples/Simple/simple.ino
