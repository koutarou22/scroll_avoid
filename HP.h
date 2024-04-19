#pragma once
#include "Engine/GameObject.h"
class HP :
    public GameObject
{
private:
	int hImage_;

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
};

