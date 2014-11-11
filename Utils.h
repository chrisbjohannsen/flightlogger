/*
 * Utils.h
 *
 *  Created on: Feb 17, 2013
 *      Author: cujo
 */
#include <WString.h>
#ifndef UTILS_H_
#define UTILS_H_

float convertMtoFt(float meters) {
	return meters * 3.28084;
}

float convertHgtoPa(float inchesHg) {
	return inchesHg * 3377;
}

float convertPtoHg(float pascals) {
	return pascals / 3377;
}

float convertCtoF(float degreesC) {
	return (1.8 * degreesC) + 32;
}

String floatToText(float value,int leftOfDecimal, int rightOfDecimal){
	char buffer[16];
	dtostrf(value, leftOfDecimal, rightOfDecimal, buffer);
	String retVal = buffer;
	return retVal;
}

#endif /* UTILS_H_ */
