#include "HP.h"
#include "Player.h"
#include "Engine/Image.h"
#include "Engine/Debug.h"


HP::HP(GameObject* parent)
	:GameObject(parent, "HP")
{
	
}

void HP::Initialize()
{
}

void HP::Update()
{
	hImage_ = Image::Load("HP.png");
	assert(hImage_ >= 0);

	transform_.position_ = XMFLOAT3(-0.9, 0.87, 0);
}

void HP::DamageHp()
{
    if (Wide_ > 0) {

        Wide_--;

    }
    Debug::Log(Wide_);
}

void HP::Draw()
{
    float heartWidth = 0.13;

    for (int i = 0; i < Wide_; i++)
    {
        if (Wide_ > 0) {
            transform_.position_.x = -0.9 + i * heartWidth;
            Image::SetTransform(hImage_, transform_);
            Image::Draw(hImage_);
        }
    }
    Debug::Log(Wide_);
}


void HP::Release()
{

}


