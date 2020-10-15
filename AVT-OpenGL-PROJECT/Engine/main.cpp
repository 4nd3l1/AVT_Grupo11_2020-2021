///////////////////////////////////////////////////////////////////////////////
//
// Assignment 1 consists in the following:
//
// - Update your graphics drivers to their latest versions.
// - Download the appropriate libraries GLEW and GLFW for your system.
// - Create a project to compile, link and run the code provided in this 
//   section in your favourite programming environment 
//   (course will use VS2019 Community Edition).
// - Verify what OpenGL contexts your computer can support, a minimum of 
//   OpenGL 3.3 support is required for this course.
//
// Further suggestions to verify your understanding of the concepts explored:
// - Create an abstract class for an OpenGL application.
// - Change the program so display is called at 30 FPS.
//
// (c)2013-20 by Carlos Martinho
//
///////////////////////////////////////////////////////////////////////////////

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


////////////////////////////////////////////////// ERROR CALLBACK (OpenGL 4.3+)

static const std::string errorSource(GLenum source)
{
	switch (source) {
	case GL_DEBUG_SOURCE_API:				return "API";
	case GL_DEBUG_SOURCE_WINDOW_SYSTEM:		return "window system";
	case GL_DEBUG_SOURCE_SHADER_COMPILER:	return "shader compiler";
	case GL_DEBUG_SOURCE_THIRD_PARTY:		return "third party";
	case GL_DEBUG_SOURCE_APPLICATION:		return "application";
	case GL_DEBUG_SOURCE_OTHER:				return "other";
	default:								exit(EXIT_FAILURE);
	}
}

static const std::string errorType(GLenum type)
{
	switch (type) {
	case GL_DEBUG_TYPE_ERROR:				return "error";
	case GL_DEBUG_TYPE_DEPRECATED_BEHAVIOR:	return "deprecated behavior";
	case GL_DEBUG_TYPE_UNDEFINED_BEHAVIOR:	return "undefined behavior";
	case GL_DEBUG_TYPE_PORTABILITY:			return "portability issue";
	case GL_DEBUG_TYPE_PERFORMANCE:			return "performance issue";
	case GL_DEBUG_TYPE_MARKER:				return "stream annotation";
	case GL_DEBUG_TYPE_PUSH_GROUP:			return "push group";
	case GL_DEBUG_TYPE_POP_GROUP:			return "pop group";
	case GL_DEBUG_TYPE_OTHER_ARB:			return "other";
	default:								exit(EXIT_FAILURE);
	}
}

static const std::string errorSeverity(GLenum severity)
{
	switch (severity) {
	case GL_DEBUG_SEVERITY_HIGH:			return "high";
	case GL_DEBUG_SEVERITY_MEDIUM:			return "medium";
	case GL_DEBUG_SEVERITY_LOW:				return "low";
	case GL_DEBUG_SEVERITY_NOTIFICATION:	return "notification";
	default:								exit(EXIT_FAILURE);
	}
}

static void error(GLenum source, GLenum type, GLuint id, GLenum severity, GLsizei length,
	const GLchar* message, const void* userParam)
{
	std::cerr << "GL ERROR:" << std::endl;
	std::cerr << "  source:     " << errorSource(source) << std::endl;
	std::cerr << "  type:       " << errorType(type) << std::endl;
	std::cerr << "  severity:   " << errorSeverity(severity) << std::endl;
	std::cerr << "  debug call: " << std::endl << message << std::endl << std::endl;
}

void setupErrorCallback()
{
	glEnable(GL_DEBUG_OUTPUT);
	glDebugMessageCallback(error, 0);
	glEnable(GL_DEBUG_OUTPUT_SYNCHRONOUS);
	glDebugMessageControl(GL_DONT_CARE, GL_DONT_CARE, GL_DONT_CARE, 0, 0, GL_TRUE);
	// params: source, type, severity, count, ids, enabled
}

///////////////////////////////////////////////// ERROR HANDLING (All versions)

