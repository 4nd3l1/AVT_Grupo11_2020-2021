#pragma once
#include "Matrix4D.h"
#include "Camera.h"
#include <list>
#include "Mesh.h"
class Node
{
	private:
		GLfloat *view, *proj;
		GLuint ProgramID;
		bool singlecolor;
		Vector4D color;
		Node* father;

	public:
		Node();
		Node(Node* f);
		void setup(GLfloat* view, GLfloat* proj, GLuint ProgramID);
		void setColor(bool singleColor, Vector4D color = Vector4D());
		void draw();
		GLuint VaoID;
		Mesh mesh;
		Matrix4D localTransform;
		Matrix4D worldTransform;
		std::list<Node> childs;
		std::list<Node> getChilds();
		void applyTransform(Matrix4D transf);
		void applyParticularTrnasform(Matrix4D transf);
		void resetLocalTransform();
		Matrix4D getLocalTransform();
		void addChild(Node child);
};

