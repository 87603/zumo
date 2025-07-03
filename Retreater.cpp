#include "Retreater.h"

Retreater::Retreater() : measurer(), turner(), mode(0) {}

void Retreater::startRetreat(int t, int s)
{
  afstand = s;  
  if (mode == 0) {
    turner.startTurn(t);
    mode = 1;
    Serial.println("mode 1");
  }

}


bool Retreater::update()
{
  if (mode == 1) {
    if (turner.update()) {
      measurer.driveForward(afstand);

      mode = 2;
    }
    return false;
  } else if (mode == 2) {
    return measurer.update();
  }
  return false;
}
