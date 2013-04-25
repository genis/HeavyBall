#pragma once
#include <vector>
#include "Globals.h"

using namespace std;
class Shader
{
private:
	vector<GLuint> program; 
	GLuint programID; 

	void readShaderSourceFile(const char*, string& source);
public:
	Shader(void);
	Shader(const char* vertexShader, const char* geometryShader, const char* fragmentShader);
	~Shader(void);
	
	void printLog(void); 

	void enable(void);
	void disable(void);

	void deleteShader(void);

};