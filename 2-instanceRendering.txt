#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include<iostream>
#include<string>
#include<vector>

std::string VERTEX_SHADER_SOURCE = "#version 330 core\n\
layout (location = 0) in vec3 aPos;\n\
layout (location = 1) in vec3 aColor;\n\
layout (location = 2) in mat4 modelMatrix;\n\
out vec3 ourColor;\n\
void main() {\n\
    gl_Position = modelMatrix * vec4(aPos, 1.0);\n\
    ourColor = aColor;\n\
}";

std::string FRAGMENT_SHADER_SOURCE = "#version 330 core\n\
in vec3 ourColor;\n\
out vec4 FragColor;\n\
void main() {\n\
    FragColor = vec4(ourColor, 1.0f);\n\
}";

const std::vector<glm::vec3> v = {
	// positions        
	 glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3(1.0f, 0.0f, 0.0f),
	 glm::vec3(0.0f, 1.0f, 0.0f), glm::vec3(0.0f, 1.0f, 0.0f),
	 glm::vec3(1.0f, 0.0f, 0.0f), glm::vec3(0.0f, 0.0f, 1.0f),
	 glm::vec3(1.0f, 1.0f, 0.0f), glm::vec3(1.0f, 1.0f, 1.0f)
};

std::vector<unsigned int> i = {0, 1, 2, 2, 3, 1};

int main() {
	// Initialize GLFW
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 5);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	// Create window
	GLFWwindow* window = glfwCreateWindow(800, 600, "Instance Rendering", NULL, NULL);
	if (window == NULL) {
		std::cout << "Failed to create GLFW window" << std::endl;
		glfwTerminate();
		return -1;
	}
	glfwMakeContextCurrent(window);

	// Initialize GLEW
	glewExperimental = GL_TRUE;
	if (glewInit() != GLEW_OK) {
		std::cout << "Failed to initialize GLEW" << std::endl;
		glfwTerminate();
		return -1;
	}

	const char* vertexShaderChars = VERTEX_SHADER_SOURCE.c_str();
	const char* fragmentShaderChars = FRAGMENT_SHADER_SOURCE.c_str();

	// Create vertex and fragment shaders
	unsigned int vertexShader, fragmentShader;
	vertexShader = glCreateShader(GL_VERTEX_SHADER);
	fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(vertexShader, 1, &vertexShaderChars, NULL);
	glShaderSource(fragmentShader, 1, &fragmentShaderChars, NULL);
	glCompileShader(vertexShader);
	glCompileShader(fragmentShader);

	// Check for shader compilation errors
	int success;
	char infoLog[512];
	glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
	if (!success) {
		glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
		std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << std::endl;
	}
	glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);
	if (!success) {
		glGetShaderInfoLog(fragmentShader, 512, NULL, infoLog);
		std::cout << "ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n" << infoLog << std::endl;
	}

	// Create shader program
	unsigned int shaderProgram;
	shaderProgram = glCreateProgram();
	glAttachShader(shaderProgram, vertexShader);
	glAttachShader(shaderProgram, fragmentShader);
	glLinkProgram(shaderProgram);

	// Check for program linking errors
	glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);
	if (!success) {
		glGetProgramInfoLog(shaderProgram, 512, NULL, infoLog);
		std::cout << "ERROR::SHADER::PROGRAM::LINKING_FAILED\n" << infoLog << std::endl;
	}

	// Set up model matrices for instance rendering
	glm::mat4 modelMatrices[2];
	modelMatrices[0] = glm::translate(glm::mat4(1.0f), glm::vec3(-1.0f, 0.0f, 0.0f));
	modelMatrices[1] = glm::translate(glm::mat4(1.0f), glm::vec3(0.0f, 0.0f, 0.0f));

	// Delete shaders (optional)
	glDeleteShader(vertexShader);
	glDeleteShader(fragmentShader);

	// Create VAO, VBO (for vertices), and EBO (for indices)
	unsigned int VAO, VBO, EBO;
	glGenVertexArrays(1, &VAO);
	glGenBuffers(1, &VBO);
	glGenBuffers(1, &EBO);

	// Bind VAO
	glBindVertexArray(VAO);

	/////////////////////////////////////////////////////
	// Bind VBO, copy vertices, set attribute pointers //
	/////////////////////////////////////////////////////
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(glm::vec3) * v.size(), (glm::vec3*) &v[0], GL_STATIC_DRAW);

	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(glm::vec3) * 2, (void*)0);

	glEnableVertexAttribArray(1);
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(glm::vec3) * 2, (void*)(sizeof(glm::vec3)));

	glBindBuffer(GL_ARRAY_BUFFER, 0);
	
	/////////////////////////////////////////////////////
	// Bind EBO, copy indices						   //
	/////////////////////////////////////////////////////
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(unsigned int) * i.size(), (unsigned int*) &i[0], GL_STATIC_DRAW);
	
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	
	/////////////////////////////////////////////////////
	// Create IBO for model matrices				   //
	/////////////////////////////////////////////////////
	unsigned int IBO_Model;
	glGenBuffers(1, &IBO_Model);
	glBindBuffer(GL_ARRAY_BUFFER, IBO_Model);  // Note: Bind as an array buffer here
	glBufferData(GL_ARRAY_BUFFER, 2 * sizeof(glm::mat4), modelMatrices, GL_STATIC_DRAW);  // Allocate space for 2 matrices

	// Set vertex attribute pointer for model matrices in VAO
	glEnableVertexAttribArray(2);
	glVertexAttribPointer(2, 4, GL_FLOAT, GL_FALSE, sizeof(glm::mat4), (void*)0);
	
	glEnableVertexAttribArray(3);
	glVertexAttribPointer(3, 4, GL_FLOAT, GL_FALSE, sizeof(glm::mat4), (void*)(1 * sizeof(glm::vec4)));

	glEnableVertexAttribArray(4);
	glVertexAttribPointer(4, 4, GL_FLOAT, GL_FALSE, sizeof(glm::mat4), (void*)(2 * sizeof(glm::vec4)));

	glEnableVertexAttribArray(5);
	glVertexAttribPointer(5, 4, GL_FLOAT, GL_FALSE, sizeof(glm::mat4), (void*)(3 * sizeof(glm::vec4)));

	glVertexAttribDivisor(2, 1); 
	glVertexAttribDivisor(3, 1); 
	glVertexAttribDivisor(4, 1); 
	glVertexAttribDivisor(5, 1); 

	glBindBuffer(GL_ARRAY_BUFFER, 0);

	glBindVertexArray(0);

	// Main rendering loop
	while (!glfwWindowShouldClose(window)) {
		// Clear screen
		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		// Use shader program
		glUseProgram(shaderProgram);

		// Bind VAO and draw using indexed rendering (instance rendering)
		glBindVertexArray(VAO);

		glDrawElementsInstanced(GL_TRIANGLES, i.size(), GL_UNSIGNED_INT, 0, 2);  // Draw 2 instances

		// Swap buffers and poll events
		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	// Deallocate resources
	glDeleteVertexArrays(1, &VAO);
	glDeleteBuffers(1, &VBO);
	glDeleteBuffers(1, &EBO);
	glDeleteProgram(shaderProgram);

	// Terminate GLFW
	glfwTerminate();
	return 0;
}