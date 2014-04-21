/*
 * Formulas.cpp
 *
 *  Created on: Apr 17, 2014
 *      Author: CarlosJose
 */

#include "Formulas.h"


double Formulas::toRelativeGravity(int accel)
{
	return (double(accel - 2048) / (1<<12)) * (2 * 2);
}

