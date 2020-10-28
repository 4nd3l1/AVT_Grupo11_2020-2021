#shader vertex
#version 410 core

layout (location = 0)in vec4 position;
layout(location = 1)in vec4 aColor;
out vec4 ourColor;

uniform mat4 Modal;
uniform mat4 View;
uniform mat4 Projection;


void main() 
{
  gl_Position = Projection * View * Modal * position;
  ourColor = aColor;
};

#shader fragment
#version 410 core

in vec4 ourColor;
out vec4 colour;

uniform int isBack;

void main() 
{
	if (isBack == 0) {
		colour = ourColor;
	}
	else {
		colour = ourColor * 0.5f;
	}
};