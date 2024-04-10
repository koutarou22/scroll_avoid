#include "EnemyGroup.h"


void EnemyGroup::LeftEnemys()
{
    for (int i = -1; i < 1; i++) 
    {
	  Enemy* p = Instantiate<Enemy>(this);
	  p->SetPosition(i + spacing, 0.7, 15.5);
    }
}

void EnemyGroup::RightEnemys()
{
    for (int i = 0; i < 2; i++)
    {
      Enemy* p = Instantiate<Enemy>(this);
      p->SetPosition(i + spacing, 0.7, 15.5);
    }
}  

void EnemyGroup::CenterEnemys()
{
    spacing = 0.0;
    Enemy* leftEnemy = Instantiate<Enemy>(this);
    leftEnemy->SetPosition(-0.5, 0.7, 15.5);

    Enemy* rightEnemy = Instantiate<Enemy>(this);
    rightEnemy->SetPosition(1.5, 0.7, 15.5);
}
