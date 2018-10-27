/*
 * SerialPort.h
 *
 *  Created on: Feb 23, 2013
 *      Author: cujo
 */

#ifndef SERIALPORT_H_
#define SERIALPORT_H_

#include "IPort.h"

class SerialPort: public IPort {
public:
	SerialPort(String name);
	virtual ~SerialPort();

	virtual void initialize();
	virtual void reset();

	virtual uint8_t readByte();
	virtual void readBytes(uint8_t* buffer, size_t size);

	virtual void writeByte(uint8_t value);
	virtual size_t writeBytes(uint8_t* buffer, size_t size);

};

#endif /* SERIALPORT_H_ */
