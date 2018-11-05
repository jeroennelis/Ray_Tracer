#pragma once
#include "Sampler.h"
class MultiJittered :
	public Sampler
{
public:
	MultiJittered();
	MultiJittered(const int numSamples);
	MultiJittered(const int numSamples, const int numSets);
	MultiJittered(const MultiJittered& mj);
	~MultiJittered();

private:
	virtual void generate_samples(void);
};

