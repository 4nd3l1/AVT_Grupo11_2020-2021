#pragma once

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

#include "Camera.h"

#define VERTICES 0
#define TEXCOORDS 1
#define NORMALS 2


class Obj_Loader
{

	public:
		Obj_Loader();

		void setup(std::string mesh_dir, std::string vs, std::string fs, GLuint& VaoId);

		void drawObj(int object, GLuint vao, GLfloat* model, GLfloat* view, GLfloat* proj, bool singleColor = false, Vector4D color = Vector4D());

		void destroyBufferObjects();

		void destroyShaderProgram();


	private:

		bool TexcoordsLoaded, NormalsLoaded;
		GLuint VaoId, ProgramId;
		GLint ModelMatrix_UId, ViewMatrix_UId, ProjectionMatrix_UId, Color_UId, isSingleColor_UId;

		const std::string read(const std::string& filename);

		const GLuint checkCompilation(const GLuint shader_id, const std::string& filename);

		void checkLinkage(const GLuint program_id);

		const GLuint addShader(const GLuint program_id, const GLenum shader_type, const std::string& filename);

		void createShaderProgram(std::string& vs_file, std::string& fs_file);

		void parseVertex(std::stringstream& sin);

		void parseTexcoord(std::stringstream& sin);

		void parseNormal(std::stringstream& sin);

		void parseFace(std::stringstream& sin);

		void parseLine(std::stringstream& sin);

		void loadMeshData(std::string& filename);

		void processMeshData();

		void freeMeshData();

		const void createMesh(std::string& filename);

		void createBufferObjects(GLuint& VaoId);

		
};

