#include "SceneManager.h"
#include "../PlayScene.h"
#include "../TestScene.h"
#include "Direct3D.h"

SceneManager::SceneManager(GameObject* parent)
	:GameObject(parent, "SceneManager")
{
}

SceneManager::~SceneManager()
{
}

void SceneManager::Initialize()
{
	currentSceneID_ = SCENE_ID_TEST;
	nextSceneID_ = currentSceneID_;
	Instantiate<TestScene>(this);
}

void SceneManager::Update()
{
	if (currentSceneID_ != nextSceneID_)
	{
		// �V�[���؂�ւ�����
		auto scene = childList_.front();
		scene->ReleaseSub();
		SAFE_DELETE(scene);
		childList_.clear();
		switch (nextSceneID_)
		{
		case SCENE_ID_PLAY:
			Instantiate<PlayScene>(this);
			break;
		case SCENE_ID_TEST:
			Instantiate<TestScene>(this);
			break;
		}
		currentSceneID_ = nextSceneID_;
	}
}

void SceneManager::Draw()
{
}

void SceneManager::Release()
{
}

void SceneManager::ChangeScene(int sceneId)
{
	switch (sceneId)
	{
	case 0:
		nextSceneID_ = SCENE_ID_TEST;
		break;
	case 1:
		nextSceneID_ = SCENE_ID_PLAY;
		break;
	}
}
