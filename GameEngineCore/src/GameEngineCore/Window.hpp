#pragma once

#include "GameEngineCore/Event.hpp"

#include <string>
#include <memory>
#include <glm/ext/vector_float2.hpp>

struct GLFWwindow;

namespace EliseyAgGameEngine {

	class Window 
	{
	public:

		int resultCode;

		using EventCallbackFn = std::function<void(BaseEvent&)>;

		Window(std::string title, const unsigned int width, const unsigned int height);
		~Window();

		Window(const Window&) = delete;
		Window(Window&&) = delete;
		Window& operator = (const Window&) = delete;
		Window& operator = (Window&&) = delete;

		virtual void on_update();
		unsigned int get_width() const { return m_data.width; };
		unsigned int get_height() const { return m_data.height; };
		glm::vec2 get_current_cursor_position() const;

		void set_event_callback(const EventCallbackFn& callback)
		{
			m_data.eventCallbackFn = callback;
		}

	private:
		struct WindowData
		{
			std::string title;
			unsigned int width;
			unsigned int height;
			EventCallbackFn eventCallbackFn;
		};

		int init();
		void shutdown();

		GLFWwindow* m_pWindow = nullptr;
		WindowData m_data;
		float m_background_color[4] = { 0.33f, 0.33f, 0.33f, 0.f };
	};

}