static const std::string errorString(GLenum error)
{
	switch(error) {
	case GL_NO_ERROR:
		return "No error has been recorded.";
	case GL_INVALID_ENUM:
		return "An unacceptable value is specified for an enumerated argument.";
	case GL_INVALID_VALUE:
		return "A numeric argument is out of range.";
	case GL_INVALID_OPERATION:
		return "The specified operation is not allowed in the current state.";
	case GL_INVALID_FRAMEBUFFER_OPERATION:
		return "The framebuffer object is not complete.";
	case GL_OUT_OF_MEMORY:
		return "There is not enough memory left to execute the command.";
	case GL_STACK_UNDERFLOW:
		return "An attempt has been made to perform an operation that would cause an internal stack to underflow.";
	case GL_STACK_OVERFLOW:
		return "An attempt has been made to perform an operation that would cause an internal stack to overflow.";
	default: exit(EXIT_FAILURE);
	}
}

static bool isOpenGLError() 
{
	bool isError = false;
	GLenum errCode;
	while ((errCode = glGetError()) != GL_NO_ERROR) {
		isError = true;
		std::cerr << "OpenGL ERROR [" << errorString(errCode) << "]." << std::endl;
	}
	return isError;
}

static void checkOpenGLError(std::string error)
{
	if (isOpenGLError()) {
		std::cerr << error << std::endl;
		exit(EXIT_FAILURE);
	}
}

///////////////////////////////////////////////////////////////////// CALLBACKS

void window_close_callback(GLFWwindow* win)
{
	std::cout << "closing..." << std::endl;
}

void window_size_callback(GLFWwindow* win, int winx, int winy)
{
	std::cout << "size: " << winx << " " << winy << std::endl;
	glViewport(0, 0, winx, winy);
}

void key_callback(GLFWwindow* win, int key, int scancode, int action, int mods)
{
	std::cout << "key: " << key << " " << scancode << " " << action << " " << mods << std::endl;
	if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
	{
		glfwSetWindowShouldClose(win, GLFW_TRUE);
		window_close_callback(win);
	}
}

void mouse_callback(GLFWwindow* win, double xpos, double ypos)
{
	std::cout << "mouse: " << xpos << " " << ypos << std::endl;
}

void mouse_button_callback(GLFWwindow* win, int button, int action, int mods)
{
	std::cout << "button: " << button << " " << action << " " << mods << std::endl;
}

void scroll_callback(GLFWwindow* win, double xoffset, double yoffset)
{
	std::cout << "scroll: " << xoffset << " " << yoffset << std::endl;
}

void joystick_callback(int jid, int event)
{
	std::cout << "joystick: " << jid << " " << event << std::endl;
}

///////////////////////////////////////////////////////////////////////// SETUP

void glfw_error_callback(int error, const char* description)
{
	std::cerr << "GLFW Error: " << description << std::endl;
}

GLFWwindow* setupWindow(int winx, int winy, const char* title, 
	int is_fullscreen, int is_vsync)
{
	GLFWmonitor* monitor = is_fullscreen ? glfwGetPrimaryMonitor() : 0;
	GLFWwindow* win = glfwCreateWindow(winx, winy, title, monitor, 0);
	if (!win)
	{
		glfwTerminate();
		exit(EXIT_FAILURE);
	}
	glfwMakeContextCurrent(win);
	glfwSwapInterval(is_vsync);
	return win;
}

void setupCallbacks(GLFWwindow* win)
{
	glfwSetKeyCallback(win, key_callback);
	glfwSetCursorPosCallback(win, mouse_callback);
	glfwSetMouseButtonCallback(win, mouse_button_callback);
	glfwSetScrollCallback(win, scroll_callback);
	glfwSetJoystickCallback(joystick_callback);

	glfwSetWindowCloseCallback(win, window_close_callback);
	glfwSetWindowSizeCallback(win, window_size_callback);
}

GLFWwindow* setupGLFW(int gl_major, int gl_minor, 
	int winx, int winy, const char* title, int is_fullscreen, int is_vsync)
{
	glfwSetErrorCallback(glfw_error_callback);
	if (!glfwInit())
	{
		exit(EXIT_FAILURE);
	}
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, gl_major);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, gl_minor);
	glfwWindowHint(GLFW_OPENGL_DEBUG_CONTEXT, GLFW_TRUE);

	GLFWwindow* win = setupWindow(winx, winy, title, is_fullscreen, is_vsync);
	setupCallbacks(win);

