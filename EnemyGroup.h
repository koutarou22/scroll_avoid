#pragma once
#include "Enemy.h"
#include "Engine/GameObject.h"
class EnemyGroup :
    public Enemy
{
public:

    float spacing = 0.5; // �Ԋu

    void LeftEnemys();

    void RightEnemys();

    void CenterEnemys();
};

