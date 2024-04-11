#pragma once
#include "Engine/GameObject.h"
class Enemy :
    public GameObject
{
private:
	int hModel_;
public:

	float EnemyP_Z = 70.5;

	Enemy(GameObject* parent);

	//‰Šú‰»
	void Initialize() override;

	//XV
	void Update() override;

	//•`‰æ
	void Draw() override;

	//ŠJ•ú
	void Release() override;

	void OnCollision(GameObject* pTarget) override;

};

