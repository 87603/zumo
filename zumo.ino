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
  if (!done) {
    retreater.startRetreat(360, 0);
    done = true;
  }
  
  retreater.update();
 

}
