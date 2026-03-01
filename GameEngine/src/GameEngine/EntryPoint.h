#pragma once

#ifdef GE_PLATFORM_WINDOWS

extern GameEngine::Application* GameEngine::CreateApplictoin();

int main(int argc, char** argv)
{

	auto app = GameEngine::CreateApplictoin();
	app->Run();
	delete app;
}

#endif
