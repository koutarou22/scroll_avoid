#pragma once
#include "Engine/GameObject.h"
class PlayScene :
    public GameObject
{
private:
	int CoolTimer = 0; 
	int MaxTime = 240;
	float spacing = 0.5;//�Ԋu
	int randame = rand() % 3;//�����_���ɎO�ʂ�I�΂��
	int lastLane = -1;
public:
	//�R���X�g���N�^
	//�����Fparent  �e�I�u�W�F�N�g�iSceneManager�j
	PlayScene(GameObject* parent);

	//������
	void Initialize() override;

	//�X�V
	void Update() override;

	//�`��
	void Draw() override;

	//�J��
	void Release() override;
};

