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
//right_forward_arm_forward_max
#define RFAF 170
//right_forward_arm_backward_min
#define RFAB 30

#define RFHF 60
#define RFHB 170

#define LFAF 12
#define LFAB 152

#define LFHF 120
#define LFHB 10

#define RBAF 150
#define RBAB 10

#define RBHF 10
#define RBHB 120

#define LBAF 30
#define LBAB 170

#define LBHF 170
#define LBHB 60

void layDown();
void wiggleTail();
void standBy();
void standUp();
void walk();
void yawn();
void pushUp(int);
void shakeHand();
void stretchF();
void stretchB();

void warmUp();
void flip();