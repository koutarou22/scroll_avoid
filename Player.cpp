#include "Player.h"
#include "Engine/Model.h"
#include "Engine/Input.h"
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

	if (Input::IsKey(DIK_RIGHT) || Input::IsKey(DIK_D))
	{
			transform_.position_.x += 0.1;
	
		if (transform_.position_.x >= 1.5)
	    {
			transform_.position_.x = 1.5;
	    }
	}

	if (Input::IsKey(DIK_LEFT) || Input::IsKey(DIK_A))
	{
            transform_.position_.x -= 0.1;

		if (transform_.position_.x <= -0.5)
        {
	        transform_.position_.x = -0.5;
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
