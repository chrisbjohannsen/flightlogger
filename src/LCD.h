/*
 * LCD.h
 *
 *  Created on: Feb 17, 2013
 *      Author: cujo
 */

#ifndef LCD_H_
#define LCD_H_
#include "Common.h"
#include <LiquidCrystal.h>
class LCD {
public:
	LCD();
	~LCD();
	void initialize();
	void print(String line1, String line2);
	void setLine1(String line);
	void setLine2(String line);
private:
	void setDisplay();

	LiquidCrystal* lcd;
	String line1;
	String line2;

};
#endif /* LCD_H_ */