#if _DEBUG
	std::cout << "GLFW " << glfwGetVersionString() << std::endl;
#endif
	return win;
}

void setupGLEW()
{
	glewExperimental = GL_TRUE;
	// Allow extension entry points to be loaded even if the extension isn't 
	// present in the driver's extensions string.
	GLenum result = glewInit();
	if (result != GLEW_OK) 
	{
		std::cerr << "ERROR glewInit: " << glewGetString(result) << std::endl;
		exit(EXIT_FAILURE);
	}
	GLenum err_code = glGetError();
	// You might get GL_INVALID_ENUM when loading GLEW.
}

void checkOpenGLInfo()
{
	const GLubyte* renderer = glGetString(GL_RENDERER);
	const GLubyte* vendor = glGetString(GL_VENDOR);
	const GLubyte* version = glGetString(GL_VERSION);
	const GLubyte* glslVersion = glGetString(GL_SHADING_LANGUAGE_VERSION);
	std::cerr << "OpenGL Renderer: " << renderer << " (" << vendor << ")" << std::endl;
	std::cerr << "OpenGL version " << version << std::endl;
	std::cerr << "GLSL version " << glslVersion << std::endl;
}

void setupOpenGL(int winx, int winy)
{
#if _DEBUG
	checkOpenGLInfo();
#endif
	glClearColor(0.1f, 0.1f, 0.3f, 1.0f);
	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LEQUAL);
	glDepthMask(GL_TRUE);
	glDepthRange(0.0, 1.0);
	glClearDepth(1.0);
	glEnable(GL_CULL_FACE);
	glCullFace(GL_BACK);
	glFrontFace(GL_CCW);
	glViewport(0, 0, winx, winy);
}

GLFWwindow* setup(int major, int minor, 
	int winx, int winy, const char* title, int is_fullscreen, int is_vsync)
{
	GLFWwindow* win = 
		setupGLFW(major, minor, winx, winy, title, is_fullscreen, is_vsync);
	setupGLEW();
	setupOpenGL(winx, winy);
	setupErrorCallback();
	return win;
}

////////////////////////////////////////////////////////////////////////// RUN

void updateFPS(GLFWwindow* win, double elapsed_sec)
{	
	static unsigned int acc_frames = 0;
	static double acc_time = 0.0;
	const double UPDATE_TIME = 1.0;

	++acc_frames;
	acc_time += elapsed_sec;
	if (acc_time > UPDATE_TIME)
	{
		std::ostringstream oss;
		double fps = acc_frames / acc_time;
		oss << std::fixed << std::setw(5) << std::setprecision(1) << fps << " FPS";
		glfwSetWindowTitle(win, oss.str().c_str());

		acc_frames = 0;
		acc_time = 0.0;
	}
}

void display_callback(GLFWwindow* win, double elapsed_sec)
{
	updateFPS(win, elapsed_sec);
}

void run(GLFWwindow* win)
{
	double last_time = glfwGetTime();
	while (!glfwWindowShouldClose(win))
	{
		double time = glfwGetTime();
		double elapsed_time = time - last_time;
		last_time = time;

		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		display_callback(win, elapsed_time);
		glfwSwapBuffers(win);
		glfwPollEvents();

		//checkOpenGLError("ERROR: MAIN/RUN");
	}
	glfwDestroyWindow(win);
	glfwTerminate();
}

////////////////////////////////////////////////////////////////////////// MAIN

