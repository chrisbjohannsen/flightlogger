/*
 * Altimeter.h
 * Wrapper class for Adafruit_GPS library
 *  Created on: Feb 17, 2013
 *      Author: cujo
 */

#ifndef ALTIMETER_H_
#define ALTIMETER_H_
#include "Common.h"
#include "Adafruit_BMP085.h"

class Altimeter {

public:
	Altimeter();

	~Altimeter();

	void initialize();

	float getTempC();

	float getTempF();

	float getPressurePA();

	float getAltitude();

	void setBasePressure(float basePressure);
private:
	float basePressure;

	Adafruit_BMP085* bmp;
};

#endif /* ALTIMETER_H_ */
