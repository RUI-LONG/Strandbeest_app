#include "movement.h"

void layDown() {

  Mini.I2C1.MXservo.setAngle(right_forward_hand, RFHF);
  Mini.I2C1.MXservo.setAngle(left_forward_hand, LFHF);
  Mini.I2C1.MXservo.setAngle(right_backward_hand, RBHB-10);
  Mini.I2C1.MXservo.setAngle(left_backward_hand, LBHB);

  delay(50);
  Mini.I2C1.MXservo.setAngle(right_forward_arm, RFAB);
  Mini.I2C1.MXservo.setAngle(left_forward_arm, LFAB);
  Mini.I2C1.MXservo.setAngle(right_backward_arm, RBAF);
  Mini.I2C1.MXservo.setAngle(left_backward_arm, LBAF);
  delay(10);
}

void yawn() {
  // ??
  Mini.I2C1.MXservo.setAngle(right_forward_arm, RFAF);
  Mini.I2C1.MXservo.setAngle(left_forward_arm, LFAF);
  Mini.I2C1.MXservo.setAngle(right_forward_hand, RFHB);
  Mini.I2C1.MXservo.setAngle(left_forward_hand, LFHB);

  Mini.I2C1.MXservo.setAngle(right_backward_arm, 100);
  Mini.I2C1.MXservo.setAngle(left_backward_arm, 80);
  Mini.I2C1.MXservo.setAngle(right_backward_hand, RBHF);
  Mini.I2C1.MXservo.setAngle(left_backward_hand, LBHF);

  delay(1500);

  Mini.I2C1.MXservo.setAngle(right_forward_arm, 90);
  Mini.I2C1.MXservo.setAngle(left_forward_arm, 90);
  Mini.I2C1.MXservo.setAngle(right_forward_hand, RFHB);
  Mini.I2C1.MXservo.setAngle(left_forward_hand, LFHB);

  Mini.I2C1.MXservo.setAngle(right_backward_arm, RBAB);
  Mini.I2C1.MXservo.setAngle(left_backward_arm, LBAB);
  Mini.I2C1.MXservo.setAngle(right_backward_hand, RBHF);
  Mini.I2C1.MXservo.setAngle(left_backward_hand, LBHF);

  delay(1500);
  standUp();
  delay(50);
}

void pushUp(int cnt) {
  Mini.I2C1.MXservo.setAngle(right_forward_arm, 90);
  Mini.I2C1.MXservo.setAngle(left_forward_arm, 90);
  Mini.I2C1.MXservo.setAngle(right_forward_hand, RFHB);
  Mini.I2C1.MXservo.setAngle(left_forward_hand, LFHB+20);

  Mini.I2C1.MXservo.setAngle(right_backward_arm, 40);
  Mini.I2C1.MXservo.setAngle(left_backward_arm, 140);
  Mini.I2C1.MXservo.setAngle(right_backward_hand, RBHF);
  Mini.I2C1.MXservo.setAngle(left_backward_hand, LBHF);
  delay(1000);

  for (int i = 0; i < cnt; i++) {

    Mini.I2C1.MXservo.setAngle(right_forward_arm, 40);
    Mini.I2C1.MXservo.setAngle(left_forward_arm, 140);
    Mini.I2C1.MXservo.setAngle(right_forward_hand, 90);
    Mini.I2C1.MXservo.setAngle(left_forward_hand, 90);

    Mini.I2C1.MXservo.setAngle(right_backward_arm, 20);
    Mini.I2C1.MXservo.setAngle(left_backward_arm, 160);

    delay(1200);

    Mini.I2C1.MXservo.setAngle(right_forward_arm, 90);
    Mini.I2C1.MXservo.setAngle(left_forward_arm, 90);
    Mini.I2C1.MXservo.setAngle(right_forward_hand, RFHB);
    Mini.I2C1.MXservo.setAngle(left_forward_hand, LFHB+20);

    Mini.I2C1.MXservo.setAngle(right_backward_arm, 40);
    Mini.I2C1.MXservo.setAngle(left_backward_arm, 160);

    delay(1200);
  }
  delay(10);
  standUp();
}


