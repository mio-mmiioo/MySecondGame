#include "Model.h"

namespace Model
{
	std::vector<ModelData*> modelList;
}

int Model::Load(std::string fileName)
{
	ModelData* pModelData = new ModelData;
	pModelData->filename_ = fileName;
	pModelData->pFbx_ = nullptr;

	for (auto& itr : modelList)
	{
		if (itr->filename_ == fileName)
		{
			pModelData->pFbx_ = itr->pFbx_;
			break;
		}
	}
	
	if (pModelData->pFbx_ == nullptr)
	{
		pModelData->pFbx_ = new Fbx;
		pModelData->pFbx_->Load(fileName.c_str());
	}
	modelList.push_back(pModelData);
	return ((int)(modelList.size() - 1));
}

void Model::SetTransform(int hModel, Transform transform)
{
	modelList[hModel]->transform_ = transform;
}

void Model::Draw(int hModel)
{
	modelList[hModel]->pFbx_->Draw(modelList[hModel]->transform_);
}

void Model::Release()
{
}
