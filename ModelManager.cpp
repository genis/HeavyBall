#include "ModelManager.h"

typedef pair<string, Model*> dataPair;
typedef map<string, Model*>::iterator dataIter;
typedef map<string, Model*>::const_iterator const_dataIter;

ModelManager::ModelManager(void)
{
}

ModelManager::~ModelManager(void)
{
	for (dataIter it = modelData.begin(); it != modelData.end(); ++it) {
		delete (it->second);
	}
}

void ModelManager::loadModel(const string& name, const char* modelPath)
{

}

Model* ModelManager::getModel(const string& name) const
{
	const_dataIter it = modelData.find(name);

	if (it == modelData.end()) return NULL;

	return it->second; 
}