#pragma once
#include "Engine/GameObject.h"
class HP :
    public GameObject
{
private:
	int hImage_;
	int Wide_ = 3;

public:

	HP(GameObject* parent);

	//‰Šú‰»
	void Initialize() override;

	//XV
	void Update() override;

	//•`‰æ
	void Draw() override;

	//ŠJ•ú
	void Release() override;

	void DamageHp();//Player‚Å‘€ì‚µ‚½‚¢
};

