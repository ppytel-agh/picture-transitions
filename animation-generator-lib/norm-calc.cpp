#pragma once

#include "norm-calc.h"

/**
* @param n discrete number of elements in normalized series
*/
NormsCalculator::NormsCalculator(unsigned int n): max(n)
{
	if (this->max >= 2) {//prevent division by zero and negative delta
		this->delta = float(1.0f / (this->max - 1));
	}
}

/**
* If numbers of element is less than 2 returns -1.0f to prevent disambiguity.\n
* Otherwise maps element indexes in a linear way 0 -> 0.0f, n-1 -> 1.0f
* If element index exceeds number of elements in series 1.0f is returned
*/
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
