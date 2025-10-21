#include "Player.h"
#include "Engine/Fbx.h"
#include "ChildOden.h"

Player::Player(GameObject* parent)
	:GameObject(parent, "Player"), // �������Ŗ��O����̂��܂�悭�Ȃ�
	pFbx_(nullptr),
	hModel_(-1)
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
	hModel_ = Model::Load("oden.fbx");

	// �q�I�u�W�F�N�g��ChildOden��ǉ�����
	pRChildOden_ = (ChildOden*)Instantiate<ChildOden>(this);
	pLChildOden_ = (ChildOden*)Instantiate<ChildOden>(this);
	pRChildOden_->SetPosition(2.0f, 1.0f, 0.0f);
	pLChildOden_->SetPosition(-2.0f, 1.0f, 0.0f);
}

void Player::Update()
{
	transform_.rotate_.y += 0.05f; // �t���[�����[�N���Ȃ����Q�N���Ă�

	if (transform_.rotate_.y > 16.0f) // �t���[�����[�N���Ȃ����Q�N���Ă�
	{
		KillMe();
	}
}

void Player::Draw()
{
	//if (pFbx_)
	//{
	//	pFbx_->Draw(transform_);
	//}
	Model::SetTransform(hModel_, transform_);
	Model::Draw(hModel_);
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
