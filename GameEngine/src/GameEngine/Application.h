#pragma once

#include "Core.h"

namespace GameEngine {

	class GAMEENGINE_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();
	};

	// To be defined in CLIENT 将在客户端中定义
	Application* CreateApplictoin();

}
