/**
	Created by: Wes Ferreira 2021-05-21
*/

#pragma once
#ifndef APPLICATION_H
#define APPLICATION_H

class Application { // Singleton
protected:
public:
	GLFWwindow* windowContext;

	static Application* getInstance();
	~Application();

private:
	static Application* instance;

	Application();

};
Application* Application::instance = 0;


Application::Application() {
	this->windowContext = MainWindow::Entity::init();
	MainWindow::renderer = Renderer::Entity::init();

	// Any polygon could to be drawn like this.
	VertexData v0, v1, v2, v3, v4, v5;
	float size = 0.05f;
	v0.position = glm::vec3 { 0.20f, 0.0f, 0.0f };
	v1.position = glm::vec3 { 0.20f + size, 0.0f, 0.0f };
	v2.position = glm::vec3 { 0.20f + size / 2, size, 0.0f };
	v3.position = glm::vec3 { 0.20f, size / 1.5, 0.0f };
	v4.position = glm::vec3 { 0.20f + size, size / 1.5, 0.0f };
	v5.position = glm::vec3 { 0.20f + size / 2, size / -2.5, 0.0f };

	v0.color = glm::vec4 { 1.0f, 0.372f, 0.427f, 1.0f };
	v1.color = glm::vec4 { 1.0f, 0.372f, 0.427f, 1.0f };
	v2.color = glm::vec4 { 1.0f, 0.764f, 0.443f, 1.0f };
	v3.color = glm::vec4 { 1.0f, 0.372f, 0.427f, 1.0f };
	v4.color = glm::vec4 { 1.0f, 0.372f, 0.427f, 1.0f };
	v5.color = glm::vec4 { 1.0f, 0.764f, 0.443f, 1.0f };

	ShapeData star = { {v0, v1, v2, v3, v4, v5}, {0, 1, 2, 3, 4, 5} };
	////////////////////////////////////////////

	std::shared_ptr<G::Batch> batch2 = std::make_shared<G::Batch>(star);

	std::shared_ptr player = std::make_shared<Player>(0.0f, 0.0f);

	MainWindow::renderer->addUnit(player);
	MainWindow::renderer->add(batch2);

	MainLoop::Entity::init(this->windowContext);
}

Application* Application::getInstance() {
	if(instance == 0) {
		instance = new Application();
	}

	return instance;
}

Application::~Application() {
	glfwTerminate();

	delete instance;
}

#endif // !APPLICATION_H

