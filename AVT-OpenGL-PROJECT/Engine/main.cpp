
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "HeaderFiles/Matrix4D.h"
#include "HeaderFiles/Camera.h"
#include "HeaderFiles/Mesh.h"
#include "HeaderFiles/Node.h"

int window_width;
int window_height;
float cursorX, cursorY;
float xOffset, yOffset;

Node n1, n2, n3;
GLuint Vao_ID1, Vao_ID2, Vao_ID3;
Mesh m1, m2, m3;

Camera camera(Vector3D(3.5f, 3.0f, 50.0f), Vector3D(3.5f, 3.0f, 0.0f), Vector3D(0.0f, 1.0f, 0.0f));
float view[16];
float proj[16];
bool ortho = true;
bool projChanged;

Vector3D pos[9];

bool animation = false;
bool animation_frame = false;

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
bool automaticRotating = false;


#define VERTICES 0
#define TEXCOORDS 1
#define NORMALS 2
bool TexcoordsLoaded, NormalsLoaded;

GLuint ProgramId;
GLint ModelMatrix_UId, ViewMatrix_UId, ProjectionMatrix_UId, isSingleColor_UId, Color_UId;

const std::string read(const std::string& filename)
{
	std::ifstream ifile(filename);
	std::string shader_string, line;
	while (std::getline(ifile, line))
	{
		shader_string += line + "\n";
	}
	return shader_string;
}

const GLuint checkCompilation(const GLuint shader_id, const std::string& filename)
{
	GLint compiled;
	glGetShaderiv(shader_id, GL_COMPILE_STATUS, &compiled);
	if (compiled == GL_FALSE)
	{
		GLint length;
		glGetShaderiv(shader_id, GL_INFO_LOG_LENGTH, &length);
		GLchar* const log = new char[length];
		glGetShaderInfoLog(shader_id, length, &length, log);
		std::cerr << "[" << filename << "] " << std::endl << log;
		delete[] log;
		exit(EXIT_FAILURE);
	}
	return compiled;
}

void checkLinkage(const GLuint program_id) {
	GLint linked;
	glGetProgramiv(program_id, GL_LINK_STATUS, &linked);
	if (linked == GL_FALSE)
	{
		GLint length;
		glGetProgramiv(program_id, GL_INFO_LOG_LENGTH, &length);
		GLchar* const log = new char[length];
		glGetProgramInfoLog(program_id, length, &length, log);
		std::cerr << "[LINK] " << std::endl << log << std::endl;
		delete[] log;
		exit(EXIT_FAILURE);
	}
}

const GLuint addShader(const GLuint program_id, const GLenum shader_type, const std::string& filename)
{
	const GLuint shader_id = glCreateShader(shader_type);
	const std::string scode = read(filename);
	const GLchar* code = scode.c_str();
	glShaderSource(shader_id, 1, &code, 0);
	glCompileShader(shader_id);
	checkCompilation(shader_id, filename);
	glAttachShader(program_id, shader_id);
	return shader_id;
}

void createShaderProgram(std::string& vs_file, std::string& fs_file)
{
	ProgramId = glCreateProgram();

	GLuint VertexShaderId = addShader(ProgramId, GL_VERTEX_SHADER, vs_file);
	GLuint FragmentShaderId = addShader(ProgramId, GL_FRAGMENT_SHADER, fs_file);

	glBindAttribLocation(ProgramId, VERTICES, "inPosition");
	if (TexcoordsLoaded)
		glBindAttribLocation(ProgramId, TEXCOORDS, "inTexcoord");
	if (NormalsLoaded)
		glBindAttribLocation(ProgramId, NORMALS, "inNormal");

	glLinkProgram(ProgramId);
	checkLinkage(ProgramId);

	glDetachShader(ProgramId, VertexShaderId);
	glDetachShader(ProgramId, FragmentShaderId);
	glDeleteShader(VertexShaderId);
	glDeleteShader(FragmentShaderId);

	ModelMatrix_UId = glGetUniformLocation(ProgramId, "ModelMatrix");
	ViewMatrix_UId = glGetUniformLocation(ProgramId, "ViewMatrix");
	ProjectionMatrix_UId = glGetUniformLocation(ProgramId, "ProjectionMatrix");
	isSingleColor_UId = glGetUniformLocation(ProgramId, "isSingleColor");
	Color_UId = glGetUniformLocation(ProgramId, "ourColor");
}

void destroyShaderProgram()
{
	glUseProgram(0);
	glDeleteProgram(ProgramId);
}

/////////////////////////////////////////////////////////////////////// SHADERs


