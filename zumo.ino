#include "Measurer.h"

Measurer measurer;
bool done = false;


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:

  if (!done) {
    done = measurer.driveForward(1818);
  }
}
