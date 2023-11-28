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

#ifdef VIZ_ENABLE_ASSERTS
	#define VIZ_ASSERT(x, ...) { if(!(x)) { VIZ_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
	#define VIZ_CORE_ASSERT(x, ...) { if(!(x)) { VIZ_CORE_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
#else
	#define VIZ_ASSERT(x, ...)
	#define VIZ_CORE_ASSERT(x, ...)
#endif

#define BIT(x) (1 << x)