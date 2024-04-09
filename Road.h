#pragma once
#include "Engine/GameObject.h"
class Road :
    public GameObject
{
private:
    int hModel_;
public:
    
	int RoadWidth_, RoadHight_;

	Road(GameObject* parent);

	//‰Šú‰»
	void Initialize() override;

	//XV
	void Update() override;

	//•`‰æ
	void Draw() override;

	//ŠJ•ú
	void Release() override;
};

