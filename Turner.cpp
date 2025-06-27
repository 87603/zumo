#include "Turner.h"

Turner::Turner()
{
  encoders.getCountsAndResetLeft();
  encoders.getCountsAndResetRight();
}

void Turner::startTurn(int degrees)
{
    float afstand = (3.14159 * 10 * degrees) / 360.0; // pi * wheelbase
    float omtrek = 3.14159 * 2.5; // pi * wiel diameter

    ticksNeeded = (afstand / omtrek) * 909;
    turnDirection = degrees > 0;
}

bool Turner::update()
{
    int l = abs(encoders.getCountsLeft());
  int r = abs(encoders.getCountsRight());
  int delta = (l + r) / 2;

  if (delta >= ticksNeeded) {
    motor->stop();
    return true;
  }

  if (turnDirection) {
    motor->tankTurn(100);
  } else {
    motor->tankTurn(-100);
  }
    return false;
}
