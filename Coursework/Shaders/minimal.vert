// Vertex Shader – file "minimal.vert"

#version 330 core

in  vec3 in_Position;
in  vec3 in_Color;
out vec3 ex_Color;

void main(void)
{
	ex_Color = in_Color;
	gl_Position = vec4(in_Position, 1.0);
}