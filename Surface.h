#pragma once

#include <vector>

using namespace std;

class Surface
{
typedef vector<vector<double> > Matrix;

private:
	struct vec2 {
		double x;
		double y;
	};

	int width;
	int height;

	Matrix surface;

	void normalizeVec2(vec2& v);
	double dotProdVec2(const vec2& v, const vec2& u);
	double dRand(double min, double max);

public:
	Surface(int heigth, int width);
	~Surface(void);

	void perlinNoise(float amplitude, int frequency, unsigned int seed);
	double getZ(int x, int y) const;

	int getHeight(void) const;
	int getWidth(void) const;
};

