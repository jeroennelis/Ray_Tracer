#include <RT.h>

class Sandbox : public Ray_Tracer::Application
{
public:
	Sandbox()
	{

	}

	~Sandbox()
	{

	}

	void Run()
	{
		World w;
		w.build();
		w.render_scene();
		while (true)
		{

		}
	}

};

Ray_Tracer::Application* Ray_Tracer::CreateApplication()
{
	return new Sandbox();
}