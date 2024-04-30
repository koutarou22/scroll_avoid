#pragma once
#include "Engine/GameObject.h"
class Gauge :
	public GameObject
{
private:
	int hLimit_;

public:

	Gauge(GameObject* parent);

	//‰Šú‰»
	void Initialize() override;

	//XV
	void Update() override;

	//•`‰æ
	void Draw() override;

	//ŠJ•ú
	void Release() override;

};

