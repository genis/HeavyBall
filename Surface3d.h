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
		Vector normal;
		float d;
		float mu;
	};

	typedef vector<vector<propierties> > Matrix;

	Matrix surface;

	GLuint verticesId;
	GLuint normalsId;
	GLuint indicesId;

	GLuint indicesCount;

	void getSmoothNormals(vector<Vector>& smoothNormals);

	void setGeometricPropierties(const Surface& S);

	void generateMesh(const Surface& S);

public:
	Surface3d(void);
	~Surface3d(void);

	Vector getGradient(float x, float y);
	Vector getNormal(float x, float y);
	float getHeight(float x, float y);
	float getMu(float x, float y);

	void generate(int width, int depth, float amplitude, int frequency, unsigned int seed);
	void draw(void);

	void deleteBuffers(void);
};

