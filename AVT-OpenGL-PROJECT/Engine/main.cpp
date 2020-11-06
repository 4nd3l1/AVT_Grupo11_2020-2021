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
#include "HeaderFiles/Matrix4D.h"
#include "HeaderFiles/Camera.h"

const float Threshold = (float)1.0e-5;

int window_width;
int window_height;
float cursorX, cursorY;
float xOffset, yOffset;

Camera camera(Vector3D(3, 0, 3), Vector3D(0, 0, 0), Vector3D(0, 1, 0));
bool ortho = true;

// KEY PRESSED
bool forwardKeyPressed = false;
bool leftKeyPressed = false;
bool rightKeyPressed = false;
bool backwardKeyPressed = false;

bool upKeyPressed = false;
bool downKeyPressed = false;

bool lockMouse = true;
bool firstMouse = true;
bool mouseMoved = false;

bool quaternionRotation = false;
bool cameraReset = false;
bool stopRotating = false;
bool automaticRotating = true;

float view[16];
float proj[16];

////////////////////////////////////////////////////////////////////////// MAIN
void move_camera() {
	if (forwardKeyPressed) {
		camera.moveCameraForward(0.05f);
	}
	if (backwardKeyPressed) {
		camera.moveCameraBackward(0.05f);
	}

	// ROTATE CAMERA //

	if (!stopRotating) {
		if (!quaternionRotation) {
			if (automaticRotating) {
				camera.rotateCameraAround(1, { 1.0f, 0.0f, 0.0f, 1.0f });
				camera.rotateCameraAround(1, { 0.0f, 1.0f, 0.0f, 1.0f });
				camera.rotateCameraAround(1, { 0.0f, 0.0f, 1.0f, 1.0f });
			}
			else
				if (mouseMoved) {
					camera.rotateCameraAround(xOffset, { 1.0f, 0.0f, 0.0f, 1.0f });
					camera.rotateCameraAround(yOffset, { 0.0f, 0.0f, 0.0f, 1.0f });
					mouseMoved = false;
				}
		}
		else {
			if (automaticRotating) {
				camera.rotateCameraAroundQuaternion(1, { 1.0f, 1.0f, 1.0f, 1.0f });
			}	
			else
				if (mouseMoved) {
					camera.rotateCameraAroundQuaternion(xOffset, { 1.0f, 0.0f, 0.0f, 1.0f });
					camera.rotateCameraAroundQuaternion(yOffset, { 0.0f, 1.0f, 0.0f, 1.0f });
					mouseMoved = false;
				}
		}
	}
	// Get the updated view matrix
	Matrix4D viewM = camera.getViewMatrix();
	viewM.getRowMajor(view);
	cameraReset = false;
}

void mouse_keyboard_input() {
	if (mouseMoved) {
		camera.rotateCamera(xOffset, yOffset);
		mouseMoved = false;
	}

	if (forwardKeyPressed) {
		camera.moveCameraForward(0.03f);
	}
	if (backwardKeyPressed) {
		camera.moveCameraBackward(0.03f);
	}
	if (leftKeyPressed) {
		camera.moveCameraLeft(0.03f);
	}
	if (rightKeyPressed) {
		camera.moveCameraRight(0.03f);
	}

	if (upKeyPressed) {
		camera.moveCameraUp(0.03f);
	}

	if (downKeyPressed) {
		camera.moveCameraDown(0.03f);
	}
}

void set_view_proj() {
	Matrix4D viewM = camera.getViewMatrix();
	viewM.getRowMajor(view);

	Matrix4D projM;
	if (ortho) {
		projM = camera.getOrthProj();
	}
	else {
		projM = camera.getPerspProj();
	}
	projM.getRowMajor(proj);
}

void setupCamera() {
	// CAMERA SETUP //
	camera.setOrthoProjectionMatrix(-1, 1, -1, 1, 1, 10);
	camera.setPrespProjectionMatrix(15, (GLfloat)window_width / (GLfloat)window_height, 1, 10);

	//Set initial cursor position to be the middle of the screen
	cursorX = (float)window_width / 2;
	cursorY = (float)window_height / 2;
}

