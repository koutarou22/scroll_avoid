#pragma once
#include "Engine/GameObject.h"
class Player :
    public GameObject
{
private:
    int hModel_;
	

	//Œ©‚¦‚È‚¢•Ç
	float Stop_R =  1.3;
	float Stop_L = -0.25;

public:

	int Hp_;

	Player(GameObject* parent);

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

