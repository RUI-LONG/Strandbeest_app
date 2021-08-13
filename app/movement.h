//#pragma once
#include <MatrixMini.h>


// Set I2C
#define right_forward_arm 2
#define right_forward_hand 1

#define left_forward_arm 3
#define left_forward_hand 4

#define right_backward_arm 5
#define right_backward_hand 6

#define left_backward_arm 7
#define left_backward_hand 8

// define limit
//right_forward_arm_forward_forword
#define RFAF 170
//right_forward_arm_backward_backword
#define RFAB 30
//right_forward_arm_backward_middle
#define RFAM 60 // 90-30

#define RFHF 60
#define RFHB 180

#define LFAF 12
#define LFAB 152
#define LFAM 120 // 90+30

#define LFHF 120
#define LFHB 0

#define RBAF 150
#define RBAB 10
#define RBAM 120 // 90+30

#define RBHF 10
#define RBHB 120

#define LBAF 30
#define LBAB 170
#define LBAM 70 // 90-30+10

#define LBHF 170
#define LBHB 60

void layDown();
void standBy();
void standUp();
void yawn();
void shakeHand();
void stretchF();
void stretchB();

// Needs Adjust
void pushUp(int cnt);
void warmUp();

// TODO
void walk();
void headDown();
void flip();
void wiggleTail();

void test(int cnt);

void LeftF(int arm_angle, int hand_angle);
void LeftB(int arm_angle, int hand_angle);
void RightF(int arm_angle, int hand_angle);
void RightB(int arm_angle, int hand_angle);
