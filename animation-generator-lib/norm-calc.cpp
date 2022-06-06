#pragma once

#include "norm-calc.h"


NormsCalculator::NormsCalculator(unsigned int n): max(n)
{
	if (this->max >= 2) {//prevent division by zero and negative delta
		this->delta = float(1.0f / (this->max - 1));
	}
}


float NormsCalculator::getNorm(unsigned int i)
{
	if (this->max < 2) {
		//invalid construction
		return -1.0f;
	}
	else if(i < (this->max-1)) {
		return this->delta * i;
	}
	else {
		//upper norm cap
		return 1.0f;
	}
}
