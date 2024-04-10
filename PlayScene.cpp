#include "PlayScene.h"
#include "Road.h"
#include "Player.h"
#include "Enemy.h"
#include "Engine/SceneManager.h"

float CoolTimer = 0;

PlayScene::PlayScene(GameObject* parent)
	:GameObject(parent, "PlayScene")
{
}

void PlayScene::Initialize()
{
	Instantiate<Road>(this);
	Instantiate<Player>(this);

	float spacing = 0.5;
	int randame = rand() % 3;


	switch (randame)
	{
	  case 0:

		for (int i = -1; i < 1; i++)
		{
			Enemy* p = Instantiate<Enemy>(this);
			p->SetPosition(i + spacing, 0.7, 15.5);
		}
		break;

	  case 1:

		for (int i = 0; i < 2; i++)
		{
			Enemy* p = Instantiate<Enemy>(this);
			p->SetPosition(i + spacing, 0.7, 15.5);
		}
		break;

	  case 2:

		Enemy* p = Instantiate<Enemy>(this);
		p->SetPosition(-0.5, 0.7, 15.5);

		Enemy* p = Instantiate<Enemy>(this);
		p->SetPosition(1.5, 0.7, 15.5);

		break;
		
	  default:

		break;
	}

}

void PlayScene::Update()
{
	if (FindObject("Player") == nullptr)
	{
		SceneManager* pSceneManager = (SceneManager*)FindObject("SceneManager");
		pSceneManager->ChangeScene(SCENE_ID_GAMEOVER);
	}
}

void PlayScene::Draw()
{
}

void PlayScene::Release()
{
}
