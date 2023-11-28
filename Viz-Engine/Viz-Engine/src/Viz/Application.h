#pragma once

#include "Core.h"

namespace Viz {

	class VIZ_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();
	};

	Application* CreateApplication();
}