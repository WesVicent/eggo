#include "core/Application.h"

#include <GL/glew.h>
#include <GLFW/glfw3.h>


Application* Application::instance = 0;

Application::Application() {
	this->windowContext = MainWindow::Entity::init();
	MainWindow::renderer = Renderer::Entity::init();

	// Any polygon could to be drawn like this.
	VertexData v0, v1, v2, v3, v4, v5;
	float size = 0.05f;
	v0 = { { 0.20f, 0.0f, 0.0f }, { 1.0f, 0.372f, 0.427f, 1.0f } };
	v1 = { { 0.20f + size, 0.0f, 0.0f }, { 1.0f, 0.372f, 0.427f, 1.0f } };
	v2 = { { 0.20f + size / 2, size, 0.0f }, { 1.0f, 0.764f, 0.443f, 1.0f } };
	v3 = { { 0.20f, size / 1.5f, 0.0f }, { 1.0f, 0.372f, 0.427f, 1.0f } };
	v4 = { { 0.20f + size, size / 1.5f, 0.0f }, { 1.0f, 0.372f, 0.427f, 1.0f } };
	v5 = { { 0.20f + size / 2, size / -2.5f, 0.0f }, { 1.0f, 0.764f, 0.443f, 1.0f } };

	// v0.position = math::vec3 { 0.20f, 0.0f, 0.0f };
	// v1.position = math::vec3 { 0.20f + size, 0.0f, 0.0f };
	// v2.position = math::vec3 { 0.20f + size / 2, size, 0.0f };
	// v3.position = math::vec3 { 0.20f, size / 1.5f, 0.0f };
	// v4.position = math::vec3 { 0.20f + size, size / 1.5f, 0.0f };
	// v5.position = math::vec3 { 0.20f + size / 2, size / -2.5f, 0.0f };

	// v0.color = math::vec4 { 1.0f, 0.372f, 0.427f, 1.0f };
	// v1.color = math::vec4 { 1.0f, 0.372f, 0.427f, 1.0f };
	// v2.color = math::vec4 { 1.0f, 0.764f, 0.443f, 1.0f };
	// v3.color = math::vec4 { 1.0f, 0.372f, 0.427f, 1.0f };
	// v4.color = math::vec4 { 1.0f, 0.372f, 0.427f, 1.0f };
	// v5.color = math::vec4 { 1.0f, 0.764f, 0.443f, 1.0f };

	ShapeData star = { {v0, v1, v2, v3, v4, v5}, {0, 1, 2, 3, 4, 5} };
	////////////////////////////////////////////

	std::shared_ptr<G::Batch> batch2 = std::make_shared<G::Batch>(star);

	std::shared_ptr player = std::make_shared<Player>(0.0f, 0.0f);

	MainWindow::renderer->addUnit(player);
	MainWindow::renderer->add(batch2);

	MainLoop::Entity::init(this->windowContext);
}

Application* Application::getInstance()
{
	if(instance == 0) {
		instance = new Application();
	}

	return instance;
}

Application::~Application() {
	glfwTerminate();

	delete instance;
}
