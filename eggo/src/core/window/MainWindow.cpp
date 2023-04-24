#include "core/window/MainWindow.h"

	MainWindow::Entity::Entity(int width, int height, const char* title) :Window(width, height, title) { }

	GLFWwindow* MainWindow::Entity::init() {
		std::unique_ptr<MainWindow::Entity> window = std::make_unique<MainWindow::Entity>(MainWindowSpecs::WIDTH, MainWindowSpecs::HEIGHT, MainWindowSpecs::TITLE);

		window->bindKeyCallBack(KEY_CALLBACK);

		return window->context;
	}

	MainWindow::Entity::~Entity() { }
