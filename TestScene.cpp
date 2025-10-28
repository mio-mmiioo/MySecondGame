#include "TestScene.h"
#include "Engine/Input.h"
#include "Engine/GameObject.h"
#include "Engine/SceneManager.h"

TestScene::TestScene(GameObject* parent)
	:GameObject(parent, "TestScene")
{
}

TestScene::~TestScene()
{
}

void TestScene::Initialize()
{
}

void TestScene::Update()
{
	if (Input::IsKeyDown(DIK_SPACE))
	{
		//SceneManager* sceneManager = FindObject("SceneManager");
		//sceneManager->ChangeScene(SCENE_ID_PLAY);
		SceneManager::ChangeScene("SceneManager");
	}
}

void TestScene::Draw()
{
}

void TestScene::Release()
{
}