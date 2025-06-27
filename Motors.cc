#include "Motors.h"

Motors::Motors()
{
}

void Motors::stop()
{
  motors.setLeftSpeed(0);
  motors.setRightSpeed(0);
}

void Motors::driveForward(int s)
{
  motors.setLeftSpeed(s);
  motors.setRightSpeed(s);
}

void Motors::tankTurn(int s)
{
  motors.setLeftSpeed(s);
  motors.setRightSpeed(-s);
}

void Motors::forwardTurn(int s, int t)
{
  motors.setLeftSpeed(s + t / 2);
  motors.setRightSpeed(s - t / 2);
}

void Motors::leftSpeed(int s)
{
  motors.setLeftSpeed(s);
}

void Motors::rightSpeed(int s)
{
  motors.setRightSpeed(s);
}