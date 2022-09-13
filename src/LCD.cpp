/*
 * LCD.cpp
 *
 *  Created on: Feb 17, 2013
 *      Author: cujo
 */
#include "LCD.h"

LCD::LCD() {
	lcd = new LiquidCrystal(12, 11, 5, 4, 3, 2);
}

LCD::~LCD() {
	delete (lcd);
}

void LCD::initialize() {
	lcd->begin(16, 2);

}

// Write lines to LCD Panel
void LCD::print(String line1, String line2) {
	this->line1 = line1;
	this->line2 = line2;
	this->setDisplay();
}

void LCD::setLine1(String line) {
	this->line1=line;
	this->setDisplay();
}

void LCD::setLine2(String line) {
	this->line2=line;
	this->setDisplay();
}

void LCD::setDisplay() {
	lcd->clear();
	lcd->setCursor(0, 0);
	lcd->print(line1);
	lcd->setCursor(0, 1);
	lcd->print(line2);
}
