#pragma once

#include <Zumo32U4.h>
#include <Wire.h>

class Motors {
private:
  Zumo32U4Motors motors;
public:
  Motors();
  void stop();
  void driveForward(int);
  void tankTurn(int);
  void forwardTurn(int, int);
  void leftSpeed(int);
  void rightSpeed(int);
};