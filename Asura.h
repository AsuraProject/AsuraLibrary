#ifndef Asura_h
#define Asura_h

#include <Arduino.h>
#include <U8g2lib.h>

class Asura{
	public:
		Asura();
		void begin();
		int accel(char direction);
	private:
		char _direction;
};

#endif