void createBufferObjects(GLuint &VaoId, Node n)
{
	GLuint VboVertices, VboTexcoords, VboNormals;

	glGenVertexArrays(1, &VaoId);
	glBindVertexArray(VaoId);
	{
		glGenBuffers(1, &VboVertices);
		glBindBuffer(GL_ARRAY_BUFFER, VboVertices);
		glBufferData(GL_ARRAY_BUFFER, n.mesh.getVertices().size() * sizeof(Vertex), &n.mesh.getVertices()[0], GL_STATIC_DRAW);
		glEnableVertexAttribArray(VERTICES);
		glVertexAttribPointer(VERTICES, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), 0);

		if (n.mesh.getTexcoordsLoaded())
		{
			glGenBuffers(1, &VboTexcoords);
			glBindBuffer(GL_ARRAY_BUFFER, VboTexcoords);
			glBufferData(GL_ARRAY_BUFFER, n.mesh.getTexCoords().size() * sizeof(Texcoord), &n.mesh.getTexCoords()[0], GL_STATIC_DRAW);
			glEnableVertexAttribArray(TEXCOORDS);
			glVertexAttribPointer(TEXCOORDS, 2, GL_FLOAT, GL_FALSE, sizeof(Texcoord), 0);
		}
		if (n.mesh.getNormalsLoaded())
		{
			glGenBuffers(1, &VboNormals);
			glBindBuffer(GL_ARRAY_BUFFER, VboNormals);
			glBufferData(GL_ARRAY_BUFFER, n.mesh.getNormals().size() * sizeof(Normal), &n.mesh.getNormals()[0], GL_STATIC_DRAW);
			glEnableVertexAttribArray(NORMALS);
			glVertexAttribPointer(NORMALS, 3, GL_FLOAT, GL_FALSE, sizeof(Normal), 0);
		}
	}
	glBindVertexArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glDeleteBuffers(1, &VboVertices);
	glDeleteBuffers(1, &VboTexcoords);
	glDeleteBuffers(1, &VboNormals);
}

void destroyBufferObjects()
{
	glBindVertexArray(Vao_ID1);
	glDisableVertexAttribArray(VERTICES);
	glDisableVertexAttribArray(TEXCOORDS);
	glDisableVertexAttribArray(NORMALS);
	glDeleteVertexArrays(1, &Vao_ID1);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);

	glBindVertexArray(Vao_ID2);
	glDisableVertexAttribArray(VERTICES);
	glDisableVertexAttribArray(TEXCOORDS);
	glDisableVertexAttribArray(NORMALS);
	glDeleteVertexArrays(1, &Vao_ID2);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);
}

void drawScene()
{
	n1.setup(view, proj, ProgramId);
	n2.setup(view, proj, ProgramId);
	n3.setup(view, proj, ProgramId);

	n1.setColor(false);
	n2.setColor(true, Vector4D(0.6f, 0.2f, 0.0f, 0.0f));
	n3.setColor(true, Vector4D(0.0f, 0.0f, 0.0f, 0.0f));

	float animationSpeed = 0.02f;
	for (int i = 0; i < 9; i++) {

		if (animation) {
			if (pos[i].getX() < 9) {
				pos[i].setX(pos[i].getX() + animationSpeed);
			}
			else if (pos[i].getZ() < 9) {
				pos[i].setZ(pos[i].getZ() + animationSpeed);
			}
			else if (pos[i].getY() < 9) {
				pos[i].setY(pos[i].getY() + animationSpeed);
			}
			else {
				pos[i].setX(0);
				pos[i].setY(0);
				pos[i].setZ(0);
			}
		}
		
		Vector3D v = pos[i];
		n1.applyParticularTrnasform(Matrix4D::translation(v.getX(), v.getY(), v.getZ()));
		n1.applyParticularTrnasform(Matrix4D::rotationY(-45.0f, false));
		n1.applyParticularTrnasform(Matrix4D::rotationX(35.2f, false));
		n1.applyParticularTrnasform(Matrix4D::rotationZ(90.2f, false));
		n1.draw();
	}

	n2.applyParticularTrnasform(Matrix4D::scaling(4.0f, 4.0f, 4.0f));
	n2.applyParticularTrnasform(Matrix4D::translation(3.5f, 3.0f, 0.0f));
	//n2.applyTransform(Matrix4D::rotationY(90, false));
	n2.draw();

	n3.applyParticularTrnasform(Matrix4D::scaling(4.0f, 4.0f, 4.0f));
	n3.applyParticularTrnasform(Matrix4D::rotationX(180, false));
	n3.applyParticularTrnasform(Matrix4D::translation(3.5f, 3.0f, -4.0f));
	n3.draw();



}

