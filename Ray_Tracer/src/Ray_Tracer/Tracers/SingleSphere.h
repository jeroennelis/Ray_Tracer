#pragma once
#include "Tracer.h"
#include "../Utilities/ShadeRec.h"
#include "../World/World.h"

class SingleSphere :
	public Tracer
{
public:
	SingleSphere(void);

	SingleSphere(World* _world_ptr);

	~SingleSphere();

	RGBColor trace_ray(const Ray& ray) const;
};

