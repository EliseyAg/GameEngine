#pragma once

#include "OpenGLgameCore/Event.hpp"
#include "OpenGLgameCore/Camera.hpp"

#include <memory>

namespace Engine {

	class Application {
	public:
		Application();
		virtual ~Application();

		Application(const Application&) = delete;
		Application(Application&&) = delete;
		Application& operator = (const Application&) = delete;
		Application& operator = (Application&&) = delete;

		virtual int start(unsigned int window_width, unsigned int window_height, const char* title);

		virtual void on_update() {};

		virtual void on_ui_draw() {};

		float m_background_color[4] = { 0.33f, 0.33f, 0.33f, 0.f };

		float camera_position[3] = { 0.f, 0.f, 1.f };
		float camera_rotation[3] = { 0.f, 0.f, 1.f };
		bool perspective_camera = true;
		Camera camera;

	private:
		std::unique_ptr<class Window> m_pWindow;

		EventDispatcher m_event_dispatcher;
		bool m_bCloseWindow = false;
	};

}