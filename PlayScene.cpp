#include "PlayScene.h"
#include "Road.h"
#include "Wall.h"
#include "HP.h"
#include "Frame.h"
#include "Gauge.h"
#include "Player.h"
#include "Enemy.h"
#include "Engine/SceneManager.h"


PlayScene::PlayScene(GameObject* parent)
	:GameObject(parent, "PlayScene")
{
}

void PlayScene::Initialize()
{
	Instantiate<Wall>(this);
	
	Wall* rightWall = Instantiate<Wall>(this);
	rightWall->SetPosition(2.05, ObjectY_, WallZ_);

	Instantiate<Road>(this);
	Instantiate<HP>(this);
	Instantiate<Frame>(this);
	Instantiate<Gauge>(this);
	Instantiate<Player>(this);

	switch (Rand)
	{
	  case 0:

		for (int i = -1; i < 1; i++)
		{
			Enemy* p = Instantiate<Enemy>(this);
			p->SetPosition(i + space_, ObjectY_, EnemyZ_);
		}
		break;

	  case 1:

		for (int i = 0; i < 2; i++)
		{
			Enemy* p = Instantiate<Enemy>(this);
			p->SetPosition(i + space_, ObjectY_, EnemyZ_);
		}
		break;

	  case 2:

		Enemy* LEnemy = Instantiate<Enemy>(this);
		LEnemy->SetPosition(-0.5, ObjectY_, EnemyZ_);

		Enemy* REnemy = Instantiate<Enemy>(this);
		REnemy->SetPosition(1.5, ObjectY_, EnemyZ_);

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
	else if (FindObject("Gauge") == nullptr)
	{
		SceneManager* pSceneManager = (SceneManager*)FindObject("SceneManager");
		pSceneManager->ChangeScene(SCENE_ID_CLEAR);
		
	}
    else if (CoolTimer_ >= MaxTime_) //『フレーム』で処理
    {
         CoolTimer_ = 0; // timerのリセット
    
        MaxTime_ -= 20;

        if (MaxTime_ < 26) {
            MaxTime_ = 26;
        }   

        Rand = (lastLane_ + rand() % 2 + 1) % 3;
        lastLane_ = Rand;

        Enemy* p = nullptr;

		switch (Rand)
		{
		case 0:

			for (int i = -1; i < 1; i++)
			{
				Enemy* p = Instantiate<Enemy>(this);
				p->SetPosition(i + space_, ObjectY_, EnemyZ_);
			}
			break;

		case 1:

			for (int i = 0; i < 2; i++)
			{
				Enemy* p = Instantiate<Enemy>(this);
				p->SetPosition(i + space_, ObjectY_, EnemyZ_);
			}
			break;

		case 2:

			Enemy * LEnemy = Instantiate<Enemy>(this);
			LEnemy->SetPosition(-0.5, ObjectY_, EnemyZ_);

			Enemy* REnemy = Instantiate<Enemy>(this);
			REnemy->SetPosition(1.5, ObjectY_, EnemyZ_);

			break;

		}
    }
    else
    {
        CoolTimer_++;
    }
}


void PlayScene::Draw()
{
}

void PlayScene::Release()
{
}