void key_callback(GLFWwindow* win, int key, int scancode, int action, int mods)
{
	// Key Presses
	if (action == GLFW_PRESS) {
		switch (key) {
			case GLFW_KEY_P:
				ortho = !ortho;
				if (ortho) {
					std::cout << "Orthogonal Mode!" << std::endl;
				}
				else {
					std::cout << "Prespective Mode!" << std::endl;
				}
				break;
			case GLFW_KEY_A:
				leftKeyPressed = true;
				break;
			case GLFW_KEY_D:
				rightKeyPressed = true;
				break;
			case GLFW_KEY_W:
				forwardKeyPressed = true;
				break;
			case GLFW_KEY_S:
				backwardKeyPressed = true;
				break;
			case GLFW_KEY_SPACE:
				upKeyPressed = true;
				break;
			case GLFW_KEY_LEFT_CONTROL:
				downKeyPressed = true;
				break;
			case GLFW_KEY_F:
				lockMouse = !lockMouse;
				if (lockMouse) {
					firstMouse = true;
				}
				break;
			case GLFW_KEY_I:
				camera.invertCamera();
				break;
			case GLFW_KEY_R:
				camera.resetCamera();
				break;
			case GLFW_KEY_G: {
				quaternionRotation = !quaternionRotation;
				if (quaternionRotation) {
					std::cout << "Quaternion Rotation Mode!" << std::endl;
				}
				else {
					std::cout << "Euler Rotation Mode!" << std::endl;
				}
				break;
			}	
			case GLFW_KEY_N: {
				automaticRotating = !automaticRotating;
				if (automaticRotating) {
					std::cout << "Auto Rotation Mode!" << std::endl;
				}
				else {
					std::cout << "Mouse Rotation Mode!" << std::endl;
				}
				break;
			}
		}
		
	}
	else if (action == GLFW_RELEASE) {
		switch (key) {
		case GLFW_KEY_A:
			leftKeyPressed = false;
			break;
		case GLFW_KEY_D:
			rightKeyPressed = false;
			break;
		case GLFW_KEY_W:
			forwardKeyPressed = false;
			break;
		case GLFW_KEY_S:
			backwardKeyPressed = false;
			break;
		case GLFW_KEY_SPACE:
			upKeyPressed = false;
			break;
		case GLFW_KEY_LEFT_CONTROL:
			downKeyPressed = false;
			break;
		}
	}
}

void mouse_callback(GLFWwindow* win, double xPos, double yPos) {
	/*
		1. Calculate the mouse's offset since the last frame.
		2. Add the offset values to the camera's yaw and pitch values.
		3. Add some constraints to the minimum/maximum pitch values.
		4. Calculate the direction vector.
	*/

	if (firstMouse) // initially set to true
	{
		cursorX = (float)xPos;
		cursorY = (float)yPos;
		firstMouse = false;
	}

	xOffset = (float)xPos - cursorX;
	yOffset = cursorY - (float)yPos; // reversed since y-coordinates range from bottom to top

	cursorX = (float)xPos;
	cursorY = (float)yPos;

	mouseMoved = true;
}

void setupCallbacks(GLFWwindow* win)
{
	glfwSetKeyCallback(win, key_callback);
	glfwSetCursorPosCallback(win, mouse_callback);
}

