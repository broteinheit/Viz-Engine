#include <Viz.h>

class Sandbox : public Viz::Application
{
public:
	Sandbox()
	{

	}

	~Sandbox()
	{

	}
};

Viz::Application* Viz::CreateApplication()
{
	return new Sandbox();
}