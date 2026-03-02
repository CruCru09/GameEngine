#pragma once

#include "Core.h"
#include "../Events/Event.h"
#include "Window.h"

namespace GameEngine {

	class GAMEENGINE_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();
	private:
		std::unique_ptr<Window> m_Window;
		bool m_Running = true;
	};

	// To be defined in CLIENT 将在客户端中定义
	Application* CreateApplictoin();

}
