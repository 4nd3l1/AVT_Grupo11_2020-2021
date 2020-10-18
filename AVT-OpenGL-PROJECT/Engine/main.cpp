
#include <iostream>
#include <sstream>
#include <iomanip>

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "HeaderFiles/Vector2D.h"
#include "HeaderFiles/Vector3D.h"
#include "HeaderFiles/Vector4D.h"
#include "HeaderFiles/Matrix2D.h"
#include "HeaderFiles/Matrix3D.h"
#include "HeaderFiles/Matrix4D.h"
#include "HeaderFiles/VertexBuffer.h"
#include "HeaderFiles/IndexBuffer.h"
#include "HeaderFiles/Renderer.h"

#include <fstream>
#include <sstream>



struct ShaderProgramSource
{
	std::string VertexSource;
	std::string FragmentSource;
};


////////////////////////////////////////////////////////////////////////// MAIN

static ShaderProgramSource ParseShader(const std::string& path)
{

	std::ifstream stream(path);

	enum class ShaderType
	{
		NONE = -1, VERTEX = 0, FRAGMENT = 1
	};

	std::string line;
	std::stringstream ss[2];
	ShaderType type = ShaderType::NONE;

	while (getline(stream, line))
	{
		if (line.find("#shader") != std::string::npos) 
		{
			if (line.find("vertex") != std::string::npos)
			{
				type = ShaderType::VERTEX;
			}
			else if (line.find("fragment") != std::string::npos)
			{
				type = ShaderType::FRAGMENT;
			}
		}
		else
		{
			ss[(int)type] << line << '\n';
		}
	}

	return {ss[0].str(), ss[1].str()};
}

static GLuint CompileShader( GLuint type, const std::string& source)
{
	GLuint id = glCreateShader(type);
	const char* src = source.c_str();
	glShaderSource(id, 1, &src, nullptr);
	glCompileShader(id);

	int result;
	glGetShaderiv(id, GL_COMPILE_STATUS, &result);
	if (result == GL_FALSE) {
		int length;
		glGetShaderiv(id, GL_INFO_LOG_LENGTH, &length);
		char* message = (char*)alloca(length * sizeof(char));
		glGetShaderInfoLog(id, length, &length, message);
		std::cout << "Failed to compile " << (type == GL_VERTEX_SHADER ? "Vertex" : "Fragment") << " shader! \n";
		std::cout << message << "\n";
		glDeleteShader(id);
		return 0;
	}

	return id;
}


static GLuint CreateShader(const std::string& vertexShader, const std::string& fragmentShader) 
{
	GLuint program = glCreateProgram();
	GLuint vs = CompileShader(GL_VERTEX_SHADER, vertexShader);
	GLuint fs = CompileShader(GL_FRAGMENT_SHADER, fragmentShader);
	glAttachShader(program, vs);
	glAttachShader(program, fs);
	glLinkProgram(program);
	glValidateProgram(program);

	glDeleteShader(vs);
	glDeleteShader(fs);

	return program;
}



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

	float sq[] = {
			-0.605f,  -0.48f,
			-0.54f,  -0.605f,
			0.01f, 0.58f,
		    0.01f, 0.34f,
			0.56f, -0.37f,
			0.42f, -0.37f
			
	};

	//Generate index buffer
	GLuint indices[] = {
		0, 1, 2,
		2, 3, 1,
		2, 3, 5,
		5, 2, 4
	};


	//Generate a vertex array 
	GLuint vao;
	GLCall(glGenVertexArrays(1, &vao));
	GLCall(glBindVertexArray(vao));


	//Generate a Buffer and giving them the data to be used on drawing
	VertexBuffer vb (sq, 6 * 3 * sizeof(GLuint));
	

	//Telling OpenGL how to read the data passed before to the buffer that is bound	
	GLCall(glEnableVertexAttribArray(0));
	GLCall(glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(float), 0));


	//Generate an index buffer
	IndexBuffer ib(indices, 12);
	

	ShaderProgramSource source = ParseShader("Engine/res/shaders/Basic.shader");

	GLuint shader = CreateShader(source.VertexSource, source.FragmentSource);
	GLCall(glUseProgram(shader));

	//create uniform - design by drawing
	GLCall(GLCall(int location = glGetUniformLocation(shader, "u_Color")));
	ASSERT(location != -1);
	GLCall(GLCall(glUniform4f(location, 0.8f, 0.3f, 0.8f, 1.0f)));

	float r = 0.0f;
	float increment = 0.05f;

	/* Loop until the user closes the window */
	while (!glfwWindowShouldClose(window))
	{
		/* Render here */
		glClear(GL_COLOR_BUFFER_BIT);
		
		//Define the triangles color
		GLCall(glUniform4f(location, 1.0f, 0.0f, 0.0f, 0.0f));

		GLCall(glDrawElements(GL_TRIANGLES, 12, GL_UNSIGNED_INT, nullptr));

		/* Red channel animation
		if (r > 1.0f)
			increment = -0.05f;
		else if (r < 0.0f)
			increment = 0.05f;
		r += increment;
	*/

		/* Swap front and back buffers */
		glfwSwapBuffers(window);

		/* Poll for and process events */
		glfwPollEvents();
	}

	glDeleteProgram(shader);
	glfwTerminate();
	return 0;



	exit(EXIT_SUCCESS);

}

/////////////////////////////////////////////////////////////////////////// END

