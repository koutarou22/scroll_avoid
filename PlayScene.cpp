#include "PlayScene.h"
#include "Road.h"
#include "Player.h"
#include "Enemy.h"
#include "Engine/SceneManager.h"

PlayScene::PlayScene(GameObject* parent)
	:GameObject(parent, "PlayScene")
{
}

void PlayScene::Initialize()
{
	Instantiate<Road>(this);
	Instantiate<Player>(this);
	Instantiate<Enemy>(this);
}

void PlayScene::Update()
{
	//if (FindObject("Player") == nullptr)
	//{
	//	SceneManager* pSceneManager = (SceneManager*)FindObject("SceneManager");
	//	pSceneManager->ChangeScene(SCENE_ID_GAMEOVER);
	//}
}

void PlayScene::Draw()
{
}

void PlayScene::Release()
{
}
