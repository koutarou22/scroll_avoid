#include "Road.h"
#include "Engine/Model.h"
#include "Engine/Camera.h"

Road::Road(GameObject* parent)
{
}

void Road::Initialize()
{
    hModel_ = Model::Load("Floor.fbx");
    assert(hModel_ >= 0);

    Camera::SetPosition({ 0.5, 1.5,-2.5 });
    Camera::SetTarget({ 0.5, 1, 0 });

}

void Road::Update()
{
    RoadWidth_ = 3;
    RoadHight_ = 90;
}

void Road::Draw()
{
    for (int z = 0; z < RoadHight_; z++)
    { 
        for (int x = 0; x < RoadWidth_; x++)
        {

            transform_.position_.x = x;
            transform_.position_.z = z;
           
           Model::SetTransform(hModel_, transform_);
           Model::Draw(hModel_);
        }
    }
}

void Road::Release()
{
}
