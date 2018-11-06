#include "Application.h"
#include <gl/glew.h>
#include "Window.h"
#include <iostream>
#include "World/World.h"

namespace Ray_Tracer {
	Application::Application()
	{
	}


	Application::~Application()
	{
	}

	void Application::Run()
	{
		std::string title = "test";
		int width = 300;
		int height = 300;

		Window window(width, height, title);
		window.Init();
		std::cout << "enter a file name: " << std::endl;
		std::string filename;
		std::cin >> filename;
		std::cout << filename << std::endl;
		World w;
		w.build();
		w.render_scene(filename);
		window.Update();
		while (!glfwWindowShouldClose(window.GetWindow()))
		{
			glfwPollEvents();
		}
	}
}


