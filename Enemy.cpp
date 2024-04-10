#include "Enemy.h"
#include "Engine/Model.h"

Enemy::Enemy(GameObject* parent)
{
}

void Enemy::Initialize()
{
	hModel_ = Model::Load("Enemy.fbx");
	assert(hModel_ >= 0);

	transform_.position_.x = 0.5;
	transform_.position_.z = 15.5;
	transform_.position_.y = 0.7;

	transform_.rotate_.x = 180;
}

void Enemy::Update()
{
	XMVECTOR vFront = { 0,0,0,1 };
	XMVECTOR move{ 0,0,0,0 };

	transform_.position_.z -= 0.05;
}

void Enemy::Draw()
{
	Model::SetTransform(hModel_, transform_);
	Model::Draw(hModel_);
}

void Enemy::Release()
{
}
