#pragma once
#include "Engine/GameObject.h"
class PlayScene :
    public GameObject
{
private:
	int CoolTimer_ = 0; 
	int MaxTime_ = 240;
	int Rand = rand() % 3;//ランダムに三通り選ばれる
	int lastLane_ = -1;//同じパターンが出ないようにする対策

	float ObjectY_ = 0.7;
	float WallZ_ = 2.5;
	float EnemyZ_ = 70.5;
	float space_ = 0.5;//間隔
	
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

