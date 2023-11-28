#pragma once

#ifdef VIZ_PLATFORM_WINDOWS
	#ifdef VIZ_BUILD_DLL
		#define VIZ_API __declspec(dllexport)
	#else
		#define VIZ_API __declspec(dllimport)
	#endif
#else 
	#error Viz-Engine only supports Windows!
#endif