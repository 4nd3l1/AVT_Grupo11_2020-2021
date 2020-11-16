#include "../HeaderFiles/SceneManager.h"

void SceneManager::setup() {
	transforms[0] = Matrix4D::translation(0.0f, 0.0f, 0.0f);
	transforms[1] = Matrix4D::translation(0.8f, 0.0f, 0.0f);
	transforms[2] = Matrix4D::translation(1.6f, 0.0f, 0.0f);
	transforms[3] = Matrix4D::translation(2.4f, 0.0f, 0.0f);
	transforms[4] = Matrix4D::translation(2.4f, 0.8f, 0.0f);
	transforms[5] = Matrix4D::translation(2.4f, 1.6f, 0.0f);
	transforms[6] = Matrix4D::translation(2.4f, 2.4f, 0.0f);
	transforms[7] = Matrix4D::translation(2.4f, 2.4f, -0.8f);
	transforms[8] = Matrix4D::translation(2.4f, 2.4f, -1.6f);
}

void SceneManager::draw(GLuint penrose_vao, GLuint frame_vao, GLuint back_vao, GLfloat* view, GLfloat* proj, Obj_Loader obj_loader)
{
	GLfloat model[16];
	for (int i = 0; i < 9; i++)
	{
		(transforms[i] * Matrix4D::scaling(0.3f, 0.3f, 0.3f)).getColMajor(model);
		obj_loader.drawObj(1, penrose_vao, model, view, proj);
	}

	Matrix4D::identity().getColMajor(model);
	obj_loader.drawObj(2, frame_vao, model, view, proj, true, Vector4D(0.6f, 0.3f, 0.2f, 0.0f));

	Matrix4D::identity().getColMajor(model);
	obj_loader.drawObj(3, back_vao, model, view, proj, true, Vector4D(0.0f, 0.0f, 0.0f, 0.0f));
	
}

