#ifndef PROXIMITYINTERFACE_H
#define PROXIMITYINTERFACE_H

#include <Zumo32U4.h>

class ProximityInterface {
private:
    Zumo32U4ProximitySensors sensorArray;

public:
    ProximityInterface();
    int getDistance();
};

#endif