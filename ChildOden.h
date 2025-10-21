#pragma once
#include "Engine/GameObject.h"
#include "Engine/Model.h"

class Fbx;

class ChildOden : public GameObject
{
public:
	ChildOden(GameObject* parent);
	~ChildOden();

	void Initialize() override;
	void Update() override;
	void Draw() override;
	void Release() override;
private:
	Fbx* pFbx_;
	int hModel_; // ƒ‚ƒfƒ‹ƒnƒ“ƒhƒ‹
};
