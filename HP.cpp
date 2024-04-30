#include "HP.h"
#include "Player.h"
#include "Engine/Image.h"
#include "Engine/Debug.h"


HP::HP(GameObject* parent)
	:GameObject(parent, "HP"),hImage_(-1),bagImage_(-1)
{
	
}

void HP::Initialize()
{
}

void HP::Update()
{
    bagImage_ = Image::Load("Image/BackImage.png");
    assert(bagImage_ >= 0);

    transform_.scale_ = XMFLOAT3(0.9, 0.9, 0.9);

	hImage_ = Image::Load("Image/HP.png");
    assert(hImage_ >= 0);

	transform_.position_ = XMFLOAT3(-0.85, 0.88, 0);
}

void HP::DamageHp()
{
    if (Wide_ > 0) {

        Wide_--;

    }

  /*  Debug::Log("‰æ‘œ‚ª");
    Debug::Log(Wide_);
    Debug::Log("–‡Œ¸‚é");*/
}

void HP::Draw()
{
    Image::SetTransform(bagImage_, transform_);
    Image::Draw(bagImage_);

    float heartWidth = 0.13;

    for (int i = 0; i < Wide_; i++)
    {
        if (Wide_ > 0) {
            transform_.position_.x = -0.9 + i * heartWidth;
            Image::SetTransform(hImage_, transform_);
            Image::Draw(hImage_);
        }
    }
   /* Debug::Log(Wide_);*/
}


void HP::Release()
{

}


