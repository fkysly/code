//
//  Game.cpp
//  Game-mac
//
//  Created by fkysly-mbp14 on 2022/8/13.
//  Copyright © 2022 Sanjay Madhav. All rights reserved.
//

#include "Game.h"
#include "SDL/SDL_image.h"

Game::Game()
    :mWindow(nullptr)
    ,mRenderer(nullptr)
    ,mIsRunning(true)
    ,mTicksCount(0)
{
    
}

bool Game::Initialize() {
    if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO)) {
        SDL_Log("sdl cannot init: %s", SDL_GetError());
        return false;
    }
    
    mWindow = SDL_CreateWindow("Chapter2", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1024, 768, 0);
    if (!mWindow) {
        SDL_Log("sdl cannot create window: %s", SDL_GetError());
        return false;
    }
    
    mRenderer = SDL_CreateRenderer(mWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if (!mRenderer) {
        SDL_Log("sdl cannot create renderer: %s", SDL_GetError());
        return false;
    }
    
    mTicksCount = SDL_GetTicks64();
    
    LoadData();
    
    return true;
}

void Game::LoadData() {
}

void Game::UnloadData() {
    
}

void Game::RunLoop() {
    while (mIsRunning) {
        ProcessInput();
        UpdateGame();
        GenerateOutput();
    }
}

void Game::Shutdown() {
    UnloadData();
    SDL_DestroyRenderer(mRenderer);
    SDL_DestroyWindow(mWindow);
    SDL_Quit();
}

void Game::ProcessInput() {
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
        switch (event.type) {
            case SDL_QUIT:
                mIsRunning = false;
                break;
        }
    }
    
    
    const Uint8* state = SDL_GetKeyboardState(NULL);
    
    if (state[SDL_SCANCODE_ESCAPE]) {
        mIsRunning = false;
    }
}

void Game::UpdateGame() {
    while (!SDL_TICKS_PASSED(SDL_GetTicks64(), mTicksCount + 16)) {
        ;
    }
    float deltaTime = mTicksCount - SDL_GetTicks64();
    if (deltaTime > 0.05f) deltaTime = 0.05f;
    mTicksCount = SDL_GetTicks64();
    
    
}

void Game::GenerateOutput() {
    SDL_SetRenderDrawColor(mRenderer, 0, 0, 0, 1);
    SDL_RenderClear(mRenderer);
    
    
    SDL_RenderPresent(mRenderer);
}
