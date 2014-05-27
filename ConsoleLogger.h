/*
 * ConsoleLogger.h
 *
 *  Created on: Feb 17, 2013
 *      Author: cujo
 */

#ifndef CONSOLELOGGER_H_
#define CONSOLEOGGER_H_

#include "Logger.h"
#include "ConsoleSerialPort.h"

class ConsoleLogger: public Logger {
public:
	ConsoleLogger();
	virtual ~ConsoleLogger();

	void initialize();
	void log(String text);
private:
	ConsoleSerialPort* port;
};

#endif /* CONSOLELOGGER_H_ */
