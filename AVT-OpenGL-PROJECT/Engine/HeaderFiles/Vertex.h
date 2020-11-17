#pragma once

#include "Vector4D.h"
#include <GL/glew.h>
#include <GLFW/glfw3.h>

typedef struct
{
	Vector4D positions;
	float colour[4];
} VertexColour;

typedef struct {
	GLfloat x, y, z;
} Vertex;

typedef struct {
	GLfloat u, v;
} Texcoord;

typedef struct {
	GLfloat nx, ny, nz;
} Normal;