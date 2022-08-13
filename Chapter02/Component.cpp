//
//  Component.cpp
//  Game-mac
//
//  Created by fkysly-mbp14 on 2022/8/13.
//  Copyright © 2022 Sanjay Madhav. All rights reserved.
//

#include "Component.hpp"
#include "Actor.hpp"

Component::Component(Actor* owner, int updateOrder)
    :mOwner(owner)
    ,mUpdateOrder(updateOrder)
{
    owner->AddComponent(this);
}

Component::~Component() {
    mOwner->RemoveComponent(this);
}

void Component::Update(float deltaTime) {
    
}

