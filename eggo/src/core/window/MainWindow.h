/**
	Created by: Wes Ferreira 2021-05-20
*/

#pragma once
#ifndef MAIN_WINDOW_H
#define MAIN_WINDOW_H

namespace MainWindow {

	std::unique_ptr<Renderer::Entity> renderer;

	class Entity : public Window, public MainWindowSpecs {
	protected:

	public:
		static GLFWwindow* init();

		Entity(int width, int height, const char* title);
		~Entity();
	private:

	};

	Entity::Entity(int width, int height, const char* title) :Window(width, height, title) { }

	GLFWwindow* Entity::init() {
		std::unique_ptr<MainWindow::Entity> window = std::make_unique<MainWindow::Entity>(MainWindowSpecs::WIDTH, MainWindowSpecs::HEIGHT, MainWindowSpecs::TITLE);

		window->bindKeyCallBack(KEY_CALLBACK);

		return window->context;
	}

	Entity::~Entity() { }
}

#endif // !MAIN_WINDOW_H

