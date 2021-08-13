//#include <Arduino.h>
//#include "MatrixMini.h"

#include "movement.h"
int roll;

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

  // walk
  
  // headDown();
  // test(5);
  // delay(500);
  pushUp(5);
}

void loop()
{
  // Serial.print("Roll=");
  // Serial.println(Mini.I2C1.MXmotion.getRoll());
  // Serial.print("Pitch=");
  // Serial.println(Mini.I2C1.MXmotion.getPitch());
  // Serial.println("============");
  // delay(100);

  // delay(200);
  // if (Mini.BTN1.get()){
  //   walk();
  // }
  // if (Mini.BTN2.get()){
  //   standBy();
  // }


}
