#include "movement.h"

void layDown() {

  Mini.I2C2.MXservo.setAngle(right_forward_hand, RFHF);
  Mini.I2C2.MXservo.setAngle(left_forward_hand, LFHF);
  Mini.I2C2.MXservo.setAngle(right_backward_hand, RBHB);
  Mini.I2C2.MXservo.setAngle(left_backward_hand, LBHB);

  delay(50);
  Mini.I2C2.MXservo.setAngle(right_forward_arm, RFAB);
  Mini.I2C2.MXservo.setAngle(left_forward_arm, LFAB);
  Mini.I2C2.MXservo.setAngle(right_backward_arm, RBAF);
  Mini.I2C2.MXservo.setAngle(left_backward_arm, LBAF);
  delay(10);
}

void pushUp(int cnt) {
  RightF(90, RFHB);
  LeftF(90, LFHB);
  RightB(RFAM, RBHF);
  LeftB(LFAM, LBHF);
  delay(1000);

  for (int i = 0; i < cnt; i++) {
    RightF(RFAM, 90);
    LeftF(LFAM, 80);
    delay(1200);

    RightF(90, RFHB);
    LeftF(90, LFHB);

    LeftB(150, -1);
    RightB(40, -1);
    delay(1200);
  }
  delay(10);
  standUp();
}


void standUp() {
  Mini.I2C2.MXservo.setAngle(right_forward_hand, RFHB);
  Mini.I2C2.MXservo.setAngle(left_forward_hand, LFHB);
  Mini.I2C2.MXservo.setAngle(right_backward_hand, RBHF);
  Mini.I2C2.MXservo.setAngle(left_backward_hand, LBHF);
  delay(100);
  Mini.I2C2.MXservo.setAngle(right_forward_arm, 90);
  Mini.I2C2.MXservo.setAngle(left_forward_arm, 90);
  Mini.I2C2.MXservo.setAngle(right_backward_arm, 90);
  Mini.I2C2.MXservo.setAngle(left_backward_arm, 90);

  delay(100);
}

void standBy() {
  Mini.I2C2.MXservo.setAngle(right_forward_hand, RFHF+40);
  Mini.I2C2.MXservo.setAngle(left_forward_hand, LFHF-40);
  Mini.I2C2.MXservo.setAngle(right_backward_hand, RBHB-40);
  Mini.I2C2.MXservo.setAngle(left_backward_hand, LBHB+40);
  delay(100);
  Mini.I2C2.MXservo.setAngle(right_forward_arm, RFAM);
  Mini.I2C2.MXservo.setAngle(left_forward_arm, LFAM);
  Mini.I2C2.MXservo.setAngle(right_backward_arm, RBAM);
  Mini.I2C2.MXservo.setAngle(left_backward_arm, LBAM);
  delay(100);
}

