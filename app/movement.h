#pragma once
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
#define LFAB 150
#define LFAM 120 // 90+30

#define LFHF 120
#define LFHB 0

#define RBAF 150
#define RBAB 10
#define RBAM 120 // 90+30

#define RBHF 0
#define RBHB 120

#define LBAF 30
#define LBAB 170
#define LBAM 70 // 90-30+10

#define LBHF 180
#define LBHB 60


// Basic Control
class BodyParts {
    private:
        MatrixServo BodyI2C;
    public:
        void setI2C(int i2cPort);
        void LeftF(int arm_angle, int hand_angle, int t=0);
        void LeftB(int arm_angle, int hand_angle, int t=0);
        void RightF(int arm_angle, int hand_angle, int t=0);
        void RightB(int arm_angle, int hand_angle, int t=0);
};

class HeadParts {
    private:
        PIXYCam HeadI2C;
    public:
        void setI2C(int i2cPort);
        void detect();
        void pitch(int ang=0);
        void roll(int ang=0);
};


// Single Poses
void layDown(int ang=20);
void standUp();
void standBy();

// Combination Poses
void shakeHand(int cnt=4);
void pushUp(int cnt=5);


// Needs Adjust
void warmUp(int ang);
void stretchF();
void stretchB();

// TODO
void flip();
void pushUp(int cnt=5);


void walk(int cnt=1);

void headDown(int ang=0);
void headUp(int ang=0);

void balance(int ang=0);

extern BodyParts Body;
extern HeadParts Head;
