//
//  Component.hpp
//  Game-mac
//
//  Created by fkysly-mbp14 on 2022/8/13.
//  Copyright © 2022 Sanjay Madhav. All rights reserved.
//

#pragma once

class Actor;

class Component {
    
public:
    Component(Actor* owner, int updateOrder = 100);
    virtual ~Component();
    virtual void Update(float deltaTime);
    
    int getUpdateOrder() const { return mUpdateOrder; }
private:
    Actor* mOwner;
    int mUpdateOrder;
};
