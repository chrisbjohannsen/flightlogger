/*
 * GpsSerialPort.h
 *
 *  Created on: Feb 23, 2013
 *      Author: cujo
 */

#ifndef GPSSERIALPORT_H_
#define GPSSERIALPORT_H_

#include "SerialPort.h"
#include "Adafruit_GPS.h"

class GpsSerialPort: public SerialPort {
public:
	GpsSerialPort();
	virtual ~GpsSerialPort();

	void initialize();
	void reset();

	uint8_t readByte();
	void readBytes(uint8_t* buffer, size_t size);

	void writeByte(uint8_t value);
	size_t writeBytes(uint8_t* buffer, size_t size);

	Adafruit_GPS* getGps();
private:

	Adafruit_GPS* gps;
	uint8_t buffer[256];
};

#endif /* GPSSERIALPORT_H_ */