void test2D() {
	Vector2D v1;
	Vector2D v2(0.1f, 0.2f);

	std::cout << "Test constructor #1: " << v1.toString() << "\n";
	std::cout << "Test constructor #2: " << v2.toString() << "\n";

	std::cout << "Test clone v2: " << v2.clone().toString() << "\n";

	std::cout << "Test operator v1 += v2: " << (v1 += v2).toString() << "\n";

	std::cout << "Test operator v1 + v2: " << (v1 + v2).toString() << "\n";

	std::cout << "Test operator v1 -= v2: " << (v1 -= v2).toString() << "\n";

	std::cout << "Test operator v1 - v2: " << (v1 - v2).toString() << "\n";

	std::cout << "Test operator v2 *= 2.0f: " << (v2 *= 2.0f).toString() << "\n";

	std::cout << "Test operator v2 * 2.0f: " << (v2 * 2.0f).toString() << "\n";

	std::cout << "Test operator float 2.0f * v2 : " << (2.0f * v2).toString() << "\n";

	std::cout << "Test operator v2 /= 2.0f: " << (v2 /= 2.0f).toString() << "\n";

	std::cout << "Test operator v2 / 2.0f: " << (v2 / 2.0f).toString() << "\n";

	std::cout << "Test operator 2.0f / v2: " << (2.0f / v1).toString() << "\n";

	std::cout << "Test v1 dot v2: " << v1.dot(v2) << "\n";

	std::cout << "Test -v2: " << (-v2).toString() << "\n";

	Vector2D v4;
	Vector2D v5;
	Vector2D v6(0.1f, 0.1f);
	std::cout << "Test compare v4(0,0) = v5(0,0) : " << v4.compare(v5) << "\n";
	std::cout << "Test compare v4(0,0) = v6(0.1f, 0.1f) : " << v4.compare(v6) << "\n";

	std::cout << "Test lenght v1: " << v1.length() << "\n";

	v2.normalize();
	std::cout << "Test normalize v2: " << v2.toString() << "\n";

}


void test3D() {

	Vector3D v1;
	Vector3D v2 (0.1f, 0.2f, 0.3f);

	std::cout << "Test constructor #1: " << v1.toString() << "\n";
	std::cout << "Test constructor #2: " << v2.toString() << "\n";

	std::cout << "Test clone v2: " << v2.clone().toString() << "\n";

	std::cout << "Test operator v1 += v2: " << (v1 += v2).toString() << "\n";

	std::cout << "Test operator v1 + v2: " << (v1 + v2).toString() << "\n";

	std::cout << "Test operator v1 -= v2: " << (v1 -= v2).toString() << "\n";

	std::cout << "Test operator v1 - v2: " << (v1 - v2).toString() << "\n";

	std::cout << "Test operator v2 *= 2.0f: " << (v2 *= 2.0f).toString() << "\n";

	std::cout << "Test operator v2 * 2.0f: " << (v2 * 2.0f).toString() << "\n";

	std::cout << "Test operator float 2.0f * v2 : " << (2.0f * v2).toString() << "\n";

	std::cout << "Test operator v2 /= 2.0f: " << (v2 /= 2.0f).toString() << "\n";

	std::cout << "Test operator v2 / 2.0f: " << (v2 / 2.0f).toString() << "\n";

	std::cout << "Test operator 2.0f / v2: " << (2.0f / v1).toString() << "\n";

	std::cout << "Test v1 cross v2: " << v1.cross(v2).toString() << "\n";

	std::cout << "Test v1 dot v2: " << v1.dot(v2) << "\n";

	std::cout << "Test -v2: " << (-v2).toString() << "\n";

	Vector3D v4;
	Vector3D v5;
	Vector3D v6 (0.1f, 0.1f, 0.1f);
	std::cout << "Test compare v4(0,0,0) = v5(0,0,0) : " << v4.compare(v5) << "\n";
	std::cout << "Test compare v4(0,0,0) = v6(0.1f, 0.1f, 0.1f) : " << v4.compare(v6) << "\n";

	std::cout << "Test lenght v1: " << v1.length() << "\n";

	v2.normalize();
	std::cout << "Test normalize v2: " << v2.toString() << "\n";
}


