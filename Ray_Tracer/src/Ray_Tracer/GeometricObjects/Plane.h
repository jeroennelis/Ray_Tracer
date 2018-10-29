#pragma once

#include "GeometricObject.h"

//-------------------------------------------------------------------- class Plane

class Plane: public GeometricObject {
	
	public:
	
		Plane(void);   												// default constructor
		
		Plane(const Point3D& p, const Normal& n);			// constructor	
	
		Plane(const Plane& p); 									// copy constructor
		
		virtual Plane* 												// virtual copy constructor
		clone(void) const;

		Plane& 														// assignment operator
		operator= (const Plane& rhs);	
		
		virtual														// destructor
		~Plane(void);   											
					
		virtual bool 																								 
		hit(const Ray& ray, double& tmin, ShadeRec& sr) const;
		
	private:
	
		Point3D 	point;   				// point through which plane passes 
		Normal 		normal;					// normal to the plane
				
		static const double kEpsilon;   // for shadows and secondary rays
};
