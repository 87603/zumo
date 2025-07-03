#include "ProximityInterface.h"

ProximityInterface::ProximityInterface() {
    sensorArray.initFrontSensor();  
}

int ProximityInterface::getDistance() {
    sensorArray.read();  

    
    int leftLed = sensorArray.countsFrontWithLeftLeds();
    int rightLed = sensorArray.countsFrontWithRightLeds();
    
    return (leftLed + rightLed) / 2;
}