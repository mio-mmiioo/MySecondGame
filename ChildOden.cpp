#include "ChildOden.h"
#include "Engine/Fbx.h"

ChildOden::ChildOden(GameObject* parent)
	:GameObject(parent, "ChildOden"), // ©‚±‚±‚Å–¼‘O‚Â‚¯‚é‚Ì‚ ‚Ü‚è‚æ‚­‚È‚¢
	pFbx_(nullptr)
{
}

ChildOden::~ChildOden()
{
}

void ChildOden::Initialize()
{
	pFbx_ = new Fbx();
	pFbx_->Load("oden.fbx");
	transform_.scale_.x = 0.3f;
	transform_.scale_.y = 0.3f;
	transform_.scale_.z = 0.3f;
	transform_.position_.x = 2.0f;
	transform_.position_.y = 1.0f;
}

void ChildOden::Update()
{
	transform_.rotate_.y += 0.05f;
}

void ChildOden::Draw()
{
	if (pFbx_)
	{
		pFbx_->Draw(transform_);
	}
}

void ChildOden::Release()
{
	if (pFbx_)
	{
		pFbx_->Release();
		delete pFbx_;
		pFbx_ = nullptr;
	}
}
