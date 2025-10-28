#pragma once
#include "Engine/GameObject.h"

class Fbx;

class Enemy : public GameObject
{
public:
	Enemy(GameObject* parent);
	~Enemy();
	// �������z�֐��̃I�[�o�[���C�h
	void Initialize() override;
	void Update() override;
	void Draw() override;
	void Release() override;
private:
	Fbx* pFbx_;
	int hModel_;
};
