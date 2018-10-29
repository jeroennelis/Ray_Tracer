#pragma once

#ifdef RT_PLATFORM_WINDOWS

extern Ray_Tracer::Application* Ray_Tracer::CreateApplication();

int main(int argc, char** argv)
{
	printf("test\n");
	auto app = Ray_Tracer::CreateApplication();
	app->Run();
	delete app;
}

#endif // RT_PLATFORM_WINDOWS
