//
//  Game.h
//  Game-mac
//
//  Created by fkysly-mbp14 on 2022/8/13.
//  Copyright © 2022 Sanjay Madhav. All rights reserved.
//

#pragma once
#include "SDL/SDL.h"

class Actor;
class SpriteComponent;

class Game {
public:
    Game();
    bool Initialize();
    void RunLoop();
    void Shutdown();

    void AddActor(Actor* actor);
    void RemoveActor(Actor* actor);
    void AddSprite(SpriteComponent* sprite);
    void RemoveSprite(SpriteComponent* sprite);

private:
    void ProcessInput();
    void UpdateGame();
    void GenerateOutput();
    void LoadData();
    void UnloadData();
    
    SDL_Window* mWindow;
    SDL_Renderer* mRenderer;
    bool mIsRunning;
    Uint64 mTicksCount;
};
