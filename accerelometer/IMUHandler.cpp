#include "IMUHandler.h"
#include <Wire.h>

IMUHandler::IMUHandler()
{
}

void IMUHandler::initialize()
{
    Wire.begin(); //start I2C communicatie

    if (!imu.init())
    {
        handleInitFailure(); // als imu niet kan starten, foutmelding
    }

    imu.enableDefault(); //sensor default instellingen activeren
}

void IMUHandler::handleInitFailure()
{
    ledRed(1); //als imu niet werkt zet rode led aan
    while (true)
    { // stuur foutmeldingen naar serial
        Serial.println(F("Failed to initialize IMU sensors."));
        delay(100);
    }
}

void IMUHandler::printSensorData()
{
    imu.read(); // lees alle sensorgegevens 

    snprintf_P(report, sizeof(report),
        PSTR("Accelerometer: %6d %6d %6d    Magnetometer: %6d %6d %6d    Gyroschoop: %6d %6d %6d"),
        imu.a.x, imu.a.y, imu.a.z,
        imu.m.x, imu.m.y, imu.m.z,
        imu.g.x, imu.g.y, imu.g.z);

    Serial.println(report); // druk alles af
}

// berekent kompasrichting 
// atan2 om hoek te berekenen 
float IMUHandler::getHeading()
{
float mx_offset = -2631;
float my_offset = -4739; // berekende gemiddelde offset 
    imu.readMag(); // alleen magnetometer uitlezen
    float heading = atan2( //offset voor kalibratie
      (float)imu.m.y - my_offset,
      (float)imu.m.x - mx_offset
    ) * 180 / PI; //hoek naar graden

    if (heading < 0)
        heading += 360; //resultaat is tussen 0 en 360
    return heading;
}

//ruwe data verzamlen 
float IMUHandler::getRawMagX() {
    imu.readMag();
    return imu.m.x;
}

float IMUHandler::getRawMagY() {
    imu.readMag();
    return imu.m.y;
}


