// phong.vert
// Vertex shader for use with a Phong or other reflection model fragment shader
// Calculates and passes on V, L, N vectors for use in fragment shader, phong2.frag
#version 130

uniform mat4 modelview;
uniform mat4 projection;
uniform vec4 lightPosition;

in  vec3 in_Position;
in  vec3 in_Normal;
out vec3 ex_N;
out vec3 ex_V;
out vec3 ex_L;

// multiply each vertex position by the MVP matrix
// and find V, L, N vectors for the fragment shader
void main(void) {
	// vertex into eye coordinates
	vec4 vertexPosition = modelview * vec4(in_Position,1.0);

	// Find V - in eye coordinates, eye is at (0,0,0)
	ex_V = normalize(-vertexPosition).xyz;

	// surface normal in eye coordinates
	// taking the rotation part of the modelview matrix to generate the normal matrix
	// (if scaling is includes, should use transpose inverse modelview matrix!)
	// this is somewhat wasteful in compute time and should really be part of the cpu program,
	// giving an additional uniform input
	//mat3 normalmatrix = transpose(inverse(mat3(modelview)));
	mat3 normalmatrix = mat3(modelview);
	ex_N = normalize(normalmatrix * in_Normal);

	// L - to light source from vertex
	ex_L = normalize(lightPosition.xyz - vertexPosition.xyz);

    gl_Position = projection * vertexPosition;
}