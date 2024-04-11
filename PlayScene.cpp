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

	switch (randame)
	{
	  case 0:

		for (int i = -1; i < 1; i++)
		{
			Enemy* p = Instantiate<Enemy>(this);
			p->SetPosition(i + spacing, 0.7, 70.5);
		}
		break;

	  case 1:

		for (int i = 0; i < 2; i++)
		{
			Enemy* p = Instantiate<Enemy>(this);
			p->SetPosition(i + spacing, 0.7, 70.5);
		}
		break;

	  case 2:

		Enemy* LEnemy = Instantiate<Enemy>(this);
		LEnemy->SetPosition(-0.5, 0.7, 70.5);

		Enemy* REnemy = Instantiate<Enemy>(this);
		REnemy->SetPosition(1.5, 0.7, 70.5);

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
    else if (CoolTimer >= MaxTime) //�w�t���[���x�ŏ���
    {
         CoolTimer = 0; // timer�̃��Z�b�g
    
        MaxTime -= 15;
        if (MaxTime < 30) {
            MaxTime = 30;
        }   
       
        randame = (lastLane + rand() % 2 + 1) % 3;
        lastLane = randame;

        Enemy* p = nullptr;
        Enemy* p2 = nullptr;

        switch (randame)
        {
        case 0: 
            for (int i = 0; i < 2; i++)
            {
                p = Instantiate<Enemy>(this);
                p->SetPosition(i + spacing, 0.5, 70.5);
            }
            break;

        case 1: 
            for (int i = -1; i < 1; i++)
            {
                p = Instantiate<Enemy>(this);
                p->SetPosition(i + spacing, 0.5, 70.5);
            }
            break;

        case 2: 

            p = Instantiate<Enemy>(this);
            p->SetPosition(-0.5, 0.5, 70.5);

            p = Instantiate<Enemy>(this);
            p->SetPosition(1.5, 0.5, 70.5);
            break;

        default:
            break;
        }
    }
    else
    {
        CoolTimer++;
    }
}


void PlayScene::Draw()
{
}

void PlayScene::Release()
{
}
