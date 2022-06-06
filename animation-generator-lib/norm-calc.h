#pragma once

class NormsCalculator {
public:
	/**
	* @param n discrete number of elements in normalized series
	*/
	NormsCalculator(unsigned int n);
	/**
	* If numbers of element is less than 2 returns -1.0f to prevent disambiguity.\n
	* Otherwise maps element indexes in a linear way 0 -> 0.0f, n-1 -> 1.0f\n
	* If element index exceeds number of elements in series 1.0f is returned
	* @param i index of element in series, first element is i=0
	* @return element norm in range (0, 1)
	*/
	float getNorm(unsigned int i);
private:
	unsigned int max;
	float delta;
};