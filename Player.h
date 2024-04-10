#pragma once
#include "Engine/GameObject.h"
class Player :
    public GameObject
{
private:
    int hModel_;

	//見えない壁
	float Stop_R =  1.5;
	float Stop_L = -0.5;

public:

	Player(GameObject* parent);

	//初期化
	void Initialize() override;

	//更新
	void Update() override;

	//描画
	void Draw() override;

	//開放
	void Release() override;

	void OnCollision(GameObject* pTarget) override;
};

