#include "HP.h"
#include "Engine/Image.h"


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

void HP::Draw()
{
	Image::SetTransform(hImage_, transform_);
	Image::Draw(hImage_);
}

void HP::Release()
{
}
