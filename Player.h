#pragma once
#include "Engine/GameObject.h"
#include "HP.h"
class Player :
    public GameObject
{
private:
    int hModel_;
	float NDTIME_; //無敵時間
	int Hp_;

	//見えない壁
	float Stop_R =  1.3;
	float Stop_L = -0.25;

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

