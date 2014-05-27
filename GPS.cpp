/*
 * GPS.cpp
 *
 *  Created on: Feb 17, 2013
 *      Author: cujo
 */
#include "GPS.h"

GPS::GPS() {
	port = new GpsSerialPort();
}

GPS::~GPS() {
	delete(port);
}

void GPS::initialize() {
	port->initialize();
}

uint8_t GPS::getHour() {
	return port->getGps()->hour;
}
uint8_t GPS::getMinute() {
	return port->getGps()->minute;
}
uint8_t GPS::getSeconds() {
	return port->getGps()->seconds;
}
uint16_t GPS::getMilliseconds() {
	return port->getGps()->milliseconds;
}
uint8_t GPS::getDay() {
	return port->getGps()->day;
}
uint8_t GPS::getMonth() {
	return port->getGps()->month;
}
uint8_t GPS::getYear() {
	return port->getGps()->year;
}
uint8_t GPS::getFix() {
	return port->getGps()->fix;
}
uint8_t GPS::getQuality() {
	return port->getGps()->fixquality;
}
uint8_t GPS::getSatellites() {
	return port->getGps()->satellites;
}
float GPS::getLatitude() {
	return port->getGps()->latitude;
}
float GPS::getLongitude() {
	return port->getGps()->longitude;
}
float GPS::getSpeed() {
	return port->getGps()->speed;
}
float GPS::getHeading() {
	return port->getGps()->angle;
}
float GPS::getAltitude() {
	return port->getGps()->altitude;
}
char GPS::getLat() {
	return port->getGps()->lat;
}
char GPS::getLon() {
	return port->getGps()->lon;
}
char GPS::getMag() {
	return port->getGps()->mag;
}

String GPS::getDateString() {
	String dateString = String(getDay());
	dateString.concat("-");
	dateString.concat(String(getMonth()));
	dateString.concat("-");
	dateString.concat(String(getYear()));
	return dateString;
}
String GPS::getTimeString() {
	String dateString = String(getHour());
	dateString.concat(":");
	dateString.concat(String(getMinute()));
	dateString.concat(":");
	dateString.concat(String(getSeconds()));
	return dateString;
}
String GPS::getLatitudeString() {
	char latBuffer[10];
	dtostrf(getLatitude(), 10, 4, latBuffer);
	char latString[15] = "";
//	strcat(latString, getLat());
//	latString += latBuffer;
	return String(latString);
}
String GPS::getLongitudeString() {
	char longBuffer[10];
	dtostrf(getLongitude(), 10, 4, longBuffer);
	char lonString[15] = "";
//	strcat(lonString, getLon());
//	lonString += longBuffer;
	return String(longBuffer);
}
String GPS::getQualityString() {
	String line1 = "GPS:Quality: ";
	line1.concat(String(getQuality()));
	return line1;
}
String GPS::getSatellitesString() {
	String line1 = "GPS:Satellites: ";
	line1.concat(String(getSatellites()));
	return line1;
}

