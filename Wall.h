#pragma once
#include "Engine/GameObject.h"
class Wall :
	public GameObject
{
private:
	int hModel_;
	int WallRoad_;
	int WallHigh_;

public:

	

	Wall(GameObject* parent);

	//������
	void Initialize() override;

	//�X�V
	void Update() override;

	//�`��
	void Draw() override;

	//�J��
	void Release() override;
};
