#include "Shader.h"
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>

Shader::Shader(void)
{
	programID = 0;
}

void Shader::readShaderSourceFile(const char* file, string& source)
{
    ifstream shaderFile(file);
    stringstream shaderData;
    shaderData << shaderFile.rdbuf();
    shaderFile.close();
    source = shaderData.str();
}

void Shader::printLog(void)
{
    int infologLength = 0;
    int maxLength;
	
	glGetProgramiv(programID, GL_INFO_LOG_LENGTH, &maxLength);
    
	char infoLog[1000];
    
    glGetProgramInfoLog(programID, maxLength, &infologLength, infoLog);
    
    if (infologLength > 0) printf("%s\n",infoLog);
}

Shader::Shader(const char* vertexFile, const char* geometryFile,  const char* fragmentFile) 
{
    programID = glCreateProgram();

    if (vertexFile != NULL) {
        string vertexSource;
        readShaderSourceFile(vertexFile, vertexSource);
        const GLchar *vertexShader[1] = {vertexSource.c_str()};
        
        GLuint vertexShaderID = glCreateShader(GL_VERTEX_SHADER);
        glShaderSource(vertexShaderID, 1, vertexShader, NULL);
        glCompileShader(vertexShaderID);
        glAttachShader(programID, vertexShaderID);

        program.push_back(vertexShaderID);
    }

    if (fragmentFile != NULL) {
        string fragmentSource;
        readShaderSourceFile(fragmentFile, fragmentSource);
        const GLchar *fragmentShader[1] = {fragmentSource.c_str()};

        GLuint fragmentShaderID = glCreateShader(GL_FRAGMENT_SHADER);
        glShaderSource(fragmentShaderID, 1, fragmentShader, NULL);
        glCompileShader(fragmentShaderID);

        glAttachShader(programID, fragmentShaderID);

        program.push_back(fragmentShaderID);
    }

    if (geometryFile != NULL) {
        string geometrySource;
        readShaderSourceFile(geometryFile, geometrySource);
        const GLchar *geometryShader[1] = {geometrySource.c_str()};
        
        GLuint geometryShaderID = glCreateShader(GL_GEOMETRY_SHADER);
        glShaderSource(geometryShaderID, 1, geometryShader, NULL);
        glCompileShader(geometryShaderID);
        
        glAttachShader(programID, geometryShaderID);

        program.push_back(geometryShaderID);
        
        glProgramParameteriEXT(programID, GL_GEOMETRY_INPUT_TYPE_EXT, GL_TRIANGLES);
        glProgramParameteriEXT(programID, GL_GEOMETRY_OUTPUT_TYPE_EXT, GL_TRIANGLE_STRIP);
        GLint n;
        glGetIntegerv(GL_MAX_GEOMETRY_OUTPUT_VERTICES_EXT, &n);
        glProgramParameteriEXT(programID, GL_GEOMETRY_VERTICES_OUT_EXT, n);

    }
    
    glLinkProgram(programID);
    //printLog(programID);
}

Shader::~Shader(void)
{
}

void Shader::enable(void)
{
	glUseProgram(programID);
}

void Shader::disable(void)
{
	glUseProgram(0);
}

void Shader::deleteShader(void)
{
	for (int i = 0; i < program.size(); ++i) glDeleteShader(program[i]);
	glDeleteProgram(programID);
}