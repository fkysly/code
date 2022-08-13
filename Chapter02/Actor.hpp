//
//  Actor.hpp
//  Game-mac
//
//  Created by fkysly-mbp14 on 2022/8/13.
//  Copyright © 2022 Sanjay Madhav. All rights reserved.
//

#pragma once

class Game;
class Component;

class Actor {
public:
    Actor(Game* game);
    ~Actor();
    
    void AddComponent(Component* component);
    void RemoveComponent(Component* component);
};
