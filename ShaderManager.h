#pragma once
#include <map>
#include <string>
#include "Shader.h"

class ShaderManager
{
public:
	ShaderManager(void);
	~ShaderManager(void);

	void loadShader(const string& name, const char* vertexShader, 
					const char* geometryShader, const char* fragmentShader);

	Shader* getShader(const string& name) const;

private:
	map<string, Shader*> shaderData;
};

