#pragma once

#include <Zumo32U4.h>
#include <Wire.h>
#include "Measurer.h"
#include "Turner.h"

/*! klasse die een draaien en rijden regelt.
draaien eerst, hij stuurt daarvoor turner aan.
daarna rijden, waarvoor hij measurer aanstuurt */

class Retreater {
private:
  Measurer measurer;
  Turner turner;
  int mode;
  long afstand;
public:
  Retreater();
  void startRetreat(int, long);
  bool update();
};