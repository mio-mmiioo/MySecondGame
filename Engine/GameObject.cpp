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
	// 自身を描画
	// 子オブジェクトを描画 childList の各要素に対してDrawを呼ぶ

	Draw();
	for (auto child : childList_)
	{
		child->DrawSub();
	}
}
