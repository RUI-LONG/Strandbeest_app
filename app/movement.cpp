#include "movement.h"

void layDown(int ang) {
  // Note: -40 <= ang <= 40
  Cat.RightF(RFAB, RFHF+10-ang);
  Cat.LeftF(LFAB, LFHF-10+ang);
  delay(100);
  Cat.RightB(RBAF, RBHB+ang);
  Cat.LeftB(LBAF, LBHB-ang);
}

void standUp() {
  Cat.RightF(-1, RFHB);
  Cat.LeftF(-1, LFHB);
  Cat.RightB(-1, RBHF);
  Cat.LeftB(-1, LBHF);
  delay(100);

  Cat.RightF(110, -1);
  Cat.LeftF(80, -1);
  Cat.RightB(95, -1);
  Cat.LeftB(90, -1);
  delay(100);
}

void standBy() {
  Cat.RightF(-1, RFHF+40);
  Cat.LeftF(-1, LFHF-40);
  Cat.RightB(-1, RBHB-40);
  Cat.LeftB(-1, LBHB+40);
  delay(100);

  Cat.RightF(RFAM, -1);
  Cat.LeftF(LFAM, -1);
  Cat.RightB(RBAM, -1);
  Cat.LeftB(LBAM, -1);
  delay(100);
}

void shakeHand(int cnt){
  layDown();
  delay(500);
  Cat.RightF(90, RFHB);
  Cat.LeftF(90, LFHB);
  delay(400);

  for (int i = 0; i < cnt; i++) {
    Cat.RightF(RFAF-20, RFHB-70);
    delay(500);
    Cat.RightF(90+20, RFHB);
    delay(500);
  }
}

void pushUp(int cnt) {
  Cat.RightF(90, RFHB);
  Cat.LeftF(90, LFHB);
  Cat.RightB(RBAB, RBHF);
  Cat.LeftB(LBAB, LBHF);
  delay(1000);

  for (int i = 0; i < cnt; i++) {
    Cat.RightF(RFAM, 90);
    Cat.LeftF(LFAM, 80);
    delay(1200);

    Cat.RightF(90, RFHB);
    Cat.LeftF(90, LFHB);

    Cat.LeftB(150, -1);
    Cat.RightB(40, -1);
    delay(1200);
  }
  delay(10);
  standUp();
}



void wiggleTail() {
  for (int i = 150; i > 30; i--) {
    Mini.RC1.set(i);
    delay(5);
  }

  delay(50);
  for (int i = 30; i < 150; i++) {
    Mini.RC1.set(i);
    delay(5);
  }
  delay(50);
}

void stretchF(){
  standUp();
  delay(800);
  Mini.I2C2.MXservo.setAngle(right_forward_arm, 90-30);
  Mini.I2C2.MXservo.setAngle(right_forward_hand, RFHF);
  delay(300);

  for (int i = 0; i < 10; i++) {
    Mini.I2C2.MXservo.setAngle(right_forward_arm, RFAF-60+6*10);
    Mini.I2C2.MXservo.setAngle(right_forward_hand, RFHB-60+6*10);

    Mini.I2C2.MXservo.setAngle(left_forward_arm, LFHB+60-6*10);
    Mini.I2C2.MXservo.setAngle(left_forward_hand, LFHB+60-6*10);
    delay(30);
  }
}

void stretchB(){
  standUp();
  delay(800);
  for (int i = 0; i < 10; i++) {
    Mini.I2C2.MXservo.setAngle(left_backward_arm, RFAF-60+6*10);
    Mini.I2C2.MXservo.setAngle(left_backward_hand, RFHB-60+6*10);

    Mini.I2C2.MXservo.setAngle(right_backward_arm, LFHB+60-6*10);
    Mini.I2C2.MXservo.setAngle(right_backward_hand, LFHB+60-6*10);
    delay(30);
  }
}

void warmUp(int ang){
  standBy();
  for (int i = 0; i < 11; i++) {
      Cat.RightB(-1, RBHB-ang);
      Cat.LeftF(-1, LFHF-ang);
      delay(80);
      Cat.RightF(-1, RFHF);
      Cat.LeftB(-1, LBHB);
      delay(80);

      Cat.RightF(-1, RFHF+ang);
      Cat.LeftB(-1, LBHB+ang);
      delay(80);
      Cat.RightB(-1, RBHB);
      Cat.LeftF(-1, LFHF);
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

void pushUp2(int cnt){
  // standBy before buttUp
  standBy();
  Mini.I2C2.MXservo.setAngle(right_forward_arm, RFAM-10);
  Mini.I2C2.MXservo.setAngle(left_forward_arm, LFAM+10);
  delay(100);
  
  int t = 30;
  for (int i = 0; i < cnt; i++) {
    Mini.I2C2.MXservo.setAngle(right_forward_hand, RFHF+40+t);
    Mini.I2C2.MXservo.setAngle(left_forward_hand, LFHF-40-t);
    delay(500);
    Mini.I2C2.MXservo.setAngle(right_forward_hand, RFHF);
    Mini.I2C2.MXservo.setAngle(left_forward_hand, LFHF);
    delay(500);
  }
  standBy();
  delay(300);
}

void test(int cnt){
  standUp();
  delay(1000);
  for (int i = 0; i < cnt; i++) {

  headUp();
  delay(1500);

  headDown();
  delay(1500);
  }
}

void headDown(int ang){
  Cat.RightF(RFAM+10,  RFHF+40);
  Cat.LeftF(LFAM-10, LFHF-40);
  Cat.RightB(RBAM-30, RBHF);
  Cat.LeftB(LBAM+30, LBHF);
}

void headUp(int ang){
  Cat.RightF(RFAM+40, RFHF+120);
  Cat.LeftF(LFAM-40, LFHF-120);
  Cat.RightB(RBAM, RBHF+80);
  Cat.LeftB(LBAM, LBHF-80);
}

void balance(int ang){
  if (ang > 20) ang = 20;
  if (ang < -20) ang = -20;
  Cat.RightF(RFAM+25-ang, RFHF+80-ang*2);
  Cat.LeftF(LFAM-25+ang, LFHF-80+ang*2);

  Cat.RightB(RBAM-15-ang, RBHF+40-ang*2);
  Cat.LeftB(LBAM+15+ang, LBHF-40+ang*2);
}