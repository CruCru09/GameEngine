#pragma once

#include "../Base.h"

#include "../Core/Core.h"

namespace GameEngine {

	// GameEngine中的事件目前正在阻塞，这意味着当事件发生时
	// 立即被派遣，必须立即处理。
	// 对于未来而言，一个更好的策略或许是将事件进行分类管理，以便更好地应对各种情况。
	// 在更新阶段的“事件”部分，对这些数据进行处理并进行传输。

	// EventType 枚举类 描述事件类型
	enum class EventType
	{
		None = 0,
		WindowClose, WindowResize, WindowFocus, WindowLostFocus, WindowMoved,
		AppTick, AppUpdate, AppRender,
		KeyPressed, KeyReleased,
		MouseButtonPressed, MouseButtonReleased, MouseMoved, MouseScrolled
	};

	// 事件类别
	enum EventCategory
	{
		None = 0,
		EventCategoryApplication	= BIT(0),
		EventCategoryInput			= BIT(1),
		EventCategoryKeyboard		= BIT(2),
		EventCategoryMouse			= BIT(3),
		EventCategoryMouseButton	= BIT(4)
	};

// 定义事件类所需的类型和名称获取函数，参数为事件类型枚举值
#define EVENT_CLASS_TYPE(type) static EventType GetStaticType() { return EventType::##type; }\
								virtual EventType GetEventType() const override { return GetStaticType(); }\
								virtual const char* GetName() const override { return #type; }

#define EVENT_CLASS_CATEGORY(category) virtual int GetCategoryFlags() const override { return category; }

	// 事件基类：提供事件类型、名称、分类及处理状态，EventDispatcher可访问处理标志。
	class GAMEENGINE_API Event
	{
		friend class EventDispatcher;
	public:
		virtual EventType GetEventType() const = 0;
		virtual const char* GetName() const = 0;
		virtual int GetCategoryFlags() const = 0;
		virtual std::string ToString() const { return GetName(); }

		inline bool IsInCategory(EventCategory category)
		{
			return GetCategoryFlags() & category;
		}
	protected:
		bool m_Handled = false;
	};

	// 事件分发器：若事件类型匹配 T，则执行处理函数并更新处理状态。
	class EventDispatcher
	{
		template<typename T>
		using EventFn = std::function<bool(T&)>;
	public:
		EventDispatcher(Event& event)
			: m_Event(event)
		{
		}

		template<typename T>
		bool Dispatch(EventFn<T> func)
		{
			if (m_Event.GetEventType() == T::GetStaticType())
			{
				m_Event.m_Handled = func(*(T*)&m_Event);
				return true;
			}
		}
	private:
		Event& m_Event;
	};

	inline std::string format_as(const Event& e)
	{
		return e.ToString();
	}

}

