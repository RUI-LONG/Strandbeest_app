//#include <Arduino.h>
//#include "MatrixMini.h"

#include "movement.h"

void setup()
{
  Mini.begin(7.4);
  Serial.begin(115200);
  Serial.print("Starting...\n");

  // layDown();
  // delay(2000);
  // standUp();
  // delay(2000);

  // standBy();
  // delay(500);
  // warmUp();
  // delay(500);
  // pushUp(5);

  // delay(500);
  // standBy();
  // shakeHand();
  // delay(500);

  // standBy();
  // delay(500);
  // stretchF();
  // delay(1500);
  // standBy();
  // stretchB();
  // delay(1500);
  // standBy();
  // delay(1000);
  // layDown();
  // delay(1000);

  // new
  standBy();
  delay(1000);
}

void loop()
{

  // standUp();
  // delay(1500);

  // yawn();
  // delay(1000);
  // standUp();

  // pushUp(5);
}
