#pragma once

#ifdef VIZ_PLATFORM_WINDOWS

extern Viz::Application* Viz::CreateApplication();

int main(int argc, char** argv)
{
	Viz::Log::Init();
	VIZ_CORE_WARN("Initialized Log!");
	int a = 5;
	VIZ_INFO("Hello! Var={0}", a);

	auto app = Viz::CreateApplication();
	app->Run();
	delete app;
}

#endif