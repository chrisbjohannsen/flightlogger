/*
 * IPort.h
 *
 *  Created on: Feb 23, 2013
 *      Author: cujo
 */

#ifndef IPORT_H_
#define IPORT_H_
#include "Common.h"

class IPort {
private:
	String name;
public:
	IPort(String name){
		this->name = name;
	}
	virtual ~IPort(){}

	virtual void initialize()=0;
	virtual void reset()=0;

	virtual uint8_t readByte()=0;
	virtual void readBytes(uint8_t* buffer, size_t size)=0;

	virtual void writeByte(uint8_t value)=0;
	virtual size_t writeBytes(uint8_t* buffer, size_t size)=0;

};


#endif /* IPORT_H_ */
