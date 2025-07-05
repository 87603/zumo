#pragma once

#include <Zumo32U4.h>
#include <Wire.h>
#include "Motors.h"

/*! Klasse voor draaien op basis van graden
berekent aantal ticks dat nodig is voor de draai en stopt zodra dit bereikt is */

class Turner {
private:
  Zumo32U4Encoders encoders;
  Motors motor;
  bool turnDirection;
  uint16_t ticksNeeded;
  bool isTurning;
public:
  Turner();
  void startTurn(int);
  bool update();
};