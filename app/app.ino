#include "movement.h"
int roll, pitch;

void setup()
{
  Mini.begin(7.4, 1);
  Head.setI2C(2);

  // Serial.begin(115200);
  Body.setI2C(1);

  Serial.println("Begin ...");

  layDown();
  delay(2000);
  standUp();
  delay(2000);
  standBy();
  delay(2000);
  shakeHand();
  delay(2000);
  pushUp(5);
  delay(2000);
  warmUp(60);

  // Test
  // standBy();
  // delay(500);
  // walk();

  // TODO
  // delay(500);
  // stretchF();
  // delay(1500);
  // stretchB();
  // delay(1500);

  
  // headDown();
  // test(5);
  // delay(500);
  // pushUp(5);6
  // test(5);
}

void loop()
{
  // standBy();
  // Head.detect();

}
