#pragma once
#include "Engine/GameObject.h"
class PlayScene :
    public GameObject
{
private:
	int CoolTimer = 0; 
	int MaxTime = 240;
	float spacing = 0.5;//間隔
	int randame = rand() % 3;//ランダムに三通り選ばれる
	int lastLane = -1;
public:
	//コンストラクタ
	//引数：parent  親オブジェクト（SceneManager）
	PlayScene(GameObject* parent);

	//初期化
	void Initialize() override;

	//更新
	void Update() override;

	//描画
	void Draw() override;

	//開放
	void Release() override;
};

