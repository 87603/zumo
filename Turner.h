#pragma once

#include <Zumo32U4.h>
#include <Wire.h>
#include "Motors.h"

class Turner {
private:
  Zumo32U4Encoders encoders;
  Motors *motor;
  bool turnDirection;
  int ticksNeeded;
public:
  Turner(Motors* m);
  void startTurn(int);
  bool update();
};