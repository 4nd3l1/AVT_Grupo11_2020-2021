#shader vertex
#version 410 core

layout (location = 0)in vec4 position;
layout(location = 1)in vec3 aColor;
out vec3 ourColor;

void main() 
{
  gl_Position = position;
  ourColor = aColor;
};

#shader fragment
#version 410 core

in vec3 ourColor;
out vec4 colour;

void main() 
{
	colour = vec4(ourColor, 1.0f);
};