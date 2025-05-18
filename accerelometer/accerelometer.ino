/* This example reads the raw values from the accelerometer,
magnetometer, and gyro on the Zumo 32U4, and prints those raw
values to the serial monitor.

The accelerometer readings can be converted to units of g using
the sensitivity specified in the LSM303 or LSM6DS33 datasheet.
The default full-scale (FS) setting is +/- 2 g, so the conversion
factor is 0.061 mg/LSB (least-significant bit).  A raw reading of
16384 would correspond to 1 g.

The gyro readings can be converted to degrees per second (dps)
using the sensitivity specified in the L3GD20H or LSM6DS33
datasheet.  The default sensitivity is 8.75 mdps/LSB (least-
significant bit).  A raw reading of 10285 would correspond to
90 dps.

The magnetometer readings are more difficult to interpret and
will usually require calibration. */



#include "IMUHandler.h"
using namespace std;

IMUHandler imuHandler;

void setup()
{
    Serial.begin(9600);
    imuHandler.initialize();
}

void loop()
{
    imuHandler.printSensorData();
    delay(100);
    float heading = imuHandler.getHeading();
    Serial.print("Heading: ");
    Serial.print(heading);
    Serial.println(" degrees");
// float mx = imuHandler.getRawMagX();
// float my = imuHandler.getRawMagY();

// Serial.print("mx: ");
// Serial.print(mx);
// Serial.print(" my: ");
// Serial.println(my);

    delay(200);
}

