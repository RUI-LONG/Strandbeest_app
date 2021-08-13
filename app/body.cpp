#include "movement.h"

void LeftF(int arm_angle, int hand_angle){
  if (arm_angle != -1){
    Mini.I2C2.MXservo.setAngle(left_forward_arm, arm_angle+5);
  }
  if (hand_angle != -1){
    Mini.I2C2.MXservo.setAngle(left_forward_hand, hand_angle);
  }
}

void RightF(int arm_angle, int hand_angle){
  if (arm_angle != -1){
    Mini.I2C2.MXservo.setAngle(right_forward_arm, arm_angle);
  }
  if (hand_angle != -1){
    Mini.I2C2.MXservo.setAngle(right_forward_hand, hand_angle);
  }
}

void LeftB(int arm_angle, int hand_angle){
  if (arm_angle != -1){
    Mini.I2C2.MXservo.setAngle(left_backward_arm, arm_angle);
  }
  if (hand_angle != -1){
    Mini.I2C2.MXservo.setAngle(left_backward_hand, hand_angle);
  }
}

void RightB(int arm_angle, int hand_angle){
  if (arm_angle != -1){
    Mini.I2C2.MXservo.setAngle(right_backward_arm, arm_angle);
  }
  if (hand_angle != -1){
    Mini.I2C2.MXservo.setAngle(right_backward_hand, hand_angle);
  }
}

