#pragma once
#include "Engine/GameObject.h"
class PlayScene :
    public GameObject
{
private:
	int CoolTimer_ = 0; 
	int MaxTime_ = 240;
	int Rand = rand() % 3;//�����_���ɎO�ʂ�I�΂��
	int lastLane_ = -1;//�����p�^�[�����o�Ȃ��悤�ɂ���΍�

	float ObjectY_ = 0.7;
	float WallZ_ = 2.5;
	float EnemyZ_ = 70.5;
	float space_ = 0.5;//�Ԋu
	
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

