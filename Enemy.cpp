#include "Enemy.h"
#include "Engine/Model.h"
#include "Engine/SphereCollider.h"

Enemy::Enemy(GameObject* parent)
	:GameObject(parent, "Enemy"), hModel_(-1)
{
}

void Enemy::Initialize()
{
	hModel_ = Model::Load("box.fbx");
	assert(hModel_ >= 0);

	transform_.position_.x = 0.5;
	transform_.position_.z = 70.5;
	transform_.position_.y = 0.7;

	SphereCollider* collision = new SphereCollider(XMFLOAT3(0, 0, 0), 0.5f);
	AddCollider(collision);
}

void Enemy::Update()
{
	transform_.position_.z -= 0.7;

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
