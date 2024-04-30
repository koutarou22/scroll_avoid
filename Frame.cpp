#include "Frame.h"
#include "Engine/Image.h"
#include "Engine/Debug.h"
#include "Engine/Input.h"

Frame::Frame(GameObject* parent)
    :GameObject(parent,"Frame"),hFrame_(-1)
{
}

void Frame::Initialize()
{
	hFrame_ = Image::Load("Image/BackImage3.png");
	assert(hFrame_ >= 0);

	transform_.scale_ = XMFLOAT3(1, 1.5, 0);
	transform_.position_ = XMFLOAT3(0.9, 0.1, 0);
}

void Frame::Update()
{
	
}

void Frame::Draw()
{
	Image::SetTransform(hFrame_, transform_);
	Image::Draw(hFrame_);
}

void Frame::Release()
{
}
