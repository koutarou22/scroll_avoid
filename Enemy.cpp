#include "Enemy.h"
#include "Engine/Model.h"
#include "Engine/SphereCollider.h"


Enemy::Enemy(GameObject* parent)
	:GameObject(parent, "Enemy"), hModel_(-1)
{
}

void Enemy::Initialize()
{
	hModel_ = Model::Load("Model/character-orc.fbx");
	assert(hModel_ >= 0);

	transform_.scale_ = XMFLOAT3(0.015f, 0.015f, 0.015f);
	transform_.rotate_.y = 180;

	transform_.position_ = XMFLOAT3(0.5, 0.7, 0.7);

	SphereCollider* collision = new SphereCollider(XMFLOAT3(0, 0, 0), 0.5f);
	AddCollider(collision);
}

void Enemy::Update()
{
	transform_.position_.z -= DefaultSpeed_;

	if (transform_.position_.z <= 0)//‚»‚Ì”ÍˆÍ‚ð’´‚¦‚½‚çÁ–Å
	{
		KillMe();
	}
}

void Enemy::Draw()
{
	Model::SetTransform(hModel_, transform_);
	Model::Draw(hModel_);

}

void Enemy::Release()
{
}

void Enemy::OnCollision(GameObject* pTarget)
{

}
