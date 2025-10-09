#include "RootJob.h"
#include "../PlayScene.h"

RootJob::RootJob(GameObject* parent)
	:GameObject(parent, "RootJob")
{
}

RootJob::~RootJob()
{
}

void RootJob::Initialize()
{
	PlayScene* playScene = new PlayScene(this);
	playScene->Initialize();
	childList_.push_back(playScene);
	
}

void RootJob::Update()
{
}

void RootJob::Draw()
{
}

void RootJob::Release()
{
}
