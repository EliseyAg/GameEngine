#pragma once

#include "GameEngineCore/Event.hpp"
#include "GameEngineCore/Camera.hpp"

#include <memory>

namespace EliseyAgGameEngine {

	class Application {
	public:
		Application();
		virtual ~Application();

		Application(const Application&) = delete;
		Application(Application&&) = delete;
		Application& operator = (const Application&) = delete;
		Application& operator = (Application&&) = delete;

		virtual int start(unsigned int window_width, unsigned int window_height, const char* title);
		void close();

		void draw();

		virtual void on_update() {};

		virtual void on_ui_draw() {};

		virtual void on_mouse_button_event(const MouseButton button_code, 
										   const double x_pos, 
										   const double y_pos, 
										   const bool pressed) {};

		glm::vec2 get_current_cursor_position() const;

		float m_background_color[4] = { 0.33f, 0.33f, 0.33f, 0.f };

		float camera_position[3] = { -5.f,  0.f,  0.f };
		float camera_rotation[3] = {  0.f,  0.f,  0.f };
		float camera_fov = 60.f;
		float camera_near_plane = 0.1f;
		float camera_far_plane = 100.f;

		bool perspective_camera = true;
		Camera camera {glm::vec3(-5, 0, 0)};

	private:
		std::unique_ptr<class Window> m_pWindow;

		EventDispatcher m_event_dispatcher;
		bool m_bCloseWindow = false;
	};

}