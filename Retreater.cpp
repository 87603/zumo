#include "Retreater.h"

Retreater::Retreater() : measurer(), turner(), mode(0) {}

bool Retreater::startRetreat(int t, int s)
{
  afstand = s;  
  if (mode == 0) {
    turner.startTurn(t);
    mode = 1;
    Serial.println("mode 1");
    return false;
  }

  return false;
}


void Retreater::update()
{
  if (mode == 1) {
    if (turner.update()) {
      measurer.driveForward(afstand);
      Serial.println("mode 2");

      mode = 2;
    }
  } 

  if (mode == 2) {
    measurer.update();
  }
}
