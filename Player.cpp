#include "Player.h"
#include "Engine/Model.h"
#include "Engine/Input.h"
#include "Engine/SceneManager.h"
#include "Engine/SphereCollider.h"

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

	SphereCollider* collision = new SphereCollider({ 0, 0, 0 }, 4.0f);
	AddCollider(collision);
}

void Player::Update()
{

	if (Input::IsKey(DIK_RIGHT) || Input::IsKey(DIK_D))
	{
			transform_.position_.x += 0.1;
	
		if (transform_.position_.x >= Stop_R)
	    {
			transform_.position_.x = Stop_R;
	    }
	}

	if (Input::IsKey(DIK_LEFT) || Input::IsKey(DIK_A))
	{
            transform_.position_.x -= 0.1;

		if (transform_.position_.x <= Stop_L)
        {
	        transform_.position_.x = Stop_L;
	    }
	}
	
}

void Player::Draw()
{
	Model::SetTransform(hModel_, transform_);
	Model::Draw(hModel_);
}

void Player::Release()
{
}

void Player::OnCollision(GameObject* pTarget)
{
	if (pTarget->GetObjectName() == "Enemy") {
		this->KillMe();
		pTarget->KillMe();
	}
}
