#include "ShaderManager.h"

typedef pair<string, Shader*> dataPair;
typedef map<string, Shader*>::iterator dataIter;
typedef map<string, Shader*>::const_iterator const_dataIter;

ShaderManager::ShaderManager(void)
{
}

ShaderManager::~ShaderManager(void)
{
	for (dataIter it = shaderData.begin(); it != shaderData.end(); ++it) {
		(it->second)->deleteShader();
		delete (it->second); 
	}
}

void ShaderManager::loadShader(const string& name, const char* vertexShader, 
							   const char* geometryShader, const char* fragmentShader) 
{
	Shader* s = new Shader(vertexShader, geometryShader, fragmentShader);
	shaderData[name] = s;
}


Shader* ShaderManager::getShader(const string& name) const
{
	const_dataIter it = shaderData.find(name);
	if (it == shaderData.end()) return NULL;

	return it->second; 
}
