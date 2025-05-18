#pragma once
#include <Zumo32U4.h>

class IMUHandler
{
public:
    IMUHandler(); // constructor
    void initialize(); //start imu op
    void printSensorData(); //leest waardes en print ze uit
    float getHeading(); //bereken kompasrichting
    float getRawMagX(); //rauwe data
    float getRawMagY(); //rauwe data


private:
    Zumo32U4IMU imu; //object van de imu sensor 
    char report[120]; //buffer om een tekstbericht met sensorwaarden te formatteren voor serial print

    void handleInitFailure(); //aanroepen als imu niet goed start
};