void test4D() {
	Vector4D v1;
	Vector4D v2(0.1f, 0.2f, 0.3f, 0.4f);

	std::cout << "Test constructor #1: " << v1.toString() << "\n";
	std::cout << "Test constructor #2: " << v2.toString() << "\n";

	std::cout << "Test clone v2: " << v2.clone().toString() << "\n";

	std::cout << "Test operator v1 += v2: " << (v1 += v2).toString() << "\n";

	std::cout << "Test operator v1 + v2: " << (v1 + v2).toString() << "\n";

	std::cout << "Test operator v1 -= v2: " << (v1 -= v2).toString() << "\n";

	std::cout << "Test operator v1 - v2: " << (v1 - v2).toString() << "\n";

	std::cout << "Test operator v2 *= 2.0f: " << (v2 *= 2.0f).toString() << "\n";

	std::cout << "Test operator v2 * 2.0f: " << (v2 * 2.0f).toString() << "\n";

	std::cout << "Test operator float 2.0f * v2 : " << (2.0f * v2).toString() << "\n";

	std::cout << "Test operator v2 /= 2.0f: " << (v2 /= 2.0f).toString() << "\n";

	std::cout << "Test operator v2 / 2.0f: " << (v2 / 2.0f).toString() << "\n";

	std::cout << "Test operator 2.0f / v2: " << (2.0f / v1).toString() << "\n";

	std::cout << "Test v1 dot v2: " << v1.dot(v2) << "\n";

	std::cout << "Test -v2: " << (-v2).toString() << "\n";

	Vector4D v4;
	Vector4D v5;
	Vector4D v6(0.1f, 0.1f, 0.1f, 0.1f);
	std::cout << "Test compare v4(0,0,0,0) = v5(0,0,0,0) : " << v4.compare(v5) << "\n";
	std::cout << "Test compare v4(0,0,0) = v6(0.1f, 0.1f, 0.1f, 0.1f) : " << v4.compare(v6) << "\n";

	std::cout << "Test lenght v1: " << v1.length() << "\n";

	v2.normalize();
	std::cout << "Test normalize v2: " << v2.toString() << "\n";
}

void testVectors() {
	int choice;
	std::cout << "Select '2', '3' or '4' if you want to test 2D, 3D or 4D vectors respectively: \n";
	std::cin >> choice;
	switch (choice) {
		case(2):
		{
			test2D();
			break;
		}	

		case(3):
		{
			test3D();
			break;
		}

		default:
		{
			test4D();
			break;
		}
	}
}

void createVector() {
	std::cout << "Select '2', '3' or '4' if you want to create a 2D, 3D or 4D vectors respectively \n";
	int choice;
	std::cin >> choice;
	float x, y, z, w;
	switch (choice) {
		case(2):
		{
			std::cout << "Please enter the coordinates for the vector with a space as interval: \n";
			std::cin >> x;
			std::cin >> y;
			Vector2D vec2 (x, y);
			std::cout << "Vector successfully created! - " << vec2.toString() << " \n";
			break;
		}
		
		case(3):
		{
			std::cout << "Please enter the coordinates for the vector with a space as interval: \n";
			std::cin >> x;
			std::cin >> y;
			std::cin >> z;
			Vector3D vec3 (x, y, z);
			std::cout << "Vector successfully created! - " << vec3.toString() << " \n";
			break;
		}
		
		default:
		{
			std::cout << "Please enter the coordinates for the vector with a space as interval: \n";
			std::cin >> x;
			std::cin >> y;
			std::cin >> z;
			std::cin >> w;
			Vector4D vec4 (x, y, z, w);
			std::cout << "Vector successfully created! - " << vec4.toString() << " \n";
			break;
		}	
	}
}

void vectorsMenu() {
	while (true) {
		std::cout << "Please enter '1' to create a vector, '2' to test vector related methods, or '3' to exit: \n";
		int choice;
		std::cin >> choice;
		switch (choice) {
			case 1:
				createVector();
				break;
			case 2:
				testVectors();
				break;
			default:
				break;
		}
		if (choice == 3) {
			break;
		}
	}
	
}


