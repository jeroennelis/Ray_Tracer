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

	void Run()
	{
		std::cout << "enter a file name: " << std::endl;
		std::string filename;
		std::cin >> filename;
		std::cout << filename << std::endl;
		World w;
		w.build();
		w.render_scene(filename);
		while (true)
		{

		}
	}

};

Ray_Tracer::Application* Ray_Tracer::CreateApplication()
{
	return new Sandbox();
}