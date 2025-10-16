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
	transform_.scale_.x = 0.7f;
	transform_.scale_.y = 0.7f;
	transform_.scale_.z = 0.7f;
	transform_.position_.x = 3.0f;
}

void ChildOden::Update()
{
	transform_.rotate_.y += 0.5f;
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
