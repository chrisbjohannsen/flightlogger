/*
 * SerialPort.cpp
 *
 *  Created on: Feb 23, 2013
 *      Author: cujo
 */

#include "SerialPort.h"

SerialPort::SerialPort(String name) : IPort(name) {

}

SerialPort::~SerialPort() {
}

void SerialPort::initialize(){
}
void SerialPort::reset(){}

uint8_t SerialPort::readByte(){
	return 0;
}
void SerialPort::readBytes(uint8_t* buffer, size_t size){}

void SerialPort::writeByte(uint8_t value){}
size_t SerialPort::writeBytes(uint8_t* buffer, size_t size){
	return 0;
}
