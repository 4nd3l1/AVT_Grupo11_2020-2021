#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <iostream>
#include <sstream>
#include <fstream>
#include <sstream>

#include "HeaderFiles/Renderer.h";

#include "HeaderFiles/VertexBuffer.h"
#include "HeaderFiles/VertexBufferLayout.h"
#include "HeaderFiles/IndexBuffer.h"
#include "HeaderFiles/VertexArray.h"
#include "HeaderFiles/Shader.h"


////////////////////////////////////////////////////////////////////////// MAIN

int main(int argc, char* argv[])
{
	GLFWwindow* window;

	/* Initialize the library */
	if (!glfwInit())
		return -1;

	/* Create a windowed mode window and its OpenGL context */
	window = glfwCreateWindow(640, 480, "Hello World", NULL, NULL);
	if (!window)
	{
		glfwTerminate();
		return -1;
	}

	/* Make the window's context current */
	glfwMakeContextCurrent(window);

	// Initialize Glew
	glewExperimental = GL_TRUE;
	glewInit();

	float pol_red[] = {
			-0.605f,  -0.48f, 0.0f, 0.0f, 0.0f, 
			-0.54f,  -0.605f, 0.0f, 0.0f, 0.0f,
			0.01f, 0.58f, 1.0f, 0.0f, 0.0f,
		    0.01f, 0.34f, 1.0f, 0.0f, 0.0f,
			0.56f, -0.37f, 0.0f, 0.0f, 0.0f,
			0.42f, -0.37f, 0.0f, 0.0f, 0.0f,
			
	};

	//Generate index buffer
	GLuint indices[] = {
		0, 1, 2,
		2, 3, 1,
		2, 3, 5,
		5, 2, 4
	};


	//Generate a vertex array and buffer and binding them
	VertexArray va;
	VertexBuffer vb (pol_red, 6 * 5 * sizeof(GLuint));

	VertexBufferLayout layout;
	layout.Push<float>(2);
	layout.Push<float>(3);
	va.AddBuffer(vb, layout);

	//Generate an index buffer
	IndexBuffer ib(indices, 12);

	Shader shader("Engine/res/shaders/Basic.shader");
	shader.Bind();
	shader.SetUniform4f("cc", 1.0f, 0.0f, 0.0f, 0.0f);

	va.UnBind();
	vb.Unbind();
	ib.Unbind();
	shader.UnBind();


	Renderer renderer;

	/* Loop until the user closes the window */
	while (!glfwWindowShouldClose(window))
	{
		renderer.clear();
	
		renderer.Draw(va, ib, shader);

		glfwSwapBuffers(window);

		glfwPollEvents();
	}

	glfwTerminate();
	return 0;



	exit(EXIT_SUCCESS);

}

/////////////////////////////////////////////////////////////////////////// END

