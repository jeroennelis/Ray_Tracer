#include "World.h"

#include <iostream>
#include <Windows.h>

World::World()
	:image(NULL)
{
}


World::~World()
{
	delete image;
	for (GeometricObject* object : objects)
	{
		delete object;
	}
}

void World::build(void)
{
	printf("building the world\n");

	vp.set_hres(300);
	vp.set_vres(300);
	vp.set_pixel_size(1);
	background_color = black;
	tracer = new MultipleObjects(this);
	
	Sphere* sphere_ptr = new Sphere;
	sphere_ptr->set_center(0, -25, 0);
	sphere_ptr->set_radius(80);
	sphere_ptr->set_color(1, 0, 0);
	add_object(sphere_ptr);

	sphere_ptr = new Sphere(Point3D(0, 30, 0), 60);
	sphere_ptr->set_color(1, 1, 0);
	add_object(sphere_ptr);

	Plane* plane_ptr = new Plane(Point3D(0, 0, 0), Normal(0, 1, 1));
	plane_ptr->set_color(0.0, 0.3, 0.0);
	add_object(plane_ptr);

	image = new Image(300, 300);
}

ShadeRec World::hit_bare_bones_objects(const Ray & ray)
{
	ShadeRec sr(*this);
	double t;
	double tmin = kHugeValue;
	int num_objects = objects.size();

	for (int j = 0; j < num_objects; j++)
	{
		if (objects[j]->hit(ray, t, sr) && (t < tmin))
		{
			sr.hit_an_object = true;
			tmin = t;
			sr.color = objects[j]->get_color();
		}
	}
	return sr;
}

void World::render_scene(void) const
{
	printf("rendering the scene\n");
	RGBColor	pixel_color;
	Ray			ray;
	double		zw = 100.0;
	double		x, y;

	ray.d = Vector3D(0, 0, -1);

	for (int r = 0; r < vp.vres; r++)
	{
		for (int c = 0; c < vp.hres; c++)
		{
			x = vp.s * (c - 0.5 *(vp.hres - 1.0));
			y = vp.s * (r - 0.5 *(vp.vres - 1.0));
			ray.o = Point3D(x, y, zw);
			pixel_color = tracer->trace_ray(ray);
			set_pixel(r, c, pixel_color);
			image->setPixel(r, c, pixel_color);
		}
	}
	image->saveImage("test.png");
	ShellExecute(NULL, "open", "test.png", NULL, NULL, SW_NORMAL);
}

void World::set_pixel(const int row, const int column, const RGBColor & pixelColor) const
{
}
