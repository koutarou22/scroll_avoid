#include "GoalUI.h"
#include "Engine/Image.h"
#include "Engine/Debug.h"
#include "Engine/Input.h"

GoalUI::GoalUI(GameObject* parent)
    :GameObject(parent,"GoalUI"),hLimit_(-1),hFrame_(-1), Limitnow_(100), MaxLimit_(100)
{
}

void GoalUI::Initialize()
{

	hFrame_ = Image::Load("Image/BackImage2.png");
	assert(hFrame_ >= 0);

	hLimit_ = Image::Load("Image/ClearLimit.png");
	assert(hLimit_ >= 0);

	transform_.position_ = XMFLOAT3(0.9, 0.2, 0);
	
	tr.position_ = XMFLOAT3(0.9, -0.5, 0);
	tr.scale_ = XMFLOAT3(3, 3.5, 3);

	Timer_ = 0;
}

void GoalUI::Update()
{
}

void GoalUI::Draw()
{
	Timer_ ++;

	Debug::Log(Timer_);

	tr.scale_.y -= 0.003;
	
	Image::SetTransform(hFrame_, transform_);
	Image::Draw(hFrame_);

	Image::SetTransform(hLimit_, tr);
	Image::Draw(hLimit_);
}

void GoalUI::Release()
{
}
