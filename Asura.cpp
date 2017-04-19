#include "Asura.h"
#include "Wire.h"

Asura::Asura(){	
}

void Asura::gyroStart(){
	#define MPU_addr 0x68
	#define minVal 265
	#define maxVal 402

	Wire.begin();
	Wire.beginTransmission(MPU_addr);
	Wire.write(0x6B);
	Wire.write(0);
	Wire.endTransmission(true);	
}

int Asura::gyro(char direction){
	int16_t AcX,AcY,AcZ;
	double x;
	double y;
	double z;
	Wire.beginTransmission(MPU_addr);
	Wire.write(0x3B);
	Wire.endTransmission(false);
	Wire.requestFrom(MPU_addr,14,true);
	AcX=Wire.read()<<8|Wire.read();
	AcY=Wire.read()<<8|Wire.read();
	AcZ=Wire.read()<<8|Wire.read();
	int xAng = map(AcX,minVal,maxVal,-90,90);
	int yAng = map(AcY,minVal,maxVal,-90,90);
	int zAng = map(AcZ,minVal,maxVal,-90,90);
	x= RAD_TO_DEG * (atan2(-yAng, -zAng)+PI);
	y= RAD_TO_DEG * (atan2(-xAng, -zAng)+PI);
	z= RAD_TO_DEG * (atan2(-yAng, -xAng)+PI);

	if(direction == 'y'){
		return(y);
	}

	if(direction == 'x'){
    	return(x);
  	}

	if(direction == 'z'){
    	return(z);
  	}
}