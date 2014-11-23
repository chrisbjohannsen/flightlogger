/*
 * Utils.h
 *
 *  Created on: Feb 17, 2013
 *      Author: cujo
 */
#include <WString.h>
#ifndef UTILS_H_
#define UTILS_H_

float convertMtoFt(float meters);

float convertHgtoPa(float inchesHg);

float convertPtoHg(float pascals);

float convertCtoF(float degreesC);

String floatToText(float value,int leftOfDecimal, int rightOfDecimal);

#endif /* UTILS_H_ */
