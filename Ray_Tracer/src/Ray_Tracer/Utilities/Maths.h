#pragma once
#include <stdlib.h>

inline double
max(double x0, double x1);

inline double
max(double x0, double x1)
{
	return((x0 > x1) ? x0 : x1);
}

inline int rand_int()
{
	return (rand());
}

inline float rand_float()
{
	return((float)rand() / (float)RAND_MAX);
}

inline float set_rand_seed(const int seed)
{
	srand(seed);
}

inline float
rand_float(int l, float h) {
	return (rand_float() * (h - l) + l);
}

inline int
rand_int(int l, int h) {
	return ((int)(rand_float(0, h - l + 1) + l));
}
