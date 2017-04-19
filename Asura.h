#ifndef Asura_h
#define Asura_h

#include <Arduino.h>

class Asura{
	public:
		Asura();
		void gyroStart();
		int gyro(char direction);
	private:
		char _direction;
};

#endif