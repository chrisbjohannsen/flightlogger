/*
 * ConsoleSerialPort.h
 *
 *  Created on: Feb 23, 2013
 *      Author: cujo
 */

#ifndef CONSOLESERIALPORT_H_
#define CONSOLESERIALPORT_H_

#include "SerialPort.h"

class ConsoleSerialPort: public SerialPort {
public:
	ConsoleSerialPort(String name);
	 ~ConsoleSerialPort();

	void initialize();
	void reset();

	uint8_t readByte();
	void readBytes(uint8_t* buffer, size_t size);

	void writeByte(uint8_t value);
	size_t writeBytes(uint8_t* buffer, size_t size);

};

#endif /* CONSOLESERIALPORT_H_ */
