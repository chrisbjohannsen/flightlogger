/*
 *  ConsoleSerialPort.cpp
 *
 *  Created on: Feb 23, 2013
 *      Author: cujo
 */

#include "ConsoleSerialPort.h"

ConsoleSerialPort::ConsoleSerialPort(String name) : SerialPort(name) {

}

ConsoleSerialPort::~ConsoleSerialPort() {
}

void ConsoleSerialPort::initialize(){
	Serial.begin(9600);
	delay(100);
}
void ConsoleSerialPort::reset(){
}

uint8_t ConsoleSerialPort::readByte(){
	return (uint8_t) Serial.read();
}
void ConsoleSerialPort::readBytes(uint8_t* buffer, size_t size){
	Serial.readBytes((char*) buffer,size);
}

void ConsoleSerialPort::writeByte(uint8_t value){
	Serial.write(value);
}
size_t ConsoleSerialPort::writeBytes(uint8_t* buffer, size_t size){
	return Serial.write(buffer,size);
}
