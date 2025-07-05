#include "Measurer.h"
#include "Turner.h"
#include "Retreater.h" 

Motors motors;
Measurer measurer;        
Turner turner;
Retreater retreater;
int afstand = 20;
void setup() {
  Serial.begin(9600);
  // bereken tijdsduur 
  // afstand gedeelt door gereden afstand in 1000 ms
  retreater.startRetreat(180, ((afstand/17.95)*1000));
  //retreater.startRetreat(0, ((1)*1000));

}

void loop() {

 
  retreater.update();
}
