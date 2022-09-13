/*
 * Altimeter.cpp
 *
 *  Created on: Feb 17, 2013
 *      Author: cujo
 */
#include "Altimeter.h"

float const DEFAULT_PRESSURE = 29.92;

Altimeter::Altimeter(){
	bmp = new Adafruit_BMP085();
	this->setBasePressure( DEFAULT_PRESSURE );
}

Altimeter::~Altimeter(){
	delete(bmp);
}

void Altimeter::initialize(){
	this->bmp->begin();
}

float Altimeter::getTempC(){
	return this->bmp->readTemperature();
}

float Altimeter::getTempF(){
	return bmp->readTemperature();
}

float Altimeter::getPressurePA(){
	return bmp->readPressure();
}

float Altimeter::getAltitude(){
	return bmp->readAltitude(this->basePressure);
}

void Altimeter::setBasePressure(float baseValue) {
	basePressure = baseValue;
}
