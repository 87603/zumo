#include "Turner.h"

Turner::Turner() : motor()
{
  encoders.getCountsAndResetLeft();
  encoders.getCountsAndResetRight();
}
void Turner::startTurn(int degrees)
{
  // Gebruik het teken van degrees om richting te bepalen
  int deg = abs(degrees);
  float afstand = (3.14159 * 10 * deg) / (2 * 360.0); // pi * wheelbase
  float omtrek = 3.14159 * 2.5; // pi * wiel diameter

  ticksNeeded = (afstand / omtrek) * 909;
  turnDirection = (degrees >= 0);  // true = rechtsom, false = linksom

  // Reset encoders als dat nodig is
  encoders.getCountsAndResetLeft();
  encoders.getCountsAndResetRight();
}


bool Turner::update()
{
  //abs want de wielen draaien tegenovergesteld, met abs wordt alleen afstand gemeten
  int left = abs(encoders.getCountsLeft());
  int right = abs(encoders.getCountsRight());
  int gemiddeldeTicks  = (left + right) / 2;

  if (gemiddeldeTicks >= ticksNeeded) {
    motor.stop();
    return true;
  }

  if (turnDirection) {
    motor.tankTurn(300);
  } else {
    motor.tankTurn(-300);
  }
    return false;
}