void standUp() {
  Mini.I2C1.MXservo.setAngle(right_forward_hand, RFHB);
  Mini.I2C1.MXservo.setAngle(left_forward_hand, LFHB);
  Mini.I2C1.MXservo.setAngle(right_backward_hand, RBHF);
  Mini.I2C1.MXservo.setAngle(left_backward_hand, LBHF);
  delay(100);
  Mini.I2C1.MXservo.setAngle(right_forward_arm, 90);
  Mini.I2C1.MXservo.setAngle(left_forward_arm, 90);
  Mini.I2C1.MXservo.setAngle(right_backward_arm, 90);
  Mini.I2C1.MXservo.setAngle(left_backward_arm, 90);

  delay(100);
}

void standBy() {
  Mini.I2C1.MXservo.setAngle(right_forward_hand, RFHF+40);
  Mini.I2C1.MXservo.setAngle(left_forward_hand, LFHF-40);
  Mini.I2C1.MXservo.setAngle(right_backward_hand, RBHB-40);
  Mini.I2C1.MXservo.setAngle(left_backward_hand, LBHB+40);
  delay(100);
  Mini.I2C1.MXservo.setAngle(right_forward_arm, 90-30+10);
  Mini.I2C1.MXservo.setAngle(left_forward_arm, 90+30);
  Mini.I2C1.MXservo.setAngle(right_backward_arm, 90+30);
  Mini.I2C1.MXservo.setAngle(left_backward_arm, 90-30+10);
  delay(100);
}


void walk() {
  // TODO
  // pose1
  for (int i = 0; i < 12; i++) {
    Mini.I2C1.MXservo.setAngle(right_forward_arm, 90-i*5);
    Mini.I2C1.MXservo.setAngle(right_forward_hand, RFHB-60);
    Mini.I2C1.MXservo.setAngle(right_backward_arm, 90+i*5);
    Mini.I2C1.MXservo.setAngle(right_backward_hand, RBHB-60);
    delay(5);
  }
  for (int i = 0; i < 12; i++) {
    Mini.I2C1.MXservo.setAngle(left_backward_arm, 90-i*5);
    Mini.I2C1.MXservo.setAngle(left_backward_hand, LBHB+60);
    Mini.I2C1.MXservo.setAngle(left_forward_arm, 90+i*5);
    Mini.I2C1.MXservo.setAngle(left_forward_hand, LFHB+60);
    delay(5);
  }

  delay(500);

  // pose2
  for (int i = 0; i < 12; i++) {
    // rigth_forward to front
    Mini.I2C1.MXservo.setAngle(right_forward_arm, 30+i*5);
    Mini.I2C1.MXservo.setAngle(right_forward_hand, RFHB-60-i);
    Mini.I2C1.MXservo.setAngle(right_backward_arm, 150-i*5);
    Mini.I2C1.MXservo.setAngle(right_backward_hand, RBHB-60-i);
    delay(5);
  }
  for (int i = 0; i < 12; i++) {
    Mini.I2C1.MXservo.setAngle(left_backward_arm, 30+i*5);
    Mini.I2C1.MXservo.setAngle(left_backward_hand, LBHB+60+i);
    Mini.I2C1.MXservo.setAngle(left_forward_arm, 150-i*5);
    Mini.I2C1.MXservo.setAngle(left_forward_hand, LFHB+60+i);
    delay(5);
  }
  delay(500);
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
  Mini.I2C1.MXservo.setAngle(right_forward_arm, 90);
  Mini.I2C1.MXservo.setAngle(right_forward_hand, RFHB);

  Mini.I2C1.MXservo.setAngle(left_forward_arm, 90);
  Mini.I2C1.MXservo.setAngle(left_forward_hand, LFHB);

  delay(400);

  for (int i = 0; i < 4; i++) {
    Mini.I2C1.MXservo.setAngle(right_forward_arm, RFAF-20);
    Mini.I2C1.MXservo.setAngle(right_forward_hand, RFHB-70);

    delay(500);
    Mini.I2C1.MXservo.setAngle(right_forward_arm, 90+20);
    Mini.I2C1.MXservo.setAngle(right_forward_hand, RFHB);
    delay(500);
  }
}

