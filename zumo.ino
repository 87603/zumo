#include "Measurer.h"
#include "Turner.h"
Measurer measurer;

Turner turner;
bool draaienBezig = false;

bool done = false;


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:

  // if (!done) {
  //   done = measurer.driveForward(1818);
  // }
  if (!draaienBezig) {
    turner.startTurn(90);
    draaienBezig = true;
  }

  if (draaienBezig) {
    if (turner.update()) {
      Serial.println("Draai voltooid!");
      draaienBezig = false;
    }
  }
}
