#pragma once
#include "Engine/GameObject.h"
class Frame :
    public GameObject
{
private:
	int hFrame_;
public:

	Frame(GameObject* parent);

	//������
	void Initialize() override;

	//�X�V
	void Update() override;

	//�`��
	void Draw() override;

	//�J��
	void Release() override;

};

