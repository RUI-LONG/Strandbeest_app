#include "movement.h"

void layDown(int ang) {
  // Note: -40 <= ang <= 40
  Body.RightF(RFAB, RFHF+10-ang);
  Body.LeftF(LFAB, LFHF-10+ang);
  delay(100);
  Body.RightB(RBAF, RBHB-5+ang);
  Body.LeftB(LBAF, LBHB-ang);
}

void standUp() {
  Body.RightF(-1, RFHB);
  Body.LeftF(-1, LFHB);
  Body.RightB(-1, RBHF);
  Body.LeftB(-1, LBHF);
  delay(100);

  Body.RightF(110, -1);
  Body.LeftF(80, -1);
  Body.RightB(95, -1);
  Body.LeftB(90, -1);
  delay(100);
}

void standBy() {
  int bias = 10;
  Body.RightF(-1, RFHF+40);
  Body.LeftF(-1, LFHF-40);
  Body.RightB(-1, RBHB-40);
  Body.LeftB(-1, LBHB-bias+40);
  delay(100);

  Body.RightF(RFAM, -1);
  Body.LeftF(LFAM+bias, -1);
  Body.RightB(RBAM, -1);
  Body.LeftB(LBAM-bias, -1);
  delay(100);
}

void shakeHand(int cnt){
  layDown(0);
  delay(1000);
  Body.RightF(90, RFHB);
  Body.LeftF(90, 30);
  Body.RightB(RBAF, RBHB-5+20);
  Body.LeftB(LBAF, LBHB-20);

  delay(400);

  for (int i = 0; i < cnt; i++) {
    Body.RightF(RFAF-20, RFHB-70);
    delay(500);
    Body.RightF(90+20, RFHB);
    delay(500);
  }

  Body.RightF(90, RFHB);
  Body.LeftF(90, 30);
  Body.RightB(RBAF, RBHB-5+20);
  Body.LeftB(LBAF, LBHB-20);
}

void pushUp(int cnt) {
  Body.LeftF(90, LFHB);
  Body.LeftB(LBAB, LBHF);
  Body.RightF(95, RFHB);
  Body.RightB(RBAB+5, RBHF);
  delay(1000);
  for (int i = 0; i < cnt; i++) {
    Body.RightF(RFAM, 90);
    Body.LeftF(LFAM, 80);
    delay(1200);

    Body.RightF(95, RFHB-5);
    Body.LeftF(90, LFHB);
    delay(1200);
  }
  delay(10);
}

void stretchF(){
  // TODO
  // standUp();
  // delay(800);
  // Body.LeftF(90, LFHB);
  // Body.RightF(95, RFHB);
}

void stretchB(){
  // TODO
  // standUp();
  // delay(800);
  // Body.LeftB(LBAB, LBHF);
  // Body.RightB(RBAB+5, RBHF);

}

void warmUp(int ang){
  standBy();
  for (int i = 0; i < 11; i++) {
      Body.RightB(-1, RBHB-ang);
      Body.LeftF(-1, LFHF-ang);
      delay(80);
      Body.RightF(-1, RFHF);
      Body.LeftB(-1, LBHB);
      delay(80);

      Body.RightF(-1, RFHF+ang);
      Body.LeftB(-1, LBHB+ang);
      delay(80);
      Body.RightB(-1, RBHB);
      Body.LeftF(-1, LFHF);
      delay(80);
  }
  standBy();
}

void flip(){
  // TODO
  standBy();

  delay(1000);

  Mini.I2C2.MXservo.setAngle(right_forward_arm, RFAB);
  Mini.I2C2.MXservo.setAngle(right_forward_hand, 0);
  Mini.I2C2.MXservo.setAngle(left_forward_arm, LFAB);
  Mini.I2C2.MXservo.setAngle(left_forward_hand, 180);

  Mini.I2C2.MXservo.setAngle(right_backward_hand, RBHB-60);
  Mini.I2C2.MXservo.setAngle(left_backward_hand, LBHB+60);
  delay(10);
  Mini.I2C2.MXservo.setAngle(right_backward_hand, RBHF);
  Mini.I2C2.MXservo.setAngle(left_backward_hand, LBHF);
  delay(100);

  // start
  Mini.I2C2.MXservo.setAngle(right_forward_arm, 90);
  Mini.I2C2.MXservo.setAngle(right_forward_hand, RFHB);
  Mini.I2C2.MXservo.setAngle(left_forward_arm, 90);
  Mini.I2C2.MXservo.setAngle(left_forward_hand, LFHB);

  // Mini.I2C2.MXservo.setAngle(right_backward_hand, RBHB);
  // Mini.I2C2.MXservo.setAngle(left_backward_hand, LBHB);

}

unsigned long oldT;

void walk(int cnt){
  oldT = millis();
  Body.LeftB(-1, LBHB+60);
  Body.RightB(-1, RBHB-40);
  Body.LeftF(-1, LFHF);
  delay(50);
  Body.LeftF(80, -1);

  // Body.RightB(95+50, -1);
  // Body.RightB(-1, RBHB-40);

  // Body.RightF(110-50, -1);
  // Body.RightF(-1, RFHF+40);

  // Body.LeftB(90-50, -1);
  // Body.LeftB(-1, LBHB+40);

}

void headDown(int ang){
  Body.RightF(RFAM+10,  RFHF+40);
  Body.LeftF(LFAM-10, LFHF-40);
  Body.RightB(RBAM-30, RBHF);
  Body.LeftB(LBAM+30, LBHF);
}

void headUp(int ang){
  Body.RightF(RFAM+40, RFHF+120);
  Body.LeftF(LFAM-40, LFHF-120);
  Body.RightB(RBAM, RBHF+80);
  Body.LeftB(LBAM, LBHF-80);
}

void balance(int ang){
  if (ang > 20) ang = 20;
  if (ang < -20) ang = -20;
  Body.RightF(RFAM+25-ang, RFHF+80-ang*2);
  Body.LeftF(LFAM-25+ang, LFHF-80+ang*2);

  Body.RightB(RBAM-15-ang, RBHF+40-ang*2);
  Body.LeftB(LBAM+15+ang, LBHF-40+ang*2);
}