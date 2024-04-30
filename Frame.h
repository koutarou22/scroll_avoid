#pragma once
#include "Engine/GameObject.h"
class Frame :
    public GameObject
{
private:
	int hFrame_;
public:

	Frame(GameObject* parent);

	//‰Šú‰»
	void Initialize() override;

	//XV
	void Update() override;

	//•`‰æ
	void Draw() override;

	//ŠJ•ú
	void Release() override;

};

