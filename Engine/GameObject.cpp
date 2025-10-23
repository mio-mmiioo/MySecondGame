#include "GameObject.h"

GameObject::GameObject()
	:pParent_(nullptr),
	isDead_(false)
{
}

GameObject::GameObject(GameObject* parent, const std::string& name)
	:pParent_(parent), objectName_(name), isDead_(false)
{
	if (parent != nullptr)
	{
		transform_.pParent_ = &(parent->transform_);
	}
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

	for (auto itr = childList_.begin(); itr != childList_.end();)
	{
		if ((*itr)->isDead_)
		{
			(*itr)->ReleaseSub();
			delete(*itr);
			itr = childList_.erase(itr);
		}
		else
		{
			itr++;
		}
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

void GameObject::KillMe()
{
	isDead_ = true;
}

GameObject* GameObject::GetRootJob()
{
	if (pParent_ == nullptr)
	{
		return this; // �e�����Ȃ���RootJob
	}
	else
	{
		return pParent_->GetRootJob();
	}
}

GameObject* GameObject::FindChildObject(const string& name)
{
	if (objectName_ == name)
	{
		return this; // �T����Ă���I�u�W�F�N�g
	}
	else
	{
		for (auto child : childList_)
		{
			GameObject* result = child->FindChildObject(name);
			if (result != nullptr)
			{
				return result;
			}
		}
		return nullptr; // ������Ȃ�����
	}
}

GameObject* GameObject::FindObjectByName(const string& name)
{
	GameObject* rootJob = GetRootJob();
	GameObject* result = rootJob->FindObjectByName(name);
	return result;
}
