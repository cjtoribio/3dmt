/*
 * TimeUtils.h
 *
 *  Created on: Apr 17, 2014
 *      Author: CarlosJose
 */

#ifndef TIMEUTILS_H_
#define TIMEUTILS_H_

#include <ctime>
#include <sys/time.h>

class TimeUtils
{
private:
	static TimeUtils instance;
	double startTime;
	TimeUtils() { startTime = getUSecs(); }
public:
	static double getUSecs();
	static double myClock();
	static void delay(double usecs);
};


#endif /* TIMEUTILS_H_ */
