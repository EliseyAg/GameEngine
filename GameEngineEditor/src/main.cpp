#include "GameEngineCore/Application.hpp"
#include "GameEngineCore/Input.hpp"

#include <memory>
#include <Windows.h>

#include <imgui/imgui.h>
#include <imgui/backends/imgui_impl_opengl3.h>
#include <imgui/imgui_internal.h>

class EngineEditor : public EliseyAgGameEngine::Application {

	float camera_position[3] = { -5.f,  0.f,  0.f };
	float camera_rotation[3] = { 0.f,  0.f,  0.f };
	float camera_fov = 60.f;
	float camera_near_plane = 0.1f;
	float camera_far_plane = 100.f;

	double m_initial_mouse_pos_x = 0.0;
	double m_initial_mouse_pos_y = 0.0;

	virtual void on_update() override
	{
		glm::vec3 movement_delta{0, 0, 0};
		glm::vec3 rotation_delta{0, 0, 0};
		float editor_camera_speed = 0.5f;
		bool move_camera = false;

		if (EliseyAgGameEngine::Input::IsKeyPressed(EliseyAgGameEngine::KeyCode::KEY_W))
		{
			movement_delta.x +=  0.01f;
		}
		if (EliseyAgGameEngine::Input::IsKeyPressed(EliseyAgGameEngine::KeyCode::KEY_S))
		{
			movement_delta.x += -0.01f;
		}
		if (EliseyAgGameEngine::Input::IsKeyPressed(EliseyAgGameEngine::KeyCode::KEY_A))
		{
			movement_delta.y += -0.01f;
		}
		if (EliseyAgGameEngine::Input::IsKeyPressed(EliseyAgGameEngine::KeyCode::KEY_D))
		{
			movement_delta.y +=  0.01f;
		}
		if (EliseyAgGameEngine::Input::IsKeyPressed(EliseyAgGameEngine::KeyCode::KEY_Q))
		{
			movement_delta.z +=  0.01f;
		}
		if (EliseyAgGameEngine::Input::IsKeyPressed(EliseyAgGameEngine::KeyCode::KEY_E))
		{
			movement_delta.z += -0.01f;
		}
		if (EliseyAgGameEngine::Input::IsKeyPressed(EliseyAgGameEngine::KeyCode::KEY_UP))
		{
			rotation_delta.y +=  0.1f;
		}
		if (EliseyAgGameEngine::Input::IsKeyPressed(EliseyAgGameEngine::KeyCode::KEY_DOWN))
		{
			rotation_delta.y += -0.1f;
		}
		if (EliseyAgGameEngine::Input::IsKeyPressed(EliseyAgGameEngine::KeyCode::KEY_LEFT))
		{
			rotation_delta.z += -0.1f;
		}
		if (EliseyAgGameEngine::Input::IsKeyPressed(EliseyAgGameEngine::KeyCode::KEY_RIGHT))
		{
			rotation_delta.z +=  0.1f;
		}
		if (EliseyAgGameEngine::Input::IsKeyPressed(EliseyAgGameEngine::KeyCode::KEY_O))
		{
			rotation_delta.x +=  0.1f;
		}
		if (EliseyAgGameEngine::Input::IsKeyPressed(EliseyAgGameEngine::KeyCode::KEY_P))
		{
			rotation_delta.x += -0.1f;
		}

		if (EliseyAgGameEngine::Input::IsMouseButtonPressed(EliseyAgGameEngine::MouseButton::MOUSE_BUTTON_RIGHT))
		{
			glm::vec2 current_cursor_position = get_current_cursor_position();
			if (EliseyAgGameEngine::Input::IsMouseButtonPressed(EliseyAgGameEngine::MouseButton::MOUSE_BUTTON_LEFT))
			{
				camera.move_right(-static_cast<float>(current_cursor_position.x - m_initial_mouse_pos_x) / 100.f);
				camera.move_up(-static_cast<float>(m_initial_mouse_pos_y - current_cursor_position.y) / 100.f);
			}
			else
			{
				rotation_delta.z -= static_cast<float>(m_initial_mouse_pos_x - current_cursor_position.x) / 5.f;
				rotation_delta.y += static_cast<float>(m_initial_mouse_pos_y - current_cursor_position.y) / 5.f;
			}
			m_initial_mouse_pos_x = current_cursor_position.x;
			m_initial_mouse_pos_y = current_cursor_position.y;
		}

		camera.add_movement_and_rotation(movement_delta * editor_camera_speed, rotation_delta * editor_camera_speed);
	}

