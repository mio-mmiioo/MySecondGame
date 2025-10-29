#include "TestScene.h"
#include "Engine/Input.h"
#include "Engine/GameObject.h"
#include "Engine/SceneManager.h"
#include "Enemy.h"

TestScene::TestScene(GameObject* parent)
	:GameObject(parent, "TestScene")
{
}

TestScene::~TestScene()
{
}

void TestScene::Initialize()
{
	Instantiate<Enemy>(this);
}

void TestScene::Update()
{
	if (Input::IsKeyDown(DIK_SPACE))
	{
		GameObject* sceneManager = GameObject::FindObject("SceneManager");
		sceneManager->ChangeScene(1);
	}
}

void TestScene::Draw()
{
}

void TestScene::Release()
{
}