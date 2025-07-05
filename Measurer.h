/*! Klasse voor gemeten voorwaarts rijden met tijdsduurcontrole
je kan tijd meegeven die berekend wordt met de afstand, als de tijd 
bereikt is stopt hij */

#pragma once

#include <Zumo32U4.h>
#include <Wire.h>
#include "Motors.h"

class Measurer {
private:
  Zumo32U4Encoders encoders;
  Motors motor;
  // float targetTicks;
  // float ticks;
   long startTime;
   long driveDuration;
  bool isDriving = false;
public:
  Measurer();
  void driveForward(/*int,*/  long);
  void update();
};