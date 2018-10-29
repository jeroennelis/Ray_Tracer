#pragma once
#include "Tracer.h"
#include "..//Utilities/ShadeRec.h"
#include "../World/World.h"

class MultipleObjects :
	public Tracer
{
public:
	MultipleObjects(void);
	MultipleObjects(World* _world_ptr);
	~MultipleObjects();

	RGBColor trace_ray(const Ray& ray) const;
};

