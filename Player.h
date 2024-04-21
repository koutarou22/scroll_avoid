#pragma once
#include "Engine/GameObject.h"
class Player :
    public GameObject
{
private:
    int hModel_;
	

	//見えない壁
	float Stop_R =  1.3;
	float Stop_L = -0.25;

public:

	int Hp_;

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

