#pragma once

// this file contains the declaration of the class GeometricObject

#include "../Utilities/Constants.h"
#include "../Utilities/RGBColor.h"
#include "../Utilities/Point3D.h"
#include "../Utilities/Normal.h"
#include "../Utilities/Ray.h"
#include "../Utilities/ShadeRec.h"

#include "../Utilities/Constants.h"


					

class GeometricObject {	
	
	public:	

		GeometricObject(void);									// default constructor
		
		GeometricObject(const GeometricObject& object);			// copy constructor
	
		virtual GeometricObject*								// virtual copy constructor
		clone(void) const = 0;

		virtual 												// destructor
		~GeometricObject (void);	
			
		virtual bool 												 
		hit(const Ray& ray, double& t, ShadeRec& s) const = 0;
		

		// the following three functions are only required for Chapter 3
		
		void
		set_color(const RGBColor& c);
				
		void
		set_color(const float r, const float g, const float b);
		
		RGBColor
		get_color(void);

	
	protected:
	
		RGBColor   color;						// only used for Bare Bones ray tracing
	
		GeometricObject&						// assignment operator
		operator= (const GeometricObject& rhs);
};


// --------------------------------------------------------------------  set_colour

inline void
GeometricObject::set_color(const RGBColor& c) {
	color = c;
}

// --------------------------------------------------------------------  set_colour

inline void 
GeometricObject::set_color(const float r, const float g, const float b) {
	color.r = r;
	color.b = b;
	color.g = g;
}

// --------------------------------------------------------------------  get_colour

inline RGBColor 
GeometricObject::get_color(void) {
	return (color);
}
