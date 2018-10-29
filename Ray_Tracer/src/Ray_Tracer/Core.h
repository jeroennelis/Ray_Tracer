#pragma once

#ifdef RT_PLATFORM_WINDOWS
	#ifdef RT_BUILD_DLL
		#define RT_API __declspec(dllexport)
	#else
		#define RT_API __declspec(dllimport)
	#endif // RT_BUILD_DLL

#else
	#error Ray_Tracer only supports Windows!

#endif // RT_PLATFORM_WINDOWS
