#include <RT.h>
#include <iostream>

class Sandbox : public Ray_Tracer::Application
{
public:
	Sandbox()
	{

	}

	~Sandbox()
	{

	}
};

Ray_Tracer::Application* Ray_Tracer::CreateApplication()
{
	return new Sandbox();
}