void stretchF(){
  standUp();
  delay(800);
  Mini.I2C1.MXservo.setAngle(right_forward_arm, 90-30);
  Mini.I2C1.MXservo.setAngle(right_forward_hand, RFHF);
  delay(300);

  for (int i = 0; i < 10; i++) {
    Mini.I2C1.MXservo.setAngle(right_forward_arm, RFAF-60+6*10);
    Mini.I2C1.MXservo.setAngle(right_forward_hand, RFHB-60+6*10);

    Mini.I2C1.MXservo.setAngle(left_forward_arm, LFHB+60-6*10);
    Mini.I2C1.MXservo.setAngle(left_forward_hand, LFHB+60-6*10);
    delay(30);
  }
}

void stretchB(){
  standUp();
  delay(800);
  for (int i = 0; i < 10; i++) {
    Mini.I2C1.MXservo.setAngle(left_backward_arm, RFAF-60+6*10);
    Mini.I2C1.MXservo.setAngle(left_backward_hand, RFHB-60+6*10);

    Mini.I2C1.MXservo.setAngle(right_backward_arm, LFHB+60-6*10);
    Mini.I2C1.MXservo.setAngle(right_backward_hand, LFHB+60-6*10);
    delay(30);
  }
}


void warmUp(){

  for (int i = 0; i < 11; i++) {
      Mini.I2C1.MXservo.setAngle(right_backward_hand, RBHB-50);
      Mini.I2C1.MXservo.setAngle(left_forward_hand, LFHF-50);
      delay(80);
      Mini.I2C1.MXservo.setAngle(right_forward_hand, RFHF);
      Mini.I2C1.MXservo.setAngle(left_backward_hand, LBHB);
      delay(80);

      Mini.I2C1.MXservo.setAngle(right_forward_hand, RFHF+50);
      Mini.I2C1.MXservo.setAngle(left_backward_hand, LBHB+50);
      delay(80);
      Mini.I2C1.MXservo.setAngle(right_backward_hand, RBHB);
      Mini.I2C1.MXservo.setAngle(left_forward_hand, LFHF);
      delay(80);
  }
  standBy();
}

void flip(){
  // TODO
  standBy();

  delay(1000);

  Mini.I2C1.MXservo.setAngle(right_forward_arm, RFAB);
  Mini.I2C1.MXservo.setAngle(right_forward_hand, 0);
  Mini.I2C1.MXservo.setAngle(left_forward_arm, LFAB);
  Mini.I2C1.MXservo.setAngle(left_forward_hand, 180);

  Mini.I2C1.MXservo.setAngle(right_backward_hand, RBHB-60);
  Mini.I2C1.MXservo.setAngle(left_backward_hand, LBHB+60);
  delay(10);
  Mini.I2C1.MXservo.setAngle(right_backward_hand, RBHF);
  Mini.I2C1.MXservo.setAngle(left_backward_hand, LBHF);
  delay(100);

  // start
  Mini.I2C1.MXservo.setAngle(right_forward_arm, 90);
  Mini.I2C1.MXservo.setAngle(right_forward_hand, RFHB);
  Mini.I2C1.MXservo.setAngle(left_forward_arm, 90);
  Mini.I2C1.MXservo.setAngle(left_forward_hand, LFHB);

  // Mini.I2C1.MXservo.setAngle(right_backward_hand, RBHB);
  // Mini.I2C1.MXservo.setAngle(left_backward_hand, LBHB);

}