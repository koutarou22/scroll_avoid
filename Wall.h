#pragma once
#include "Engine/GameObject.h"
class Wall :
	public GameObject
{
private:
	int hModel_;
	int WallRoad_;
	int WallHigh_;

public:

	

	Wall(GameObject* parent);

	//‰Šú‰»
	void Initialize() override;

	//XV
	void Update() override;

	//•`‰æ
	void Draw() override;

	//ŠJ•ú
	void Release() override;
};
