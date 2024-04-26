#include "Player.h"
#include "Hp.h"
#include "Engine/Model.h"
#include "Engine/Input.h"
#include "Engine/SceneManager.h"
#include "Engine/SphereCollider.h"
#include "Engine/Debug.h"
#include "Engine/Camera.h"

Player::Player(GameObject* parent)
	:GameObject(parent, "Player"), hModel_(-1)
{
	
}

void Player::Initialize()
{
	hModel_ = Model::Load("Model/Player.fbx");
	assert(hModel_ >= 0);

	transform_.position_ = XMFLOAT3(0.5, 0.05, 1.5);
	transform_.scale_ = XMFLOAT3(1.0, 1.0, 1.0);

	SphereCollider* collision = new SphereCollider({ 0, 0.5, 0 }, 0.2f);
	AddCollider(collision);

	Hp_ = 10;//HP
	NDTIME_ = 1.0f;//無敵時間

	Camera::SetPosition({ 0.5, 2.5,-1.5 });
	Camera::SetTarget({ 0.5, 2, 0 });
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

	if (NDTIME_ > 0.0f)
	{
		NDTIME_ -= 0.5;
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
	HP* hp = (HP*)FindObject("HP");

	Debug::Log("残りHP=");
	Debug::Log(Hp_);

	Camera::SetTarget({ 0.5, 2, 0 });

	if (NDTIME_ <= 0.0f)
	{
		Camera::SetTarget({ 0.53, 1.94, 0 });

		hp->DamageHp();
		Hp_--;
		NDTIME_ = 1.0f;//ここでリセット

		if (Hp_ <= 0)
		{
			KillMe();
		}
	}
}
