#include "Gauge.h"
#include "Engine/Image.h"
#include "Engine/Debug.h"

Gauge::Gauge(GameObject* parent)
    :GameObject(parent, "Gauge"), hLimit_(-1)
{
}

void Gauge::Initialize()
{
	hLimit_ = Image::Load("Image/ClearLimit.png");
	assert(hLimit_ >= 0);

	transform_.position_ = XMFLOAT3(0.9, -0.56, 0);
	transform_.scale_ = XMFLOAT3(3, 3.5, 3);
}

void Gauge::Update()
{
}

void Gauge::Draw()
{
	transform_.scale_.y -= 0.003;

	if (transform_.scale_.y < 0.05)
	{
		transform_.scale_.y = 0.05;

		if (transform_.scale_.y = 0.05)
		{
			KillMe();
			Debug::Log("Á–Å");
		}
	}

	Debug::Log("w");
	Debug::Log(transform_.scale_.y);
	Debug::Log("x");

	Image::SetTransform(hLimit_, transform_);
	Image::Draw(hLimit_);
}

void Gauge::Release()
{
}
