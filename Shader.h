#pragma once
class Shader
{
public:
	Shader(void);
	Shader(char* vertexShader, char* geomatryShader, char* fragmentShader);
	~Shader(void);
	
	void enable(void);
	void disable(void);

	void deleteShader(void);
};

