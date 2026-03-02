#include "GameEngine/Core/GameEngine.h"

class Sandbox : public GameEngine::Application
{
public:
	Sandbox()
	{

	}

	~Sandbox()
	{

	}

};

GameEngine::Application* GameEngine::CreateApplictoin()
{
	return new Sandbox();
}