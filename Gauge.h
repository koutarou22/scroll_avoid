#pragma once
#include "Engine/GameObject.h"
class Gauge :
	public GameObject
{
private:
	int hLimit_;

public:

	Gauge(GameObject* parent);

	//������
	void Initialize() override;

	//�X�V
	void Update() override;

	//�`��
	void Draw() override;

	//�J��
	void Release() override;

};

