/*
 * ConsoleLogger.cpp
 *
 *  Created on: Feb 17, 2013
 *      Author: cujo
 */

#include "ConsoleLogger.h"

ConsoleLogger::ConsoleLogger() {
	port = new ConsoleSerialPort("console");
}

ConsoleLogger::~ConsoleLogger() {
	delete(port);
}

void ConsoleLogger::initialize(){
	port->initialize();
	log("Serial Logger initialized");
}

void ConsoleLogger::log(String text){
	unsigned int length = text.length();
	uint8_t buffer[256];

	text.getBytes(buffer,length);
	buffer[length] = '\r';
	buffer[length+1] = '\n';
	port->writeBytes(buffer,length + 2);

}
