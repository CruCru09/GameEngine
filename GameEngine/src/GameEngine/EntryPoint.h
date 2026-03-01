#pragma once

#ifdef GE_PLATFORM_WINDOWS

extern GameEngine::Application* GameEngine::CreateApplictoin();

int main(int argc, char** argv)
{
	GameEngine::Log::Init();
	GE_CORE_WARN("Initalized Log!");
	int a = 5;
	GE_INFO("Holle! Var={0}",a);

	auto app = GameEngine::CreateApplictoin();
	app->Run();
	delete app;
}

#endif
