#pragma once
#include "Engine/GameObject.h"
#include "HP.h"
class Player :
    public GameObject
{
private:
    int hModel_;
	float NDTIME_; //���G����
	int Hp_;

	//�����Ȃ���
	float Stop_R =  1.3;
	float Stop_L = -0.25;

public:
	
	Player(GameObject* parent);

	//������
	void Initialize() override;

	//�X�V
	void Update() override;

	//�`��
	void Draw() override;

	//�J��
	void Release() override;

	void OnCollision(GameObject* pTarget) override;
};

