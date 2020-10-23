#shader vertex
#version 410 core

layout (location = 0)in vec4 position;
layout(location = 1)in vec4 aColor;
out vec4 ourColor;

uniform mat4 Matrix;

void main() 
{
  gl_Position = position * Matrix;
  ourColor = aColor;
};

#shader fragment
#version 410 core

in vec4 ourColor;
out vec4 colour;

void main() 
{
	colour = ourColor;
};