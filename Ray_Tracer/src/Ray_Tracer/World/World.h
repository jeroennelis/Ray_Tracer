#pragma once
#include "ViewPlane.h"
#include "../Utilities/RGBColor.h"
#include "../GeometricObjects//Sphere.h"
#include "../GeometricObjects/Plane.h"
#include "../Tracers/Tracer.h"
#include "../Tracers/SingleSphere.h"
#include "../Tracers/MultipleObjects.h"
#include "../image.h"
#include "../Utilities/Point2D.h"
#include "../Samplers/Jittered.h"
#include "../Samplers/NRooks.h"
#include "../Samplers/MultiJittered.h"
#include <stdio.h>

#include "../Core.h"

class RT_API World
{
public:
	ViewPlane	vp;
	RGBColor	background_color;
	Sphere		sphere;
	Tracer*		tracer_ptr;
	Image*		image;

	std::vector<GeometricObject*>	objects;
	
	World(void);
	~World(void);

	void build(void);

	void add_object(GeometricObject* object_ptr);

	ShadeRec hit_bare_bones_objects(const Ray& ray);

	void render_scene(std::string& filename) const;

	void set_pixel(const int row, const int column, const RGBColor& pixelColor) const;
};

inline void World::add_object(GeometricObject* object_ptr)
{
	objects.push_back(object_ptr);
}



