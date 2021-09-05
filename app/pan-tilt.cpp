#include "movement.h"

HeadParts Head;

void HeadParts::setI2C(int i2cPort) {
  switch (i2cPort) {
    case 1:
      HeadI2C = Mini.I2C1.PIXYcam;
      break;
    case 2:
      HeadI2C = Mini.I2C2.PIXYcam;
      break;
    case 3:
      HeadI2C = Mini.I2C3.PIXYcam;
      break;
    case 4:
      HeadI2C = Mini.I2C4.PIXYcam;
      break;
    default:
      HeadI2C = Mini.I2C1.PIXYcam;
      break;
  }
  HeadI2C.pixyinit(i2cPort);
}

void HeadParts::detect(){
  //TODO 
  int detectSig = 2;

  bool isRedBlockValid = HeadI2C.getblock(detectSig, 1);

  if (isRedBlockValid==true)
  {
    if (HeadI2C.getCountofBlock() != 0){
        if (HeadI2C.block.signature == detectSig){
            Serial.println("sig");
            Serial.println(HeadI2C.block.signature);
            Serial.println("width");
            Serial.println(HeadI2C.block.width);
            Serial.println("height");
            Serial.println(HeadI2C.block.height);
            // Serial.println(HeadI2C.block.x);
            // Serial.println(HeadI2C.block.y);
            Serial.println("====================");
        }
    }

  }
}

void HeadParts::pitch(int ang){
    for (int i=0; i<180; i++){
        Mini.RC1.set(i);
        delay(5);
    }

}

void HeadParts::roll(int ang){
    for (int i=0; i<180; i++){
        Mini.RC2.set(i);
        delay(5);
    }

}