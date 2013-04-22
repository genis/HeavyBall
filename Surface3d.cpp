#include "Surface3d.h"
#include "Point.h"


Surface3d::Surface3d(void)
{
}

Surface3d::~Surface3d(void)
{
}

void Surface3d::getSmoothNormals(Surface& S, vector<Vector>& smoothNormals) 
{
	int n = S.getHeight();
	int m = S.getWidth();

	for (int i = 0; i < n-1; ++i) {
		for (int j = 0; j < m-1; ++j) {
			smoothNormals[i*m + j] += surface[i][j].normal; 
		}
		//add the current row last vertex normal
		smoothNormals[i*m + m-1] += surface[i][m-1].normal;
	}
	//add last row
	for (int i = 0; i < m-1; ++i) smoothNormals[(n-1)*m + i] += surface[n-1][i].normal;
	//add last row last vertex normal
	smoothNormals[n-1*m + m-1] += surface[n-1][m-1].normal;

	for (int i = 0; i < smoothNormals.size(); ++i) smoothNormals[i].normalize();
}

void Surface3d::setNormals(Surface& S)
{
	int n = S.getHeight();
	int m = S.getWidth();

	for (int i = 0; i < n-1; ++i) {
		for (int j = 0; j < m-1; ++j) {
			Point p1(j, S.getZ(j, i), i);
			Point p2(j+1, S.getZ(j+1, i), i);
			Point p3(j, S.getZ(j, i+1), i+1);

			Vector v1 = p2 - p1;
			Vector v2 = p3 - p1;

			//normals should face up
			Vector n = v2.crossProd(v1);
			n.normalize();

			surface[i][j].normal = n;
		}
	}
}

void Surface3d::setGradient(Surface& S)
{
	int n = S.getHeight();
	int m = S.getWidth();

	for (int i = 0; i < n-1; ++i) {
		for (int j = 0; j < m-1; ++j) {
		//TODO
		}
	}
}

void Surface3d::generateMesh(Surface& S)
{
	int n = S.getHeight();
	int m = S.getWidth();

	//set up vertices and normals
	vector<Vector> smoothNormals;
	getSmoothNormals(S, smoothNormals);

	GLfloat* vertices = new GLfloat[n*m];
	GLfloat* normals = new GLfloat[n*m];

	unsigned int verticesStride = 0;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			vertices[verticesStride + 0] = GLfloat(j);
			vertices[verticesStride + 1] = GLfloat(i);
			vertices[verticesStride + 2] = GLfloat(S.getZ(j, i));

			normals[verticesStride + 0] = smoothNormals[i*m + j].x; 
			normals[verticesStride + 1] = smoothNormals[i*m + j].y;
			normals[verticesStride + 2] = smoothNormals[i*m + j].z;

			verticesStride += 3;
		}
	}

	glGenBuffers(1, &verticesId);
    glBindBuffer(GL_ARRAY_BUFFER, verticesId);
    glBufferData(GL_ARRAY_BUFFER, sizeof(GLfloat)*verticesStride, vertices, GL_STATIC_DRAW);

	glGenBuffers(1, &normalsId);
    glBindBuffer(GL_ARRAY_BUFFER, normalsId);
    glBufferData(GL_ARRAY_BUFFER, sizeof(GLfloat)*verticesStride, normals, GL_STATIC_DRAW);

	delete vertices;
	delete normals;
	
	//set up indices

	//a triangle strip generated by stitching
	GLuint* indices = new GLuint[n*m + (m-2)*2];

	unsigned int indicesStride = 0;

	for (int i = 0; i < n-2; ++i) {
		for (int j = 0; j < m; ++j) {
			indices[indicesStride++] = i*m + j;
			indices[indicesStride++] = (i+1)*m + j;
		}

		++i;
		for (int j = m-1; j >= 0; ++j) {
			indices[indicesStride++] = i*m + j;
			indices[indicesStride++] = (i+1)*m + j;
		}
	}

	glGenBuffers(1, &indicesId);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, indicesId);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(GLuint)*indicesStride, indices, GL_STATIC_DRAW);

	indicesCount = indicesStride;

	delete indices;
}

void Surface3d::generate(int width, int depth, float amplitude, int frequency, unsigned int seed) 
{
	surface = Matrix(depth, vector<propierties> (width));
	
	Surface S(depth+1, width+1);
	S.perlinNoise(amplitude, frequency, seed);

	setNormals(S);
	generateMesh(S);
}

void Surface3d::draw(void)
{
	glBindBuffer(GL_ARRAY_BUFFER, verticesId);
    glVertexPointer(3, GL_FLOAT, 0, (GLvoid*) 0);

    glBindBuffer(GL_ARRAY_BUFFER, normalsId);
    glNormalPointer(GL_FLOAT, 0, (GLvoid*) 0);

    glEnableClientState(GL_VERTEX_ARRAY);
    glEnableClientState(GL_NORMAL_ARRAY);
    
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, indicesId);
    glDrawElements(GL_TRIANGLE_STRIP, indicesCount, GL_UNSIGNED_INT, (GLvoid*) 0);
    
    glDisableClientState(GL_VERTEX_ARRAY);
    glDisableClientState(GL_NORMAL_ARRAY);
    
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}

void Surface3d::deleteBuffers(void)
{
	glDeleteBuffers(1, &verticesId);
    glDeleteBuffers(1, &normalsId);
	glDeleteBuffers(1, &indicesId);
}
