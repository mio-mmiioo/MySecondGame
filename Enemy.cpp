#include "Enemy.h"
#include "Engine/Fbx.h"
#include "Engine/Model.h"
#include "Engine/Input.h"

Enemy::Enemy(GameObject* parent)
	:GameObject(parent, "Enemy"), // ←ここで名前つけるのあまりよくない
	pFbx_(nullptr),
	hModel_(-1)
{
}

Enemy::~Enemy()
{
}

void Enemy::Initialize()
{
	pFbx_ = new Fbx();
	pFbx_->Load("box.fbx");
	transform_.scale_.x = 0.7f;
	transform_.scale_.y = 0.7f;
	transform_.scale_.z = 0.7f;
	hModel_ = Model::Load("box.fbx");
}

void Enemy::Update()
{
	transform_.rotate_.y += 0.05f;
	if (Input::IsKeyDown(DIK_K)) // フレームワークがない弊害起きてる
	{
		KillMe();
	}
}

void Enemy::Draw()
{
	Model::SetTransform(hModel_, transform_);
	Model::Draw(hModel_);
}

void Enemy::Release()
{
	if (pFbx_)
	{
		pFbx_->Release();
		delete pFbx_;
		pFbx_ = nullptr;
	}
}
