#pragma once

#include <Zumo32U4.h>
#include <Wire.h>
#include "Measurer.h"
#include "Turner.h"

class Retreater {
private:
  uint8_t mode;
  Measurer measurer;
  Turner turner;
public:
  Retreater();
  bool startRetreat(int, int);
  void update(int);
};