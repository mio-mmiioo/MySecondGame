#include "GameObject.h"

GameObject::GameObject()
	:pParent_(nullptr)
{
}

GameObject::GameObject(GameObject* parent, const std::string& name)
	:pParent_(parent), objectName_(name)
{
}

GameObject::~GameObject()
{
}

void GameObject::Release()
{
}

void GameObject::UpdateSub()
{
	Update();
	for (auto child : childList_)
	{
		child->UpdateSub();
	}
}

void GameObject::ReleaseSub()
{
	this->Release(); 
	for (auto child : childList_)
	{
		child->ReleaseSub();
	}
}

void GameObject::DrawSub()
{
	// ���g��`��
	// �q�I�u�W�F�N�g��`�� childList �̊e�v�f�ɑ΂���Draw���Ă�

	Draw();
	for (auto child : childList_)
	{
		child->DrawSub();
	}
}