int main(int argc, char* argv[])
{
	GLFWwindow* window;

	/* Initialize the library */
	if (!glfwInit())
		return -1;

	/* Create a windowed mode window and its OpenGL context */
	window_width = 920;
	window_height = 920;
	window = glfwCreateWindow(window_width, window_height, "Hello World", NULL, NULL);
	
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

	setupCallbacks(window);
	setupCamera();

	//RED PART POSITIONS

	GLfloat pol_red[] = {
		-0.605f, -0.48f, 0.5f, 0.0f, 0.0f, 0.0f,
		- 0.54f, -0.605f, 0.5f, 0.0f, 0.0f, 0.0f,
		0.01f, 0.58f, 1.0f, 0.0f, 0.0f, 0.0f,
		0.01f, 0.34f, 1.0f, 0.0f, 0.0f, 0.0f,
		0.56f, -0.37f, 0.5f, 0.0f, 0.0f, 0.0f,
		0.42f, -0.37f,0.5f, 0.0f, 0.0f, 0.0f
	};

	GLfloat pol_green[] = {
		-0.605f, -0.48f, 0.0f, 0.5f, 0.0f, 0.0f,
		-0.54f, -0.605f, 0.0f, 0.5f, 0.0f, 0.0f,
		0.01f, 0.58f, 0.0f, 1.0f, 0.0f, 0.0f,
		0.01f, 0.34f, 0.0f, 1.0f, 0.0f, 0.0f,
		0.56f, -0.37f, 0.0f, 0.5f, 0.0f, 0.0f,
		0.42f, -0.37f,0.0f, 0.5f, 0.0f, 0.0f
	};

	GLfloat pol_blue[] = {
		-0.605f, -0.48f, 0.0f, 0.0f, 0.5f, 0.0f,
		-0.54f, -0.605f, 0.0f, 0.0f, 0.5f, 0.0f,
		0.01f, 0.58f, 0.0f, 0.0f, 1.0f, 0.0f,
		0.01f, 0.34f, 0.0f, 0.0f, 1.0f, 0.0f,
		0.56f, -0.37f, 0.0f, 0.0f, 0.5f, 0.0f,
		0.42f, -0.37f, 0.0f, 0.0f, 0.5f, 0.0f
	};


	//RED PART
	Matrix4D id = Matrix4D::identity();

	//GREEN PART
	Matrix4D m_rot_1 = Matrix4D::rotationZ(-120, false);
	Matrix4D m_transl_1 = Matrix4D::translation(0.26f,-0.192f,0.0f);
	Matrix4D m_modal_1 = (m_transl_1 * m_rot_1);

	//BLUE PART
	Matrix4D m_rot_2 = Matrix4D::rotationZ(120, false);
	Matrix4D m_transl_2 = Matrix4D::translation(-0.034f, -0.328f, 0.0f);
	Matrix4D m_modal_2 = (m_transl_2 * m_rot_2);


	//Generate index buffer
	GLuint indices[] = {
		2, 0, 1, 
		1, 3, 2, 
		2, 3, 5,
		5, 4, 2
	};
	GLuint indices_back[] = {
		2, 3, 1,
		1, 0, 2,
		2, 5, 3,
		5, 2, 4
	};

	//Generate a buffer layout
	VertexBufferLayout layout;
	layout.Push<float>(2);
	layout.Push<float>(4);
	

	//Generate a vertex buffer - RED PART
	VertexArray va;
	VertexBuffer vb (pol_red, 6 * 6 * sizeof(GLfloat));
	va.AddBuffer(vb, layout);


	//Generate an index buffers
	IndexBuffer ib(indices, 12);
	IndexBuffer ib_back(indices_back, 12);

	Shader shader("Engine/res/shaders/Basic.shader");


	va.UnBind();
	vb.Unbind();
	ib.Unbind();
	shader.UnBind();


	Renderer renderer;

	glEnable(GL_CULL_FACE);
	glFrontFace(GL_CCW);

	if (lockMouse) {
		glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED); //Tell GLFW that it should hide the cursorand capture it.Capturing a cursor means that, once the application has focus, the mouse cursor stays within the center of the window(unless the application loses focus or quits)
	}
	else {
		glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_NORMAL);
	}

	/* Loop until the user closes the window */
	while (!glfwWindowShouldClose(window))
	{
		renderer.clear();

		//mouse_keyboard_input();

		move_camera();

		set_view_proj();

		vb.Bind();
		vb.SubBufferData(0, 6 * 6 * sizeof(float), pol_red);
		shader.Bind();
		GLfloat arr[16];
		id.getRowMajor(arr);
		shader.SetUniform4fv("Modal", arr);
		shader.SetUniform4fv("View", view);
		shader.SetUniform4fv("Projection", proj);
		shader.SetUniform1i("isBack", 0);
		renderer.Draw(va, ib, shader);

		
		vb.Bind();
		vb.SubBufferData(0, 6 * 6 * sizeof(float), pol_green);
		shader.Bind();
		GLfloat arr1[16];
		m_modal_1.getRowMajor(arr1);
		shader.SetUniform4fv("Modal", arr1);
		shader.SetUniform4fv("View", view);
		shader.SetUniform4fv("Projection", proj);
		shader.SetUniform1i("isBack", 0);
		renderer.Draw(va, ib, shader);

		vb.Bind();
		vb.SubBufferData(0, 6 * 6 * sizeof(float), pol_blue);
		shader.Bind();
		GLfloat arr2[16];
		m_modal_2.getRowMajor(arr2);
		shader.SetUniform4fv("Modal", arr2);
		shader.SetUniform4fv("View", view);
		shader.SetUniform4fv("Projection", proj);
		shader.SetUniform1i("isBack", 0);
		renderer.Draw(va, ib, shader);

		
		//DRAW BACK FACE
		vb.Bind();
		vb.SubBufferData(0, 6 * 6 * sizeof(float), pol_red);
		shader.SetUniform4fv("Modal", arr);
		shader.SetUniform4fv("View", view);
		shader.SetUniform4fv("Projection", proj);
		shader.SetUniform1i("isBack", 1);
		renderer.Draw(va, ib_back, shader);

		vb.Bind();
		vb.SubBufferData(0, 6 * 6 * sizeof(float), pol_green);
		shader.SetUniform4fv("Modal", arr1);
		shader.SetUniform4fv("View", view);
		shader.SetUniform4fv("Projection", proj);
		shader.SetUniform1i("isBack", 1);
		renderer.Draw(va, ib_back, shader);

		vb.Bind();
		vb.SubBufferData(0, 6 * 6 * sizeof(float), pol_blue);
		shader.SetUniform4fv("Modal", arr2);
		shader.SetUniform4fv("View", view);
		shader.SetUniform4fv("Projection", proj);
		shader.SetUniform1i("isBack", 1);
		renderer.Draw(va, ib_back, shader);


		glfwSwapBuffers(window);

		glfwPollEvents();
	}

	glfwTerminate();
	return 0;



	exit(EXIT_SUCCESS);

}

/////////////////////////////////////////////////////////////////////////// END

