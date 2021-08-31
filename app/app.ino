#include "movement.h"
int roll, pitch;

void setup()
{
  Mini.begin(7.4);
  // Serial.begin(115200);
  Cat.setMiniI2C(1);

  // layDown();
  // delay(2000);
  // standUp();
  // delay(2000);
  // standBy();
  // shakeHand();
  // delay(2000);
  // pushUp(5);
  
  // warmUp();
  // delay(500);
  // pushUp(5);

  // delay(500);
  // standBy();
  // shakeHand();
  // delay(500);

  warmUp(60);


  // delay(500);
  // stretchF();
  // delay(1500);
  // stretchB();
  // delay(1500);

  // walk
  
  // headDown();
  // test(5);
  // delay(500);
  // pushUp(5);
  // test(5);
}

void loop()
{
  standBy();

  // test();

  // delay(200);
  // if (Mini.BTN1.get()){
  //   walk();
  // }
  // if (Mini.BTN2.get()){
  //   standBy();
  // }
}


