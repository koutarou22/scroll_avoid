#pragma once
#include "Engine/GameObject.h"
class HP :
    public GameObject
{
private:
	int hImage_;

public:

	HP(GameObject* parent);

	//������
	void Initialize() override;

	//�X�V
	void Update() override;

	//�`��
	void Draw() override;

	//�J��
	void Release() override;
};