	void setup_dockspace_menu()
	{
		static ImGuiDockNodeFlags dockspace_flags = ImGuiDockNodeFlags_PassthruCentralNode | ImGuiDockNodeFlags_NoWindowMenuButton;
		static ImGuiWindowFlags window_flags = ImGuiWindowFlags_MenuBar | ImGuiWindowFlags_NoDocking;
		window_flags |= ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoMove;
		window_flags |= ImGuiWindowFlags_NoBringToFrontOnFocus | ImGuiWindowFlags_NoNavFocus;
		window_flags |= ImGuiWindowFlags_NoBackground;

		const ImGuiViewport* viewport = ImGui::GetMainViewport();
		ImGui::SetNextWindowPos(viewport->WorkPos);
		ImGui::SetNextWindowSize(viewport->WorkSize);
		ImGui::SetNextWindowViewport(viewport->ID);
		ImGui::PushStyleVar(ImGuiStyleVar_WindowRounding, 0.0f);
		ImGui::PushStyleVar(ImGuiStyleVar_WindowBorderSize, 0.0f);
		ImGui::PushStyleVar(ImGuiStyleVar_WindowPadding, ImVec2(0.0f, 0.0f));
		ImGui::Begin("DockSpace", nullptr, window_flags);
		ImGui::PopStyleVar(3);

		ImGuiIO& io = ImGui::GetIO();
		ImGuiID dockspace_id = ImGui::GetID("MyDockSpace");
		ImGui::DockSpace(dockspace_id, ImVec2(0.0f, 0.0f), dockspace_flags);

		if (ImGui::BeginMenuBar())
		{
			if (ImGui::BeginMenu("File"))
			{
				if (ImGui::MenuItem("New Scene...", NULL))
				{

				}
				if (ImGui::MenuItem("Open Scene...", NULL))
				{

				}
				if (ImGui::MenuItem("Save Scene...", NULL))
				{

				}
				ImGui::Separator();
				if (ImGui::MenuItem("Exit", NULL))
				{
					close();
				}
				ImGui::EndMenu();
			}
			ImGui::EndMenuBar();
		}
		ImGui::End();
	}

	virtual void on_mouse_button_event(const EliseyAgGameEngine::MouseButton button_code,
									   const double x_pos,
									   const double y_pos,
									   const bool pressed) override
	{
		m_initial_mouse_pos_x = x_pos;
		m_initial_mouse_pos_y = y_pos;
	}

	virtual void on_ui_draw() override
	{
		setup_dockspace_menu();

		camera_position[0] = camera.get_position().x;
		camera_position[1] = camera.get_position().y;
		camera_position[2] = camera.get_position().z;
		camera_rotation[0] = camera.get_rotation().x;
		camera_rotation[1] = camera.get_rotation().y;
		camera_rotation[2] = camera.get_rotation().z;

		camera_fov = camera.get_field_of_view();
		camera_near_plane = camera.get_near_clip_plane();
		camera_far_plane = camera.get_far_clip_plane();

		ImGui::Begin("Editor");

		ImGui::SliderFloat3("light source position", light_source_position, -10.f, 10.f);
		ImGui::ColorEdit3("light source color", light_source_color);

		ImGui::SliderFloat("ambient factor", &ambient_factor, 0.f, 1.f);
		ImGui::SliderFloat("diffuse factor", &diffuse_factor, 0.f, 1.f);
		ImGui::SliderFloat("specular factor", &specular_factor, 0.f, 1.f);
		ImGui::SliderFloat("shininess", &shininess, 0.f, 128.f);

		if (ImGui::SliderFloat3("camera position", camera_position, -10.f, 10.f))
		{
			camera.set_position(glm::vec3(camera_position[0], camera_position[1], camera_position[2]));
		}
		if (ImGui::SliderFloat3("camera rotation", camera_rotation, 0, 360.f))
		{
			camera.set_rotation(glm::vec3(camera_rotation[0], camera_rotation[1], camera_rotation[2]));
		}
		if (ImGui::SliderFloat("camera FOV", &camera_fov, 1.f, 120.f))
		{
			camera.set_field_of_view(camera_fov);
		}
		if (ImGui::SliderFloat("camera near clip plane", &camera_near_plane, 0.1f, 10.f))
		{
			camera.set_near_clip_plane(camera_near_plane);
		}
		if (ImGui::SliderFloat("camera far clip plane", &camera_far_plane, 1.f, 100.f))
		{
			camera.set_far_clip_plane(camera_far_plane);
		}
		if (ImGui::Checkbox("Perspective camera", &perspective_camera))
		{
			camera.set_projection_mode(perspective_camera ? EliseyAgGameEngine::Camera::ProjectionMode::Perspective : EliseyAgGameEngine::Camera::ProjectionMode::Orthograthic);
		}

		ImGui::End();
	}
};

int main() {
	auto pEngineEditor = std::make_unique<EngineEditor>();

	HWND hWnd = GetConsoleWindow();

	#ifdef NDEBUG
		ShowWindow(hWnd, SW_HIDE);
	#endif

	int returnCode = pEngineEditor->start(800, 800, "Editor");

	return returnCode;
}