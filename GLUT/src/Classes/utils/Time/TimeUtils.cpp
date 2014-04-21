/*
 * TimeUtils.cpp
 *
 *  Created on: Apr 16, 2014
 *      Author: CarlosJose
 */

#include "TimeUtils.h"



double TimeUtils::getUSecs() {
	timeval tv;
	gettimeofday(&tv, NULL);
	return 1.0 * tv.tv_sec * 1000000.0 + tv.tv_usec;
}



double TimeUtils::myClock()
{
	return TimeUtils::getUSecs() - instance.getUSecs();
}

void TimeUtils::delay(double usecs) {
	int usecsDest = myClock() + usecs;
	while (myClock() < usecsDest)
		;
}
