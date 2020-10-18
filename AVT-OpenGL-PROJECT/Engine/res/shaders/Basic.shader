#shader vertex
#version 410 core

layout (location = 0)in vec4 position;

void main() 
{
  gl_Position = position;
};

#shader fragment
#version 410 core

out vec4 colour;

uniform vec4 u_Color;

void main() 
{
  colour = u_Color;
};