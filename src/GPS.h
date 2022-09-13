/*
 * GPS.h
 *
 *  Created on: Feb 17, 2013
 *      Author: cujo
 */

#ifndef GPS_H_
#define GPS_H_
#include "Common.h"
#include "GpsSerialPort.h"

class GPS {

public:
	GPS();
	~GPS();

	void initialize();

	uint8_t getHour();
	uint8_t getMinute();
	uint8_t getSeconds();
	uint16_t getMilliseconds();
	uint8_t getDay();
	uint8_t getMonth();
	uint8_t getYear();
	uint8_t getFix();
	uint8_t getQuality();
	uint8_t getSatellites();

	float getLatitude();
	float getLongitude();
	float getSpeed();
	float getHeading();
	float getAltitude();
	char getLat();
	char getLon();
	char getMag();

	String getDateString();
	String getTimeString();
	String getLatitudeString();
	String getLongitudeString();
	String getQualityString();
	String getSatellitesString();
private:
	GpsSerialPort* port;
};
#endif /* GPS_H_ */


