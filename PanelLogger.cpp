/*
 * PanelLogger.cpp
 *
 *  Created on: Feb 19, 2013
 *      Author: cujo
 */

#include "PanelLogger.h"
#include "LCD.h"

PanelLogger::PanelLogger() {
	lcd = new LCD();
}

PanelLogger::~PanelLogger() {
	delete(lcd);
}

void PanelLogger::initialize() {
	lcd->initialize();
}

void PanelLogger::log(String text){
	lcd->setLine1(text);
}

void PanelLogger::log(String line1, String line2) {
	lcd->print(line1, line2);
}