void move_camera() {

	if (forwardKeyPressed) {
		camera.moveCameraForward(0.05f);
	}
	if (backwardKeyPressed) {
		camera.moveCameraBackward(0.05f);
	}

	if (leftKeyPressed) {
		camera.moveCameraLeft(0.05f);
	}
	if (rightKeyPressed) {
		camera.moveCameraRight(0.05f);
	}

	// ROTATE CAMERA //

	if (!stopRotating) {
		if (!quaternionRotation) {
			if (automaticRotating) {
				camera.rotateCameraAround(1, { 0.0f, 1.0f, 0.0f, 1.0f });
			}
			else

				if (mouseMoved) {
					camera.rotateCameraAround(xOffset, { 0.0f, 1.0f, 0.0f, 1.0f });
					camera.rotateCameraAround(yOffset, { 1.0f, 0.0f, 0.0f, 1.0f });
					mouseMoved = false;
				}
		}
		else {
			if (automaticRotating) {
				camera.rotateCameraAroundQuaternion(1, { 0.0f, 1.0f, 0.0f, 1.0f });
			}
			else
				if (mouseMoved) {
					camera.rotateCameraAroundQuaternion(xOffset, { 0.0f, 1.0f, 0.0f, 1.0f });
					camera.rotateCameraAroundQuaternion(yOffset, { 1.0f, 0.0f, 0.0f, 1.0f });
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
	viewM.getColMajor(view);

	Matrix4D projM;
	if (ortho) {
		projM = camera.getOrthProj();
	}
	else {
		projM = camera.getPerspProj();
	}
	projM.getColMajor(proj);
}

void setupCamera() {
	// CAMERA SETUP //
	camera.setOrthoProjectionMatrix(-10.0f, 10.0f, -10.0f, 10.0f, 1.0f, 100.0f);
	camera.setPrespProjectionMatrix(30, ((GLfloat)window_width / (GLfloat)window_height), 1.0f, 100.0f);
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
		case GLFW_KEY_C:
			animation = !animation;
			break;
		case GLFW_KEY_F:
			animation_frame = !animation_frame;
			break;
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

///////////////////////////////////////////////////////////////////// CALLBACKS

void window_close_callback(GLFWwindow* win)
{
	destroyShaderProgram();
	destroyBufferObjects();
}

void window_size_callback(GLFWwindow* win, int winx, int winy)
{
	window_width = winx;
	window_height = winy;
	glViewport(0, 0, winx, winy);
	// Change projection matrices to maintain aspect ratio
}

///////////////////////////////////////////////////////////////////////// SETUP

void glfw_error_callback(int error, const char* description)
{
	std::cerr << "GLFW Error: " << description << std::endl;
}

GLFWwindow* setupWindow(int winx, int winy, const char* title,
	int is_fullscreen, int is_vsync)
{
	window_width = winx;
	window_height = winy;
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
	glClearColor(0.8f, 0.8f, 0.8f, 1.0f);
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

	setupCallbacks(win);

	setupCamera();
	
	m1.CreateMesh("Engine/assets/models/cube.obj");
	n1.mesh = m1;
	createBufferObjects(n1.VaoID, n1);
	m2.CreateMesh("Engine/assets/models/frame.obj");
	n2.mesh = m2;
	createBufferObjects(n2.VaoID, n2);
	m3.CreateMesh("Engine/assets/models/back.obj");
	n3.mesh = m3;
	createBufferObjects(n3.VaoID, n3);
	n2.addChild(n1);
	n2.addChild(n3);

	std::string vs = "Engine/res/shaders/cube_vs.glsl";
	std::string fs = "Engine/res/shaders/cube_fs.glsl";


	createShaderProgram(vs, fs);
	return win;
}

////////////////////////////////////////////////////////////////////////// RUN

void display(GLFWwindow* win, double elapsed_sec)
{
	drawScene();
}

void run(GLFWwindow* win)
{
	double last_time = glfwGetTime();
	while (!glfwWindowShouldClose(win))
	{
		double time = glfwGetTime();
		double elapsed_time = time - last_time;
		last_time = time;

		move_camera();

		set_view_proj();

		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		display(win, elapsed_time);

		glfwSwapBuffers(win);
		glfwPollEvents();
	}
	glfwDestroyWindow(win);
	glfwTerminate();
}

////////////////////////////////////////////////////////////////////////// MAIN

int main(int argc, char* argv[])
{
	int gl_major = 4, gl_minor = 3;
	int is_fullscreen = 0;
	int is_vsync = 1;
	GLFWwindow* win = setup(gl_major, gl_minor,
		1000, 1000, "Loading World", is_fullscreen, is_vsync);
	glEnable(GL_CULL_FACE);
	glFrontFace(GL_CCW);

	if (lockMouse) {
		glfwSetInputMode(win, GLFW_CURSOR, GLFW_CURSOR_DISABLED); //Tell GLFW that it should hide the cursorand capture it.Capturing a cursor means that, once the application has focus, the mouse cursor stays within the center of the window(unless the application loses focus or quits)
	}
	else {
		glfwSetInputMode(win, GLFW_CURSOR, GLFW_CURSOR_NORMAL);
	}

	pos[0] = Vector3D(3, 0, 0);
	pos[1] = Vector3D(6, 0, 0);
	pos[2] = Vector3D(9, 0, 0);
	pos[3] = Vector3D(9, 0, 3);
	pos[4] = Vector3D(9, 0, 6);
	pos[5] = Vector3D(9, 0, 9);
	pos[6] = Vector3D(9, 3, 9);
	pos[7] = Vector3D(9, 6, 9);
	pos[8] = Vector3D(9, 9, 9);


	run(win);
	exit(EXIT_SUCCESS);
	
}

///////////////////////////////////////////////////////////////////////////////
