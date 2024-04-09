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

	//������
	void Initialize() override;

	//�X�V
	void Update() override;

	//�`��
	void Draw() override;

	//�J��
	void Release() override;
};

