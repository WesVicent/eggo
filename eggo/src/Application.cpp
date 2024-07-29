#include "Application.h"


Application* Application::instance;

void Application::run() const {
	if (mainLoop) {
		mainLoop();
	}
}

Application::Application() {
	Global::init();

	this->mainWindow = std::make_unique<Window>(MainWindowSpecs::WIDTH, MainWindowSpecs::HEIGHT, MainWindowSpecs::TITLE);
}

Application* Application::getInstance()
{
	if (!instance) {
		instance = new Application();
	}

	return instance;
}

Application::~Application() {
}
