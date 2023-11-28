#pragma once

#ifdef VIZ_PLATFORM_WINDOWS

extern Viz::Application* Viz::CreateApplication();

int main(int argc, char** argv)
{
	printf("Viz Engine\n");

	auto app = Viz::CreateApplication();
	app->Run();
	delete app;
}

#endif