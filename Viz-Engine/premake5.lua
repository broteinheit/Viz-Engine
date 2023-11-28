workspace 'Viz'
	architecture 'x64'

	configurations
	{
		'Debug',
		'Release',
		'Dist'
	}

outputdir = '%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}'

project 'Viz-Engine'
	location 'Viz-Engine'
	kind 'SharedLib'
	language 'C++'
	cppdialect 'C++17'

	targetdir ('bin/' .. outputdir .. '/%{prj.name}')
	objdir ('bin-int/' .. outputdir .. '/%{prj.name}')

	pchheader "vizpch.h"
	pchsource "Viz-Engine/src/vizpch.cpp"

	files
	{
		'%{prj.name}/src/**.h',
		'%{prj.name}/src/**.cpp'
	}

	includedirs
	{
		'%{prj.name}/src',
		'vendor/spdlog/include'
	}

	filter 'system:windows'
		cppdialect 'C++17'
		staticruntime 'On'
		systemversion 'latest'

		defines
		{
			'VIZ_PLATFORM_WINDOWS',
			'VIZ_BUILD_DLL',
			"_WINDLL",
			"_SILENCE_ALL_MS_EXT_DEPRECATION_WARNINGS"

		}

		postbuildcommands
		{
			('{COPY} %{cfg.buildtarget.relpath} ../bin/' .. outputdir .. '/Sandbox')
		}

	filter 'configurations:Debug'
		defines 'VIZ_DEBUG'
		symbols 'On'

	filter 'configurations:Release'
		defines 'VIZ_RELEASE'
		optimize 'On'

	filter 'configurations:Dist'
		defines 'VIZ_DIST'
		optimize 'On'

project 'Sandbox'
	location 'Sandbox'
	kind 'ConsoleApp'
	language 'C++'
	cppdialect 'C++17'

	targetdir ('bin/' .. outputdir .. '/%{prj.name}')
	objdir ('bin-int/' .. outputdir .. '/%{prj.name}')

	files
	{
		'%{prj.name}/src/**.h',
		'%{prj.name}/src/**.cpp'
	}

	includedirs
	{
		'vendor/spdlog/include',
		'Viz-Engine/src'
	}

	links
	{
		'Viz-Engine'
	}

	filter 'system:windows'
		cppdialect 'C++17'
		staticruntime 'On'
		systemversion 'latest'

		defines
		{
			'VIZ_PLATFORM_WINDOWS'

		}

	filter 'configurations:Debug'
		defines 'VIZ_DEBUG'
		symbols 'On'

	filter 'configurations:Release'
		defines 'VIZ_RELEASE'
		optimize 'On'

	filter 'configurations:Dist'
		defines 'VIZ_DIST'
		optimize 'On'