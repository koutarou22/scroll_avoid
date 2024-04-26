#pragma once
#include "Engine/GameObject.h"
class Wall :
	public GameObject
{
private:
	int hModel_;
	int WallRoad_;
	float WallHigh_;
	

public:

	Wall(GameObject* parent);

	//初期化
	void Initialize() override;

	//更新
	void Update() override;

	//描画
	void Draw() override;

	//開放
	void Release() override;
};
