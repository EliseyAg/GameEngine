<<<<<<< HEAD
#include "OpenGLgameCore/Application.hpp"

#include <iostream>
#include <memory>

#include <imgui/imgui.h>
#include <imgui/backends/imgui_impl_opengl3.h>

class EngineEditor : public Engine::Application {
	virtual void on_update() override
	{
		//std::cout << "Update frame: " << frame++ << std::endl;
	}

	virtual void on_ui_draw() override
	{
		ImGui::Begin("Editor");
		ImGui::SliderFloat3("camera position", camera_position, -10.f, 10.f);
		ImGui::SliderFloat3("camera rotation", camera_rotation, 0, 360.f);
		ImGui::Checkbox("Perspective camera", &perspective_camera);
		ImGui::End();
	}

=======
#include <iostream>
#include <memory>
#include "OpenGLgameCore/Application.hpp"

class MyApp : public Engine::Application {
	virtual void on_update() override {
		//std::cout << "Update frame: " << frame++ << std::endl;
	}

>>>>>>> 1ed6159dea207cdcda968d6b2b3f61b5c1b28db1
	int frame = 0;
};

int main() {
<<<<<<< HEAD
	auto pEngineEditor = std::make_unique<EngineEditor>();

	int returnCode = pEngineEditor->start(1200, 600, "App");
=======
	auto myApp = std::make_unique<MyApp>();

	int returnCode = myApp->start(1200, 600, "App");
>>>>>>> 1ed6159dea207cdcda968d6b2b3f61b5c1b28db1

	return returnCode;
}