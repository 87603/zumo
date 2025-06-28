#pragma once

#include <Zumo32U4.h>
#include <Wire.h>
#include "Motors.h"

class Measurer {
private:
  Zumo32U4Encoders encoders;
  Motors *motor;
  int targetTicks;
public:
  Measurer(Motors *m);
  bool driveForward(int);
  bool update();
};