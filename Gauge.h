#pragma once
#include "Engine/GameObject.h"
class Gauge :
	public GameObject
{
private:
	int hLimit_;

public:

	Gauge(GameObject* parent);

	//初期化
	void Initialize() override;

	//更新
	void Update() override;

	//描画
	void Draw() override;

	//開放
	void Release() override;

};

