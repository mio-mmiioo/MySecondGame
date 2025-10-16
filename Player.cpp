#include "Player.h"
#include "Engine/Fbx.h"
#include "ChildOden.h"

Player::Player(GameObject* parent)
	:GameObject(parent, "Player"), // ←ここで名前つけるのあまりよくない
	pFbx_(nullptr)
{
}

Player::~Player()
{
}

void Player::Initialize()
{
	pFbx_ = new Fbx();
	pFbx_->Load("oden.fbx");
	transform_.scale_.x = 0.7f;
	transform_.scale_.y = 0.7f;
	transform_.scale_.z = 0.7f;

	// 子オブジェクトにChildOdenを追加する
	Instantiate<ChildOden>(this);
}

void Player::Update()
{
	transform_.rotate_.y += 0.1f;
}

void Player::Draw()
{
	if (pFbx_)
	{
		pFbx_->Draw(transform_);
	}
}

void Player::Release()
{
	if (pFbx_)
	{
		pFbx_->Release();
		delete pFbx_;
		pFbx_ = nullptr;
	}
}
