#pragma once

#include <Zumo32U4.h>
#include <Wire.h>
#include "Motors.h"

class Turner {
private:
  Zumo32U4Encoders encoders;
  Motors motor;
  bool turnDirection;
  uint16_t ticksNeeded;
public:
  Turner();
  void startTurn(int);
  bool update();
};