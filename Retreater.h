#pragma once

#include <Zumo32U4.h>
#include <Wire.h>
#include "Measurer.h"
#include "Turner.h"

class Retreater {
private:
  Measurer measurer;
  Turner turner;
  int mode;
  int afstand;
public:
  Retreater();
  void startRetreat(int, int);
  bool update();
};