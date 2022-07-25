#include "OpenGLgameCore/Application.hpp"
#include "OpenGLgameCore/Input.hpp"

#include <iostream>
#include <memory>

#include <imgui/imgui.h>
#include <imgui/backends/imgui_impl_opengl3.h>

class EngineEditor : public Engine::Application {
	virtual void on_update() override
	{
		if (Engine::Input::IsKeyPressed(Engine::KeyCode::KEY_W))
		{
			camera_position[2] += -0.01f;
		}
		if (Engine::Input::IsKeyPressed(Engine::KeyCode::KEY_S))
		{
			camera_position[2] +=  0.01f;
		}
		if (Engine::Input::IsKeyPressed(Engine::KeyCode::KEY_A))
		{
			camera_position[0] += -0.01f;
		}
		if (Engine::Input::IsKeyPressed(Engine::KeyCode::KEY_D))
		{
			camera_position[0] +=  0.01f;
		}
		if (Engine::Input::IsKeyPressed(Engine::KeyCode::KEY_Q))
		{
			camera_position[1] +=  0.01f;
		}
		if (Engine::Input::IsKeyPressed(Engine::KeyCode::KEY_E))
		{
			camera_position[1] += -0.01f;
		}
		if (Engine::Input::IsKeyPressed(Engine::KeyCode::KEY_UP))
		{
			camera_rotation[0] +=  0.1f;
		}
		if (Engine::Input::IsKeyPressed(Engine::KeyCode::KEY_DOWN))
		{
			camera_rotation[0] += -0.1f;
		}
		if (Engine::Input::IsKeyPressed(Engine::KeyCode::KEY_LEFT))
		{
			camera_rotation[1] +=  0.1f;
		}
		if (Engine::Input::IsKeyPressed(Engine::KeyCode::KEY_RIGHT))
		{
			camera_rotation[1] += -0.1f;
		}
	}

	virtual void on_ui_draw() override
	{
		ImGui::Begin("Editor");
		ImGui::SliderFloat3("camera position", camera_position, -10.f, 10.f);
		ImGui::SliderFloat3("camera rotation", camera_rotation, 0, 360.f);
		ImGui::Checkbox("Perspective camera", &perspective_camera);
		ImGui::End();
	}
};

int main() {
	auto pEngineEditor = std::make_unique<EngineEditor>();

	int returnCode = pEngineEditor->start(1200, 600, "Editor");

	return returnCode;
}