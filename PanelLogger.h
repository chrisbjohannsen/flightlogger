/*
 * PanelLogger.h
 *
 *  Created on: Feb 19, 2013
 *      Author: cujo
 */

#ifndef PANELLOGGER_H_
#define PANELLOGGER_H_

#include "Logger.h"
#include "LCD.h"

class PanelLogger: public Logger {
public:
	PanelLogger();
	virtual ~PanelLogger();

	void initialize();
	void log(String text);
	void log(String line1, String line2);

private:
	LCD* lcd;
};

#endif /* PANELLOGGER_H_ */
