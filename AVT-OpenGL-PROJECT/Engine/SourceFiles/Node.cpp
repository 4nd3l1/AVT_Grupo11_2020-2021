#include "../HeaderFiles/Node.h"

Node::Node()
{
}

Node::Node(Node* f) {
	VaoID = -1;
	localTransform = Matrix4D::identity();
	father = f;
}

void Node::setup(GLfloat* view, GLfloat* proj, GLuint ProgramID) {
	this->view = view;
	this->proj = proj;
	this->ProgramID = ProgramID;
}

void Node::setColor(bool singleColor, Vector4D color) {
	this->singlecolor = singleColor;
	this->color = color;
}

void Node::draw() {
	glUseProgram(ProgramID);
	glBindVertexArray(VaoID);
	GLfloat model[16];
	localTransform.getColMajor(model);
	GLuint ModelMatrix_UId = glGetUniformLocation(ProgramID, "ModelMatrix");
	GLuint ViewMatrix_UId = glGetUniformLocation(ProgramID, "ViewMatrix");
	GLuint ProjectionMatrix_UId = glGetUniformLocation(ProgramID, "ProjectionMatrix");
	GLuint isSingleColor_UId = glGetUniformLocation(ProgramID, "isSingleColor");
	glUniformMatrix4fv(ModelMatrix_UId, 1, GL_FALSE, model);
	glUniformMatrix4fv(ViewMatrix_UId, 1, GL_FALSE, view);
	glUniformMatrix4fv(ProjectionMatrix_UId, 1, GL_FALSE, proj);
	if (singlecolor) {
		GLuint Color_UId = glGetUniformLocation(ProgramID, "ourColor");
		glUniform4f(Color_UId, color.getX(), color.getY(), color.getZ(), color.getW());
		glUniform1i(isSingleColor_UId, 1);
	}
	else {
		glUniform1i(isSingleColor_UId, 0);
	}
	glDrawArrays(GL_TRIANGLES, 0, (GLsizei)mesh.getVertices().size());
	resetLocalTransform();
	glUseProgram(0);
	glBindVertexArray(0);
}

std::list<Node> Node::getChilds()
{
	return childs;
}

void Node::applyTransform(Matrix4D transf)
{
	localTransform = transf * localTransform;
	worldTransform = localTransform * worldTransform;
	for(Node var: childs)
	{
		var.applyTransform(transf);
	}

}

void Node::applyParticularTrnasform(Matrix4D transf) {
	localTransform = transf * localTransform;
	worldTransform = localTransform * worldTransform;
}

void Node::resetLocalTransform() {
	localTransform = Matrix4D::identity();
}

Matrix4D Node::getLocalTransform()
{
	return localTransform;
}

void Node::addChild(Node child)
{
	childs.push_back(child);
}
