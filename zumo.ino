#include "Measurer.h"
#include "Turner.h"
 

Motors motors;
Measurer measurer(&motors);

Turner turner(&motors);

bool draaienBezig = false;

bool done = false;


void setup() {
  Serial.begin(9600);

}

void loop() {

  //zo lang driveForward() false is
  if (!done) {
    done = measurer.driveForward(18.0);
  }
  // if (!draaienBezig) {
  //   turner.startTurn(90);
  //   draaienBezig = true;
  // }

  // if (draaienBezig) {
  //   if (turner.update()) {
  //     Serial.println("Draai voltooid!");
  //     draaienBezig = false;
  //   }
  // }
}
