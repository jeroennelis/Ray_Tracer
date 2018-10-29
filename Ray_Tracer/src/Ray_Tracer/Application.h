#pragma once

#include "Core.h"

namespace Ray_Tracer {
	
	class RT_API Application
	{
	public:
		Application();
		virtual ~Application();

		virtual void Run();
	};

	// To be defined in CLIENT
	Application* CreateApplication();
}



