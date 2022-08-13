//
//  SpriteComponent.hpp
//  Game-mac
//
//  Created by fkysly-mbp14 on 2022/8/13.
//  Copyright © 2022 Sanjay Madhav. All rights reserved.
//

#pragma once

#include "SDL/SDL.h"
#include "Component.hpp"

class Actor;

class SpriteComponent : public Component {
public:
    SpriteComponent(Actor *owner, int drawOrder);

    ~SpriteComponent();

    virtual void Draw(SDL_Renderer* renderer);

    virtual void SetTexture(SDL_Texture *texture);

    int GetDrawOrder() const {
        return mDrawOrder;
    };

    int GetTexWidth() const {
        return mTexWidth;
    };

    int GetTextHeight() const {
        return mTexHeight;
    };

protected:
    SDL_Texture *mTexture;
    int mTexWidth;
    int mTexHeight;
    int mDrawOrder;
};