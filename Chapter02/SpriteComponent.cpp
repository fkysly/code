//
//  SpriteComponent.cpp
//  Game-mac
//
//  Created by fkysly-mbp14 on 2022/8/13.
//  Copyright © 2022 Sanjay Madhav. All rights reserved.
//

#include "SpriteComponent.hpp"
#include "Actor.hpp"
#include "Game.h"
#include "Math.h"

SpriteComponent::SpriteComponent(Actor *owner, int drawOrder)
        : Component(owner, drawOrder), mDrawOrder(drawOrder), mTexture(nullptr), mTexWidth(0), mTexHeight(0) {
    mOwner->GetGame()->AddSprite(this);
}

SpriteComponent::~SpriteComponent() {
    mOwner->GetGame()->RemoveSprite(this);
}

void SpriteComponent::SetTexture(SDL_Texture *texture) {
    mTexture = texture;
    SDL_QueryTexture(texture, nullptr, nullptr, &mTexWidth, &mTexHeight);
}

void SpriteComponent::Draw(SDL_Renderer *renderer) {
    SDL_Rect dstrect;
    dstrect.w = static_cast<int>(mTexWidth * mOwner->GetScale());
    dstrect.h = static_cast<int>(mTexHeight * mOwner->GetScale());

    dstrect.x = static_cast<int>(mOwner->GetPosition().x - dstrect.w / 2);
    dstrect.y = static_cast<int>(mOwner->GetPosition().y - dstrect.h / 2);

    SDL_RenderCopyEx(renderer, mTexture, nullptr, &dstrect, -Math::ToDegrees(mOwner->GetRotation()), nullptr, SDL_FLIP_NONE);
}
