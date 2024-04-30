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

	//‰Šú‰»
	void Initialize() override;

	//XV
	void Update() override;

	//•`‰æ
	void Draw() override;

	//ŠJ•ú
	void Release() override;

	void SetLimit();

};

