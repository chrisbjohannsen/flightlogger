/*
 * Logger.h
 *
 *  Created on: Feb 17, 2013
 *      Author: cujo
 */

#ifndef LOGGER_H_
#define LOGGER_H_
#include "Common.h"
class Logger {
public:
	Logger();
	virtual ~Logger();

	virtual void log(String text) = 0;
};

#endif /* LOGGER_H_ */
