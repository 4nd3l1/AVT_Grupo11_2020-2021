#pragma once
#include <string>
#include <GL/glew.h>
#include <unordered_map>

struct ShaderProgramSource
{
	std::string VertexSource;
	std::string FragmentSource;
};

class Shader
{
private:
	std::string m_path;
	GLuint m_RendererID;
	std::unordered_map<std::string, int> m_UniformLocationCache;

public:
	Shader(const std::string& path);
	~Shader();

	void Bind() const;
	void UnBind() const;

	// Set uniforms
	void SetUniform4f(const std::string& name, float v0, float v1, float v2, float v3);

	void SetUniform4fv(const std::string& name, float matrix[]);

	void SetUniform1i(const std::string& name, int value);

private:
	ShaderProgramSource ParseShader(const std::string& path);
	GLuint CreateShader(const std::string& vertexShader, const std::string& fragmentShader);
	GLuint CompileShader(GLuint type, const std::string& source);
	int GetUniformLocation(const std::string& name);

};