int main(int argc, char* argv[])
{
	int gl_major = 4, gl_minor = 3;
	int is_fullscreen = 0;
	int is_vsync = 1;
	 //GLFWwindow* win = setup(gl_major, gl_minor, 
		//640, 480, "OpenGL Viewer (GLFW)", is_fullscreen, is_vsync);
	 //run(win);
	// vectorsMenu();

	/* Challenge #1
	std::cout << "2.1 - " << Vector3D(1.5, 3.2, 0.8).rodriguesRot(Vector3D(8, 2, 0), 24).toString() << "\n";
	std::cout << "2.2 - " << Vector3D(0.5, 1.0, 1.0).rodriguesRot(Vector3D(8, 2, 0), 0).toString() << "\n";

	Vector3D v38(1.0, 2.0, 3.0);
	Vector3D v39(0.1, 0.2, 0.3);
	Vector3D v40(0.1, 0.2, 0.3);
	Vector3D v41(1.0, 2.0, 3.0);
	Vector3D v42(1.1, 2.2, 3.3);
	Vector3D v43(0.1, 0.2, 0.3);
	Vector3D v45 = v39 * 10;	
	Vector3D v46(-0.9, -1.79, -2.7);
	std::cout << "3.1 - " << (v38 == v45) << "\n";
	std::cout << "3.2 - " << ((v40 + v41) == v42) << "\n";
	std::cout << "3.1 - " << ((v43 - v41) != v46) << "\n";
*/



	std::cout << "=====================MATRIX 3x3=====================\n";

	std::cout << "=======CONSTRUCTORS, SETTERS & GETTERS=======\n";

	Matrix3D mat1;
	std::cout << "Matrix 1: " << mat1 << "\n";

	Matrix3D mat2(new float[3][3]{ {1,2,3},{4,5,6},{7,8,9} });
	std::cout << "Matrix 2: " << mat2 << "\n";

	std::cout << "Matrix 2 [2][2]: " << mat2.get(2, 2) << "\n";

	mat2.set(2, 2, 10);
	std::cout << "Matrix 2 [2][2] after Set: " << mat2.get(2, 2) << "\n\n";

	Matrix3D mat3(1);
	std::cout << "Matrix 3: " << mat3 << "\n";

	std::cout << "\n=======MATRIX-MATRIX OPERATORS=======\n";
	std::cout << "Matrix 1: " << mat1 << "\n";
	std::cout << "Matrix 2: " << mat2 << "\n";
	std::cout << "Matrix3: " << mat3 << "\n";

	std::cout << "Matrix1 + Matrix2 = " << mat1 + mat2 << "\n";
	std::cout << "Matrix2 - Matrix1 = " << mat1 - mat2 << "\n";

	std::cout << "Matrix3 * Matrix2 = " << mat3 * mat2 << "\n";
	std::cout << "Matrix2 * Matrix3 = " << mat2 * mat3 << "\n";


	std::cout << "\n=======MATRIX-SCALAR OPERATORS=======\n";
	std::cout << "Matrix3: " << mat3 << "\n";

	std::cout << "Matrix3 * 2 = " << mat3 * 2 << "\n";
	std::cout << "1/2.0f * Matrix3 = " << 1 / 2.0f * mat3 << "\n";

	std::cout << "Matrix3 / 4 = " << mat3 / 4 << "\n";
	std::cout << "4.0f / Matrix3 = " << 4.0f / mat3 << "\n";

	std::cout << "\n=======MATRIX-VECTOR OPERATORS=======\n";
	std::cout << "Matrix3: " << mat3;

	Vector3D vec1(1, 2, 3);
	std::cout << "Vector1: " << vec1.toString() << "\n";

	std::cout << "Matrix3 * Vector1 = " << (mat3 * vec1).toString() << "\n";
	std::cout << "Vector1 * Matrix3 = " << (vec1 * mat3).toString() << "\n\n";

	std::cout << "Matrix2: " << mat2;
	std::cout << "Vector1: " << vec1.toString() << "\n";

	std::cout << "Matrix2 * Vector1 = " << (mat2 * vec1).toString() << "\n";
	std::cout << "Vector1 * Matrix2 = " << (vec1 * mat2).toString() << "\n";

	std::cout << "\n=======ASSIGNMENTS=======\n";
	std::cout << "Matrix3: " << mat3;

	vec1.setX(1);
	vec1.setY(2);
	vec1.setZ(3);
	std::cout << "Vector1: " << vec1.toString() << "\n";

	Matrix3D mat4;
	std::cout << "Matrix4: " << mat4;

	mat4 = mat3;
	std::cout << "Matrix4 = Matrix3: " << mat4;

	mat4 += mat3;
	std::cout << "Matrix4 += Matrix3: " << mat4;

	mat4 -= mat3;
	std::cout << "Matrix4 -= Matrix3: " << mat4;

	mat4 += 1;
	std::cout << "Matrix4 += 1: " << mat4;

	mat4 -= 1;
	std::cout << "Matrix4 -= 1: " << mat4;

	mat4 = 1;
	std::cout << "Matrix4 = 1: " << mat4;

	mat4 *= mat3;
	std::cout << "Matrix4 *= Matrix3: " << mat4;

	mat4 *= 2;
	std::cout << "Matrix4 *= 2: " << mat4;

	mat4 /= 2;
	std::cout << "Matrix4 /= 2: " << mat4;

	vec1 *= mat4;
	std::cout << "Vector1 /= Matrix4: " << vec1.toString();

	std::cout << "\n=======COMPARISSONS=======\n";
	std::cout << "Matrix1: " << mat1;
	std::cout << "Matrix2: " << mat2;

	mat3 = mat2;
	std::cout << "Matrix3: " << mat3;

	std::cout << "Matrix1 == Matrix2 : " << (mat1 == mat2) << "\n";
	std::cout << "Matrix1 != Matrix2 : " << (mat1 != mat2) << "\n";

	std::cout << "Matrix3 == Matrix2 : " << (mat3 == mat2) << "\n";
	std::cout << "Matrix2 != Matrix3 : " << (mat2 != mat3) << "\n";

	std::cout << "\n=======MATRIX METHODS=======\n";
	std::cout << "Matrix1: " << mat1;
	mat2 = Matrix3D(new float[3][3]{ {1,2,3},{0,1,4},{5,6,0} });
	std::cout << "Matrix2: " << mat2 << "\n";

	std::cout << "Transposed Matrix1: " << mat1.transposed();
	std::cout << "Transposed Matrix2: " << mat2.transposed();

	std::cout << "Col Major Matrix2: " << mat2.convertMajorOrder();
	std::cout << "Row Major Matrix2: " << mat2.convertMajorOrder();

	std::cout << "Determinant Matrix1: " << mat1.determinant() << "\n";
	std::cout << "Determinant Matrix2: " << mat2.determinant() << "\n";

	std::cout << "Adjoint Matrix1: " << mat1.adjoint() << "\n";
	std::cout << "Adjoint Matrix2: " << mat2.adjoint() << "\n";

	std::cout << "Inverse Matrix2: " << mat2.inverse() << "\n";

	std::cout << "Identity Matrix: " << Matrix3D::identity();

	vec1.setX(1);
	vec1.setY(2);
	vec1.setZ(3);
	std::cout << "Dual Matrix (Vector (1,2,3)): " << Matrix3D::dual(vec1);



	std::cout << "\n=======CONVERSIONS=======\n";

	std::cout << "=====================MATRIX 3x3=====================\n\n\n";

	std::cout << "=====================MATRIX 2x2=====================\n";

	std::cout << "=======CONSTRUCTORS, SETTERS & GETTERS=======\n";

	Matrix2D mat8;
	std::cout << "Matrix 8: " << mat8 << "\n";

	Matrix2D mat5(new float[2][2]{ {1,2},{3,4} });
	std::cout << "Matrix 5: " << mat5 << "\n";

	std::cout << "Matrix 5 [1][1]: " << mat5.get(1, 1) << "\n";

	mat5.set(1, 1, 10);
	std::cout << "Matrix 5 [1][1] after Set: " << mat5.get(1, 1) << "\n\n";

	Matrix2D mat6(1);
	std::cout << "Matrix 6: " << mat6 << "\n";

	std::cout << "\n=======MATRIX-MATRIX OPERATORS=======\n";
	std::cout << "Matrix 8: " << mat8 << "\n";
	std::cout << "Matrix 5: " << mat5 << "\n";
	std::cout << "Matrix 6: " << mat6 << "\n";

	std::cout << "Matrix 8 + Matrix 5 = " << mat8 + mat5 << "\n";
	std::cout << "Matrix 5 - Matrix 8 = " << mat5 - mat8 << "\n";

	std::cout << "Matrix 6 * Matrix 5 = " << mat6 * mat5 << "\n";
	std::cout << "Matrix 5 * Matrix 6 = " << mat5 * mat6 << "\n";


	std::cout << "\n=======MATRIX-SCALAR OPERATORS=======\n";
	std::cout << "Matrix 6: " << mat6 << "\n";

	std::cout << "Matrix 6 * 2 = " << mat6 * 2 << "\n";
	std::cout << "1/2.0f * Matrix 6 = " << 1 / 2.0f * mat6 << "\n";

	std::cout << "Matrix 6 / 4 = " << mat6 / 4 << "\n";
	std::cout << "4.0f / Matrix 6 = " << 4.0f / mat6 << "\n";

	std::cout << "\n=======MATRIX-VECTOR OPERATORS=======\n";
	std::cout << "Matrix 6: " << mat6;

	Vector2D vec2(1, 2);
	std::cout << "Vector1: " << vec1.toString() << "\n";

	std::cout << "Matrix 6 * Vector 2 = " << (mat6 * vec2).toString() << "\n";
	std::cout << "Vector 2 * Matrix 6 = " << (vec2 * mat6).toString() << "\n\n";

	std::cout << "Matrix 5: " << mat5;
	std::cout << "Vector 2: " << vec2.toString() << "\n";

	std::cout << "Matrix 5 * Vector 2 = " << (mat5 * vec2).toString() << "\n";
	std::cout << "Vector 2 * Matrix 5 = " << (vec2 * mat5).toString() << "\n";

	std::cout << "\n=======ASSIGNMENTS=======\n";
	std::cout << "Matrix 6: " << mat6;

	vec2.setX(1);
	vec2.setY(2);
	std::cout << "Vector 2: " << vec2.toString() << "\n";

	Matrix2D mat7;
	std::cout << "Matrix 7: " << mat7;

	mat7 = mat6;
	std::cout << "Matrix 7 = Matrix 6: " << mat7;

	mat7 += mat6;
	std::cout << "Matrix 7 += Matrix 6: " << mat7;

	mat7 -= mat6;
	std::cout << "Matrix 7 -= Matrix 6: " << mat7;

	mat7 += 1;
	std::cout << "Matrix 7 += 1: " << mat7;

	mat7 -= 1;
	std::cout << "Matrix 7 -= 1: " << mat7;

	mat7 = 1;
	std::cout << "Matrix 7 = 1: " << mat7;

	mat7 *= mat6;
	std::cout << "Matrix 7 *= Matrix 6: " << mat7;

	mat7 *= 2;
	std::cout << "Matrix 7 *= 2: " << mat7;

	mat7 /= 2;
	std::cout << "Matrix 7 /= 2: " << mat7;

	vec2 *= mat7;
	std::cout << "Vector 2 /= Matrix 7: " << vec2.toString();

	std::cout << "\n=======COMPARISSONS=======\n";
	std::cout << "Matrix 8: " << mat8;
	std::cout << "Matrix 5: " << mat5;

	mat6 = mat5;
	std::cout << "Matrix 6: " << mat6;

	std::cout << "Matrix 8 == Matrix 5 : " << (mat8 == mat5) << "\n";
	std::cout << "Matrix 8 != Matrix 5 : " << (mat8 != mat5) << "\n";

	std::cout << "Matrix 6 == Matrix 5 : " << (mat6 == mat5) << "\n";
	std::cout << "Matrix 5 != Matrix 6 : " << (mat5 != mat6) << "\n";

	std::cout << "\n=======MATRIX METHODS=======\n";
	std::cout << "Matrix 8: " << mat8;
	mat5 = Matrix2D(new float[2][2]{ {1,2},{0,1} });
	std::cout << "Matrix 5: " << mat5 << "\n";

	std::cout << "Transposed Matrix 8: " << mat8.transposed();
	std::cout << "Transposed Matrix 5: " << mat5.transposed();

	std::cout << "Col Major Matrix 5: " << mat5.convertMajorOrder();
	std::cout << "Row Major Matrix 5: " << mat5.convertMajorOrder();

	std::cout << "Determinant Matrix 8: " << mat8.determinant() << "\n";
	std::cout << "Determinant Matrix 5: " << mat5.determinant() << "\n";

	std::cout << "Adjoint Matrix 8: " << mat8.adjoint() << "\n";
	std::cout << "Adjoint Matrix 5: " << mat5.adjoint() << "\n";

	std::cout << "Inverse Matrix 5: " << mat5.inverse() << "\n";

	std::cout << "Identity Matrix: " << Matrix2D::identity();

	std::cout << "\n=======CONVERSIONS=======\n";

	std::cout << "=====================MATRIX 3x3=====================\n\n\n";






	exit(EXIT_SUCCESS);

}

/////////////////////////////////////////////////////////////////////////// END

