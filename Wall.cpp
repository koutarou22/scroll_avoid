#include "Wall.h"
#include "Engine/Model.h"

Wall::Wall(GameObject* parent)
    :GameObject(parent, "Wall"), hModel_(-1)
{
    WallRoad_ = 80;
    WallHigh_ = 2;
    //WallWide_ = 2;
    //Space_ = 2;
}

void Wall::Initialize()
{
    hModel_ = Model::Load("Model/box.fbx");
    assert(hModel_ >= 0);

    transform_.scale_ = XMFLOAT3(0.2f, 1.7f, 2.0f);
    transform_.position_ = XMFLOAT3(-1.1, 2.5, 0.7);
}

void Wall::Update()
{
}

void Wall::Draw()
{
    for (int y = 0; y < WallHigh_; y++)
    {
        for (int z = 0; z <  WallRoad_; z++)
        {
            transform_.position_.z = z;
            transform_.position_.y = y;

            Model::SetTransform(hModel_, transform_);
            Model::Draw(hModel_);
        }
    }
}

void Wall::Release()
{
}
