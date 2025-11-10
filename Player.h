#pragma once
#include "Engine/GameObject.h"

class Fbx;
class ChildOden;
class SphereCollider;

class Player : public GameObject
{
public:
	Player(GameObject* parent);
	~Player();
	// 純粋仮想関数のオーバーライド
	void Initialize() override;
	void Update() override;
	void Draw() override;
	void Release() override;
	void OnCollision(GameObject* pTarger);

private:
	Fbx* pFbx_;
	SphereCollider* pSphereCollider_;
	int hModel_;
	ChildOden* pRChildOden_;
	ChildOden* pLChildOden_;
};
