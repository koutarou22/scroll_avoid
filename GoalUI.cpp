#include "GoalUI.h"
#include "Engine/Image.h"

GoalUI::GoalUI(GameObject* parent)
    :GameObject(parent,"GoalUI"),hLimit_(-1),hFrame_(-1)
{
}

void GoalUI::Initialize()
{

	hFrame_ = Image::Load("Image/BackImage2.png");
	assert(hFrame_ >= 0);

	hLimit_ = Image::Load("Image/ClearLimit.png");
	assert(hLimit_ >= 0);

	transform_.position_ = XMFLOAT3(0.9, 0.2, 0);
	
}

void GoalUI::Update()
{
}

void GoalUI::Draw()
{
	//Transform tr = transform_;
	//float scale = (float)Limitnow_ / (float) MaxLimit_;

	//tr.scale_.y = scale;
	//tr.position_.y = transform_.position_.y - (transform_.scale_.y * (1.0f - scale) / 5.0f);


	Image::SetTransform(hFrame_, transform_);
	Image::Draw(hFrame_);

	Image::SetTransform(hLimit_, transform_);
	Image::Draw(hLimit_);
}

void GoalUI::Release()
{
}
