#pragma once

#include <Zumo32U4.h>
#include <Wire.h>

class Retreater {
private:
  uint8_t mode;

public:
  Retreater();
  bool startRetreat(int, int);
  void update(int);
};