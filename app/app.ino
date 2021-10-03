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
  delay(1500);
  standUp();
  delay(1500);
  warmUp(40);
  delay(500);

  standBy();
  delay(2000);
  pushUp(5);
  delay(1000);
  
  standBy();
  delay(2000);
  shakeHand(6);
  delay(500);
  standBy();
  delay(1500);

  for (int i = 0; i < 5; i++) {
    headDown();
    delay(400);
    headUp();
    delay(400);
  }
  layDown();


  // TODO
  // delay(500);
  // stretchF();
  // delay(1500);
  // stretchB();
  // delay(1500);

  // Test
  // walk();
}

void loop()
{
  // standBy();
  // Head.detect();

}
