//Fragment Lighting Vertex Shader
varying vec3 Vobs;
varying vec3 N;

void main() {
    gl_Position = gl_ModelViewProjectionMatrix * gl_Vertex;
    N = gl_NormalMatrix * gl_Normal;
    Vobs = (gl_ModelViewMatrix * gl_Vertex).xyz;
	
	gl_FrontColor = gl_Color;
}