/*
 * GpsSerialPort.cpp
 *
 *  Created on: Feb 23, 2013
 *      Author: cujo
 */

#include "GpsSerialPort.h"

GpsSerialPort::GpsSerialPort() : SerialPort("GPS"){
	gps = new Adafruit_GPS(&Serial3);

}

GpsSerialPort::~GpsSerialPort() {
	delete(gps);
}

void GpsSerialPort::initialize() {
	//intialize the GPS module
	gps->begin(19200);
	//minimun recommended
	gps->sendCommand(PMTK_SET_NMEA_OUTPUT_RMCGGA);
	// Set the update rate
	gps->sendCommand(PMTK_SET_NMEA_UPDATE_1HZ);
}

void GpsSerialPort::reset() {
	//noop
}

uint8_t GpsSerialPort::readByte() {
	return 0;
}
void GpsSerialPort::readBytes(uint8_t* buffer, size_t size) {

}

void GpsSerialPort::writeByte(uint8_t value) {

}
size_t GpsSerialPort::writeBytes(uint8_t* buffer, size_t size) {
	return 0;
}

Adafruit_GPS* getGps(){
	return gps;
}
