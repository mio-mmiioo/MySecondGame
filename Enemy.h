#pragma once
#include "Engine/GameObject.h"

class Fbx;
class SphereCollider;

class Enemy : public GameObject
{
public:
	Enemy(GameObject* parent);
	~Enemy();
	// 純粋仮想関数のオーバーライド
	void Initialize() override;
	void Update() override;
	void Draw() override;
	void Release() override;
private:
	Fbx* pFbx_;
	SphereCollider* pSphereCollider_;
	int hModel_;
};
