#pragma once
#include "Engine/GameObject.h"
class GoalUI :
    public GameObject
{
private:
	int hLimit_;
	int hFrame_;


	int Limitnow_;
	int MaxLimit_;

	int Timer_;
	Transform tr = transform_;

public:

	GoalUI(GameObject* parent);

	//初期化
	void Initialize() override;

	//更新
	void Update() override;

	//描画
	void Draw() override;

	//開放
	void Release() override;

	void SetLimit();

};

