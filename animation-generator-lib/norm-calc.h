#pragma once

class NormsCalculator {
public:
	NormsCalculator(unsigned int);
	float getNorm(unsigned int);
private:
	unsigned int max;
	float delta;
};