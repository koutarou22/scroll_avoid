#include "Player.h"
#include "Engine/Model.h"
Player::Player(GameObject* parent)
{
}

void Player::Initialize()
{
	hModel_ = Model::Load("box.fbx");
	assert(hModel_ >= 0);

	transform_.position_.x = 0.5;
	transform_.position_.z = 1.5;
	transform_.position_.y = 0.5;
}

void Player::Update()
{
}

void Player::Draw()
{
	Model::SetTransform(hModel_, transform_);
	Model::Draw(hModel_);
	
}

void Player::Release()
{
}
