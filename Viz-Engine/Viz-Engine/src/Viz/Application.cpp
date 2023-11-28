#include "vizpch.h"
#include "Application.h"

#include "Viz/Events/ApplicationEvent.h"
#include "Viz/Log.h"

namespace Viz {

	Application::Application()
	{
	}

	Application::~Application()
	{
	}

	void Application::Run()
	{
		WindowResizeEvent e(1280, 720);
		VIZ_TRACE(e);

		while (true);
	}

}