void walk() {
  // TODO
  // standBy();
  // Mini.I2C2.MXservo.setAngle(right_backward_arm, RBAF);
  // Mini.I2C2.MXservo.setAngle(left_forward_arm, LFAM-20);

  // Mini.I2C2.MXservo.setAngle(left_forward_hand, LFHF-20);
  // Mini.I2C2.MXservo.setAngle(right_backward_hand, RBHB);
  // delay(150);
  // Mini.I2C2.MXservo.setAngle(left_forward_hand, LFHF-40);

  // Mini.I2C2.MXservo.setAngle(right_forward_arm, RFAB);
  // Mini.I2C2.MXservo.setAngle(right_forward_hand, RFHF+20);

  // delay(150);
  // Mini.I2C2.MXservo.setAngle(left_forward_arm, LFAM+20);
  // Mini.I2C2.MXservo.setAngle(right_forward_arm, RFAM+20);
  // Mini.I2C2.MXservo.setAngle(left_backward_arm, LBAM-20);

  // Mini.I2C2.MXservo.setAngle(left_backward_hand, LBHB);
  // Mini.I2C2.MXservo.setAngle(right_backward_hand, RBHB-40);

  // delay(150);
  // Mini.I2C2.MXservo.setAngle(right_forward_hand, RFHF+60);
  // Mini.I2C2.MXservo.setAngle(left_forward_hand, LFHF-40);

  // delay(150);
  // Mini.I2C2.MXservo.setAngle(right_backward_arm, RBAM);

  // Mini.I2C2.MXservo.setAngle(left_backward_hand, LBHB+40);

  // delay(150);
  // Mini.I2C2.MXservo.setAngle(right_forward_arm, RFAM);

  // Mini.I2C2.MXservo.setAngle(right_forward_hand, RFHF+40);

  // delay(150);
  // Mini.I2C2.MXservo.setAngle(left_forward_arm, LFAM);
  // Mini.I2C2.MXservo.setAngle(left_backward_arm, LBAM);

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

void shakeHand(){
  layDown();
  delay(500);
  Mini.I2C2.MXservo.setAngle(right_forward_arm, 90);
  Mini.I2C2.MXservo.setAngle(right_forward_hand, RFHB);

  Mini.I2C2.MXservo.setAngle(left_forward_arm, 90);
  Mini.I2C2.MXservo.setAngle(left_forward_hand, LFHB);

  delay(400);

  for (int i = 0; i < 4; i++) {
    Mini.I2C2.MXservo.setAngle(right_forward_arm, RFAF-20);
    Mini.I2C2.MXservo.setAngle(right_forward_hand, RFHB-70);

    delay(500);
    Mini.I2C2.MXservo.setAngle(right_forward_arm, 90+20);
    Mini.I2C2.MXservo.setAngle(right_forward_hand, RFHB);
    delay(500);
  }
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


void warmUp(){

  for (int i = 0; i < 11; i++) {
      Mini.I2C2.MXservo.setAngle(right_backward_hand, RBHB-50);
      Mini.I2C2.MXservo.setAngle(left_forward_hand, LFHF-50);
      delay(80);
      Mini.I2C2.MXservo.setAngle(right_forward_hand, RFHF);
      Mini.I2C2.MXservo.setAngle(left_backward_hand, LBHB);
      delay(80);

      Mini.I2C2.MXservo.setAngle(right_forward_hand, RFHF+50);
      Mini.I2C2.MXservo.setAngle(left_backward_hand, LBHB+50);
      delay(80);
      Mini.I2C2.MXservo.setAngle(right_backward_hand, RBHB);
      Mini.I2C2.MXservo.setAngle(left_forward_hand, LFHF);
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

void headDown(){
  // standBy before buttUp
  int t = 30;
  Mini.I2C2.MXservo.setAngle(right_forward_hand, RFHF+40-t);
  Mini.I2C2.MXservo.setAngle(left_forward_hand, LFHF-40+t);
  // Mini.I2C2.MXservo.setAngle(right_backward_hand, RBHB-40);
  // Mini.I2C2.MXservo.setAngle(left_backward_hand, LBHB+40);
  delay(100);
  Mini.I2C2.MXservo.setAngle(right_forward_arm, RFAM-t);
  Mini.I2C2.MXservo.setAngle(left_forward_arm, LFAM+t);
  // Mini.I2C2.MXservo.setAngle(right_backward_arm, RBAM);
  // Mini.I2C2.MXservo.setAngle(left_backward_arm, LBAM);
  delay(100);
}
void test(int cnt){
  // standBy before buttUp
  standBy();
  Mini.I2C2.MXservo.setAngle(right_forward_arm, RFAM-10);
  Mini.I2C2.MXservo.setAngle(left_forward_arm, LFAM+10);
  delay(100);
  
  int t = 30;
  for (int i = 0; i < cnt; i++) {
    Mini.I2C2.MXservo.setAngle(right_forward_hand, RFHF+40+t);
    Mini.I2C2.MXservo.setAngle(left_forward_hand, LFHF-40-t);
    delay(300);
    Mini.I2C2.MXservo.setAngle(right_forward_hand, RFHF);
    Mini.I2C2.MXservo.setAngle(left_forward_hand, LFHF);
    delay(300);
  }
  standBy();
  delay(300);
}