#include "Player.h"
#include "Hp.h"
#include "Engine/Model.h"
#include "Engine/Input.h"
#include "Engine/SceneManager.h"
#include "Engine/SphereCollider.h"
#include "Engine/Debug.h"
#include <iostream>

using namespace std;

Player::Player(GameObject* parent)
	:GameObject(parent, "Player"), hModel_(-1)
{
}

void Player::Initialize()
{
	hModel_ = Model::Load("Player.fbx");
	assert(hModel_ >= 0);

	transform_.position_ = XMFLOAT3(0.5, 0.5, 1.5);
	transform_.scale_ = XMFLOAT3(1.0, 1.0, 1.0);

	SphereCollider* collision = new SphereCollider({ 0, 0, 0 }, 0.2f);
	AddCollider(collision);

	Hp_ = 3;
	
	
	NDTIME_ = 1.0f;
	
}

void Player::Update()
{
	NDTIME_ = true;
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
	
	if (NDTIME_ > 0.0f)
	{
		NDTIME_ -= 0.5;
	}
}

void Player::Draw()
{
	if (NDTIME_)
	{
		Model::SetTransform(hModel_, transform_);
		Model::Draw(hModel_);
	}
	
}

void Player::Release()
{
}

void Player::OnCollision(GameObject* pTarget)
{
	

	Debug::Log("–³“GŽžŠÔ•t—^");
	Debug::Log(NDTIME_);
	Debug::Log("•b");

	Debug::Log("HP‚ª");
	Debug::Log(Hp_);
	Debug::Log("‚É‚È‚Á‚Ä‚µ‚Ü‚Á‚½!");

	if (NDTIME_ > 0.0f)
	{
		Hp_--;
		NDTIME_ = 1.0f;
		
		if (Hp_ <= 0)
		{
			KillMe();
     	}
	}
}
