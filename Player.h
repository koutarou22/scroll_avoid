#pragma once
#include "Engine/GameObject.h"
#include "HP.h"
class Player :
    public GameObject
{
private:
    int hModel_;
	float NDTIME_; //–³“GŠÔ
	int Hp_;

	//Œ©‚¦‚È‚¢•Ç
	float Stop_R =  1.3;
	float Stop_L = -0.25;

public:
	
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

