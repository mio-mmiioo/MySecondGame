#pragma once

#include <string>
#include "Transform.h"
#include <list>

using std::string;
using std::list;

class GameObject
{
public:
	GameObject();
	GameObject(GameObject* parent, const std::string& name);
	virtual ~GameObject();

	virtual void Initialize() = 0;
	virtual void Update() = 0;
	virtual void Draw() = 0;
	virtual void Release() = 0;
	void UpdateSub();
	void ReleaseSub();
	void DrawSub(); // �q�I�u�W�F�N�g�����ׂĕ`�悷��

	void SetPosition(XMFLOAT3 position) { transform_.position_ = position; }
	void SetPosition(float x, float y, float z) { transform_.position_.x = x, transform_.position_.y = y, transform_.position_.z = z; }
	void KillMe();

	GameObject* GetRootJob(); 
	GameObject* FindChildObject(const string& name);
	GameObject* FindObjectByName(const string& name);

	template<class T>
	GameObject* Instantiate(GameObject* parent)
	{
		T* obj = new T(parent);
		obj->Initialize();
		childList_.push_back(obj);
		return obj;
	}

protected:
	list<GameObject*> childList_;
	Transform transform_;
	GameObject* pParent_;
	std::string objectName_;

private:
	bool isDead_;
};