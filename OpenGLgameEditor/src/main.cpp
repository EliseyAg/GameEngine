#include <iostream>
#include <memory>
#include "OpenGLgameCore/Application.hpp"

class MyApp : public Engine::Application {
	virtual void on_update() override {
		//std::cout << "Update frame: " << frame++ << std::endl;
	}

	int frame = 0;
};

int main() {
	auto myApp = std::make_unique<MyApp>();

	int returnCode = myApp->start(1200, 600, "App");

	return returnCode;
}