#include "Measurer.h"
#include "Turner.h"
#include "Retreater.h" 

Motors motors;
Measurer measurer;
Turner turner;
Retreater retreater;

bool draaienBezig = false;
bool done = false;


void setup() {
  Serial.begin(9600);

}

void loop() {

  retreater.startRetreat(90, 8.0)
  //zo lang driveForward() false is
  // if (!done) {
  //   done = measurer.driveForward(18.0);
  // } if (done) {
  //   if (!draaienBezig) {
  //     turner.startTurn(90);
  //     draaienBezig = true;
  //   }

  //   if (draaienBezig) {
  //     if (turner.update()) {
  //       Serial.println("Draai voltooid!");
  //       draaienBezig = false;
  //       if (!draaienBezig) {
  //         retreater.startRetreat(90.0, 18.0)
  //       }
  //     }
  //   }
  // }

}
