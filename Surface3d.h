#pragma once
#include <gl/glew.h>
#include <gl/glut.h>
#include <vector>
#include "Surface.h"
#include "Vector.h"
#include "Shader.h"

class Surface3d
{
private:
	struct propierties {
		Vector grad;
		Vector normal;
		float height;
		float mu;
	};

	typedef vector<vector<propierties> > Matrix;

	Matrix surface;

	GLuint verticesId;
	GLuint normalsId;
	GLuint indicesId;

	GLuint indicesCount;

	void getSmoothNormals(Surface& S, vector<Vector>& smoothNormals);

	void setNormals(Surface& S);
	void setGradient(Surface& S);

	void generateMesh(Surface& S);

public:
	Surface3d(void);
	~Surface3d(void);

	void generate(int width, int depth, float amplitude, int frequency, unsigned int seed);
	void draw(void);

	void deleteBuffers(void);
};

