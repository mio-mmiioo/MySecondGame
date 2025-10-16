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

};