// Do not remove the include below
#include "FL2.h"
#include "GPS.h"
#include "Altimeter.h"
#include "Gyro.h"
#include "LCD.h"
#include "ConsoleLogger.h"
#include "PanelLogger.h"
GPS _gps;
Altimeter _altimeter;
//Adafruit_BMP085 _altimeter;
//Adafruit_L3GD20 _gyro;
//LiquidCrystal _lcd;
ConsoleLogger _console;
PanelLogger _panel;

//The setup function is called once at startup of the sketch
void setup() {
	_gps.initialize();
	_altimeter.initialize();
//		_gyro = Gyro::getInstance();
//		_lcd = LCD::getInstance();

	_panel.initialize();
	delay(1000);
	pinMode(13, OUTPUT);
	_console.initialize();
	delay(2000);
}

void healthCheck() {
	digitalWrite(13, HIGH);   // turn the LED on (HIGH is the voltage level)
	delay(500);               // wait for a second
	digitalWrite(13, LOW);    // turn the LED off by making the voltage LOW
	delay(500);
}
// The loop function is called in an endless loop
void loop() {
//		printTemp();
//		Serial.println();
//		delay(3000);
//		printPressure();
//		delay(3000);
//		printAltitude();
//		delay(3000);
//		printLocation();
//		delay(3000);
	String tempC = floatToText(_altimeter.getTempC(), 5, 2);
	_console.log(tempC);
	_panel.log("Temp C", tempC);
	delay(500);
}
