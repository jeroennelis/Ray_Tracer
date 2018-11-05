#include "Sampler.h"
#include "../Utilities/Maths.h"


Sampler::Sampler()
	:num_samples(1),
	num_sets(1),
	count(0),
	jump(0)
{
	samples.reserve(num_samples * num_sets);
}

Sampler::Sampler(const int numSamples)
	:num_samples(numSamples),
	num_sets(1),
	count(0),
	jump(0)
{
	samples.reserve(num_samples * num_sets);
}

Sampler::Sampler(const int numSamples, const int numSets)
	:num_samples(numSamples),
	num_sets(numSets),
	count(0),
	jump(0)
{
	samples.reserve(num_samples * num_sets);
}

Sampler::Sampler(const Sampler & s)
	:num_samples(s.num_samples),
	num_sets(s.num_sets),
	count(s.count),
	jump(s.jump),
	samples(s.samples),
	shuffled_indices(s.shuffled_indices)
{
}


Sampler::~Sampler()
{
}

Point2D Sampler::sample_unit_square(void)
{
	if (count % num_samples == 0)
		jump = (rand_int() % num_sets) * num_samples;
	return (samples[count++ % (num_samples * num_sets)]);
}
