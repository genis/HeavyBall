#pragma once
#include "Model.h"
#include <string>
#include <map>

using namespace std;

class ModelManager
{
public:
	ModelManager(void);
	~ModelManager(void);

	void loadModel(const string& name, const char* modelPath);
	Model* getModel(const string& name) const;

private:
	map<string, Model*> modelData;
};

