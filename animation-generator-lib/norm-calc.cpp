#pragma once

#include "norm-calc.h"

NormsCalculator::NormsCalculator(unsigned int m): max(m)
{
}

float NormsCalculator::getNorm(unsigned int i)
{
	if (this->max < 1) {
		return -1.0f;
	}
	else if(i < (this->max-1)) {
		return float(1.0f / (this->max - 1)) * i;
	}
	else {
		return 1.0f;
	}
}
