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
#include "HeaderFiles/Vector2D.h"
#include "HeaderFiles/Vector3D.h"
#include "HeaderFiles/Vector4D.h"
#include "HeaderFiles/Matrix4D.h"


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

	//RED PART POSITIONS
	Vector2D v0(-0.605f, -0.48f);
	Vector2D v1(-0.54f, -0.605f);
	Vector2D v2(0.01f, 0.58f);
	Vector2D v3(0.01f, 0.34f);
	Vector2D v4(0.56f, -0.37f);
	Vector2D v5(0.42f, -0.37f);

	GLfloat pol[] = {
		-0.605f, -0.48f, 0.5f, 0.0f, 0.0f, 0.0f,
		-0.54f, -0.605f, 0.5f, 0.0f, 0.0f, 0.0f,
		0.01f, 0.58f, 1.0f, 0.0f, 0.0f, 0.0f,
		0.01f, 0.34f, 1.0f, 0.0f, 0.0f, 0.0f,
		0.56f, -0.37f, 0.5f, 0.0f, 0.0f, 0.0f,
		0.42f, -0.37f,0.5f, 0.0f, 0.0f, 0.0f
	};

	//RED PART
	Matrix4D id = Matrix4D::identity();

	//GREEN PART
	Matrix4D m_rot_1 = Matrix4D::rotationZ(-119, false);
	Matrix4D m_transl_1 = Matrix4D::translation(0.265f,-0.187f,0.0f);
	Matrix4D m_modal_1 = (m_transl_1 * m_rot_1).transposed();

	//BLUE PART
	Matrix4D m_rot_2 = Matrix4D::rotationZ(120, false);
	Matrix4D m_transl_2 = Matrix4D::translation(-0.03f, -0.33f, 0.0f);
	Matrix4D m_modal_2 = (m_transl_2 * m_rot_2).transposed();


	//Generate index buffer
	GLuint indices[] = {
		0, 1, 2,
		2, 3, 1,
		2, 3, 5,
		5, 2, 4
	};

	//Generate a buffer layout
	VertexBufferLayout layout;
	layout.Push<float>(2);
	layout.Push<float>(4);
	

	//Generate a vertex buffer - RED PART
	VertexArray va;
	VertexBuffer vb (pol, 6 * 6 * sizeof(GLuint));
	va.AddBuffer(vb, layout);


	//Generate an index buffer
	IndexBuffer ib(indices, 12);

	Shader shader("Engine/res/shaders/Basic.shader");

	/*
	shader.Bind();
	shader.SetUniform4f("cc", 1.0f, 0.0f, 0.0f, 0.0f);
	*/

	va.UnBind();
	vb.Unbind();
	ib.Unbind();
	shader.UnBind();


	Renderer renderer;

	/* Loop until the user closes the window */
	while (!glfwWindowShouldClose(window))
	{
		renderer.clear();

		GLfloat arr[16];
		id.getRowMajor(arr);
		GLfloat red1[4] = { 0.5f, 0.0f, 0.0f, 0.0f };
		GLfloat red2[4] = { 1.0f, 0.0f, 0.0f, 0.0f };
		vb.Bind();
		vb.SubBufferData(2 * sizeof(GLfloat), 4 * sizeof(float), red1);
		vb.SubBufferData(8 * sizeof(GLfloat), 4 * sizeof(float), red1);
		vb.SubBufferData(14 * sizeof(GLfloat), 4 * sizeof(float), red2);
		vb.SubBufferData(20 * sizeof(GLfloat), 4 * sizeof(float), red2);
		vb.SubBufferData(26 * sizeof(GLfloat), 4 * sizeof(float), red1);
		vb.SubBufferData(32 * sizeof(GLfloat), 4 * sizeof(float), red1);
		shader.Bind();
		shader.SetUniform4fv("Matrix", arr);
		renderer.Draw(va, ib, shader);

		GLfloat arr1[16];
		m_modal_1.getRowMajor(arr1);
		GLfloat green1[4] = {0.0f, 0.5f, 0.0f, 0.0f};
		GLfloat green2[4] = { 0.0f, 1.0f, 0.0f, 0.0f };
		vb.Bind();
		vb.SubBufferData(2*sizeof(GLfloat), 4 * sizeof(float), green1);
		vb.SubBufferData(8 * sizeof(GLfloat), 4 * sizeof(float), green1);
		vb.SubBufferData(14 * sizeof(GLfloat), 4 * sizeof(float), green2);
		vb.SubBufferData(20 * sizeof(GLfloat), 4 * sizeof(float), green2);
		vb.SubBufferData(26 * sizeof(GLfloat), 4 * sizeof(float), green1);
		vb.SubBufferData(32 * sizeof(GLfloat), 4 * sizeof(float), green1);
		shader.Bind();
		shader.SetUniform4fv("Matrix", arr1);
		renderer.Draw(va, ib, shader);

		GLfloat arr2[16];
		m_modal_2.getRowMajor(arr2);
		GLfloat blue1[4] = { 0.0f, 0.0f, 0.5f, 0.0f };
		GLfloat blue2[4] = { 0.0f, 0.0f, 1.0f, 0.0f };
		vb.Bind();
		vb.SubBufferData(2 * sizeof(GLfloat), 4 * sizeof(float), blue1);
		vb.SubBufferData(8 * sizeof(GLfloat), 4 * sizeof(float), blue1);
		vb.SubBufferData(14 * sizeof(GLfloat), 4 * sizeof(float), blue2);
		vb.SubBufferData(20 * sizeof(GLfloat), 4 * sizeof(float), blue2);
		vb.SubBufferData(26 * sizeof(GLfloat), 4 * sizeof(float), blue1);
		vb.SubBufferData(32 * sizeof(GLfloat), 4 * sizeof(float), blue1);
		shader.Bind();
		shader.SetUniform4fv("Matrix", arr2);
		renderer.Draw(va, ib, shader);
	


		glfwSwapBuffers(window);

		glfwPollEvents();
	}

	glfwTerminate();
	return 0;



	exit(EXIT_SUCCESS);

}

/////////////////////////////////////////////////////////////////////////// END

