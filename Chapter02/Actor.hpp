//
//  Actor.hpp
//  Game-mac
//
//  Created by fkysly-mbp14 on 2022/8/13.
//  Copyright © 2022 Sanjay Madhav. All rights reserved.
//

#pragma once

#include "math.h"

class Game;
class Component;

class Actor {
public:
    Actor(Game* game);
    ~Actor();
    
    void AddComponent(Component* component);
    void RemoveComponent(Component* component);
    Game* GetGame();
    const Vector2& GetPosition() const {
        return mPosition;};
    void SetPosition(const Vector2& position) {mPosition = position;};
    float GetScale() const {return mScale;};
    void SetScale(float scale) {mScale = scale;};
    float GetRotation() const {return mRotation;};
    void SetRotation(float rotation) {mRotation = rotation;};

private:
    Game* mGame;
    Vector2 mPosition;
    float mScale;
    float mRotation;
};
