#pragma once
#include "Vector3D.h"
#include "../HeaderFiles/Obj_Loader.h"

class SceneManager
{
	private:
		Matrix4D transforms[9];

	public:
		void setup();
		void draw(GLuint penrose_vao, GLuint frame_vao, GLuint back_vao, GLfloat* view, GLfloat* proj, Obj_Loader obj_loader);

};

