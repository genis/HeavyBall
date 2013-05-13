//Fragment Lighting Fragment Shader
 
varying vec3 Vobs;
varying vec3 N;

vec3 getAmbient() {
    return (gl_FrontMaterial.ambient * (gl_LightSource[0].ambient + 0.2)).rgb;
}

vec3 getDiffuse(vec3 L) {
    vec3 diffuse = (gl_FrontMaterial.diffuse * gl_LightSource[0].diffuse).rgb;
    return diffuse * max(dot(N, L), 0.0);
}

vec3 getSpecular(vec3 R, vec3 V) {
    vec3 specular = (gl_FrontMaterial.specular * gl_LightSource[0].specular).rgb;
    return specular * pow(max(dot(V, R), 0.0), gl_FrontMaterial.shininess);
}

void main() {

    vec3 V = normalize(-Vobs);
	
	if (dot(V,N) < 0.1) {
		gl_FragColor = vec4(0.0, 0.0, 0.0, 1.0);
	}
	else {
		vec3 L = normalize(gl_LightSource[0].position.xyz - Vobs);
		vec3 R = reflect(-L,N);
		gl_FragColor = (vec4(getAmbient() + getDiffuse(L), 1.0) * gl_Color);
	}
}