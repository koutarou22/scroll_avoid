#include "Player.h"
#include "Hp.h"
#include "Engine/Model.h"
#include "Engine/Input.h"
#include "Engine/SceneManager.h"
#include "Engine/SphereCollider.h"

Player::Player(GameObject* parent)
	:GameObject(parent, "Player"), hModel_(-1)
{
}

void Player::Initialize()
{
	hModel_ = Model::Load("PlayerM.fbx");
	assert(hModel_ >= 0);

	transform_.position_ = XMFLOAT3(0.5, 0.5, 1.5);

	SphereCollider* collision = new SphereCollider({ 0, 0, 0 }, 0.2f);
	AddCollider(collision);

	Hp_ = 3;
}

void Player::Update()
{

	if (Input::IsKey(DIK_RIGHT) || Input::IsKey(DIK_D))
	{
			transform_.position_.x += 0.06;
	
		if (transform_.position_.x >= Stop_R)
	    {
			transform_.position_.x = Stop_R;
	    }
	}

	if (Input::IsKey(DIK_LEFT) || Input::IsKey(DIK_A))
	{
            transform_.position_.x -= 0.06;

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
	Hp_--;

	if (Hp_ <= 0)
	{
		KillMe();
	}
	
}
