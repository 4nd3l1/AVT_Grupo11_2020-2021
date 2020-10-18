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

	//GREEN PART POSITIONS
	Matrix4D m_rot_1 = Matrix4D::rotationZ(-119, false);
	Matrix4D m_transl_1 = Matrix4D::translation(0.265f,-0.187f,0.0f);
	Matrix4D m_modal_1 = (m_transl_1 * m_rot_1).transposed();
	

	float V6_4d_x = v0.getX();
	float V6_4d_y = v0.getY();
	Vector4D v6_4D(V6_4d_x, V6_4d_y, 1.0f, 1.0f);
	Vector4D v6_4D_transformed = v6_4D * m_modal_1;


	float V7_4d_x = v1.getX();
	float V7_4d_y = v1.getY();
	Vector4D v7_4D(V7_4d_x, V7_4d_y, 1.0f, 1.0f);
	Vector4D v7_4D_transformed = v7_4D * m_modal_1;

	float V8_4d_x = v2.getX();
	float V8_4d_y = v2.getY();
	Vector4D v8_4D(V8_4d_x, V8_4d_y, 1.0f, 1.0f);
	Vector4D v8_4D_transformed = v8_4D * m_modal_1;


	float V9_4d_x = v3.getX();
	float V9_4d_y = v3.getY();
	Vector4D v9_4D(V9_4d_x, V9_4d_y, 1.0f, 1.0f);
	Vector4D v9_4D_transformed = v9_4D * m_modal_1;


	float V10_4d_x = v4.getX();
	float V10_4d_y = v4.getY();
	Vector4D v10_4D(V10_4d_x, V10_4d_y, 1.0f, 1.0f);
	Vector4D v10_4D_transformed = v10_4D * m_modal_1;


	float V11_4d_x = v5.getX();
	float V11_4d_y = v5.getY();
	Vector4D v11_4D(V11_4d_x, V11_4d_y, 1.0f, 1.0f);
	Vector4D v11_4D_transformed = v11_4D * m_modal_1;

	//BLUE PART POSITIONS
	Matrix4D m_rot_2 = Matrix4D::rotationZ(120, false);
	Matrix4D m_transl_2 = Matrix4D::translation(-0.03f, -0.33f, 0.0f);
	Matrix4D m_modal_2 = (m_transl_2 * m_rot_2).transposed();


	float V12_4d_x = v0.getX();
	float V12_4d_y = v0.getY();
	Vector4D v12_4D(V12_4d_x, V12_4d_y, 1.0f, 1.0f);
	Vector4D v12_4D_transformed = v12_4D * m_modal_2;


	float V13_4d_x = v1.getX();
	float V13_4d_y = v1.getY();
	Vector4D v13_4D(V13_4d_x, V13_4d_y, 1.0f, 1.0f);
	Vector4D v13_4D_transformed = v13_4D * m_modal_2;

	float V14_4d_x = v2.getX();
	float V14_4d_y = v2.getY();
	Vector4D v14_4D(V14_4d_x, V14_4d_y, 1.0f, 1.0f);
	Vector4D v14_4D_transformed = v14_4D * m_modal_2;


	float V15_4d_x = v3.getX();
	float V15_4d_y = v3.getY();
	Vector4D v15_4D(V15_4d_x, V15_4d_y, 1.0f, 1.0f);
	Vector4D v15_4D_transformed = v15_4D * m_modal_2;


	float V16_4d_x = v4.getX();
	float V16_4d_y = v4.getY();
	Vector4D v16_4D(V16_4d_x, V16_4d_y, 1.0f, 1.0f);
	Vector4D v16_4D_transformed = v16_4D * m_modal_2;


	float V17_4d_x = v5.getX();
	float V17_4d_y = v5.getY();
	Vector4D v17_4D(V17_4d_x, V17_4d_y, 1.0f, 1.0f);
	Vector4D v17_4D_transformed = v17_4D * m_modal_2;


	float pol_red[] = {
			v0.getX(),  v0.getY(), 0.1f, 0.0f, 0.0f,
			v1.getX(),  v1.getY(), 0.1f, 0.0f, 0.0f,
			v2.getX(),  v2.getY(), 1.1f, 0.0f, 0.0f,
			v3.getX(),  v3.getY(), 1.1f, 0.0f, 0.0f,
			v4.getX(),  v4.getY(), 0.1f, 0.0f, 0.0f,
			v5.getX(),  v5.getY(), 0.1f, 0.0f, 0.0f,
	};

	float pol_green[] = {
			v6_4D_transformed.getX(),  v6_4D_transformed.getY(), 0.0f, 0.1f, 0.0f,
			v7_4D_transformed.getX(),  v7_4D_transformed.getY(), 0.0f, 0.1f, 0.0f,
			v8_4D_transformed.getX(),  v8_4D_transformed.getY(), 0.0f, 1.1f, 0.0f,
			v9_4D_transformed.getX(),  v9_4D_transformed.getY(), 0.0f, 1.1f, 0.0f,
			v10_4D_transformed.getX(),  v10_4D_transformed.getY(), 0.0f, 0.1f, 0.0f,
			v11_4D_transformed.getX(),  v11_4D_transformed.getY(), 0.0f, 0.1f, 0.0f,
	};

	float pol_blue[] = {
			v12_4D_transformed.getX(),  v12_4D_transformed.getY(), 0.0f, 0.0f, 0.1f,
			v13_4D_transformed.getX(),  v13_4D_transformed.getY(), 0.0f, 0.0f, 0.1f,
			v14_4D_transformed.getX(),  v14_4D_transformed.getY(), 0.0f, 0.0f, 1.1f,
			v15_4D_transformed.getX(),  v15_4D_transformed.getY(), 0.0f, 0.0f, 1.1f,
			v16_4D_transformed.getX(),  v16_4D_transformed.getY(), 0.0f, 0.0f, 0.1f,
			v17_4D_transformed.getX(),  v17_4D_transformed.getY(), 0.0f, 0.0f, 0.1f,
	};

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
	layout.Push<float>(3);
	

	//Generate a vertex buffer - RED PART
	VertexArray va;
	VertexBuffer vb (pol_red, 6 * 5 * sizeof(GLuint));
	va.AddBuffer(vb, layout);

	//Generate a vertex buffer - GREEN PART
	VertexArray va_g;
	VertexBuffer vb_g (pol_green, 6 * 5 * sizeof(GLuint));
	va_g.AddBuffer(vb_g, layout);

	//Generate a vertex buffer - BLUE PART	
	VertexArray va_b;
	VertexBuffer vb_b(pol_blue, 6 * 5 * sizeof(GLuint));
	va_b.AddBuffer(vb_b, layout);

	//Generate an index buffer
	IndexBuffer ib(indices, 12);

	Shader shader("Engine/res/shaders/Basic.shader");

	/*
	shader.Bind();
	shader.SetUniform4f("cc", 1.0f, 0.0f, 0.0f, 0.0f);
	*/

	va.UnBind();
	va_g.UnBind();
	va_b.UnBind();
	vb.Unbind();
	vb_g.Unbind();
	vb_b.Unbind();
	ib.Unbind();
	shader.UnBind();


	Renderer renderer;

	/* Loop until the user closes the window */
	while (!glfwWindowShouldClose(window))
	{
		renderer.clear();
		
		renderer.Draw(va, ib, shader);
		renderer.Draw(va_g, ib, shader);
		renderer.Draw(va_b, ib, shader);


		glfwSwapBuffers(window);

		glfwPollEvents();
	}

	glfwTerminate();
	return 0;



	exit(EXIT_SUCCESS);

}

/////////////////////////////////////////////////////////////////////////// END

