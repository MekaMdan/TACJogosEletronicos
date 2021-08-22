#include "SDL_image.h"
#include "SDL_mixer.h"
#include <chrono>

#include <string>
#include <iostream>

#include "Game.h"

using namespace std;

Game* Game::instance = nullptr;

Game& Game::GetInstance(){
    if(instance!=nullptr){
        // JA EXISTE
        return *instance;
    }else{
        new Game("Mariana Alencar - 160014522", WIDTH, HEIGHT);
        return *instance;
    }
}

Game::Game(string title, int width, int height) {
    if(instance != nullptr){
        // Caso ja exista uma instancia

    }else{    
        instance = this; 
        int sdl_returnvalue = SDL_Init(SDL_INIT_VIDEO|SDL_INIT_AUDIO|SDL_INIT_TIMER);
        
        if(sdl_returnvalue!=0){
            // Caso haja erro ao inicializar o SDL_Init
        }else{
            IMG_Init(IMG_INIT_JPG | IMG_INIT_PNG | IMG_INIT_TIF);
            Mix_Init(MIX_INIT_OGG);
            window = SDL_CreateWindow(
                title.c_str(),
                SDL_WINDOWPOS_CENTERED,
                SDL_WINDOWPOS_CENTERED,
                width,
                height,
                0);
            renderer = SDL_CreateRenderer(
                window,
                -1,
                SDL_RENDERER_ACCELERATED);
            state = new State();
        }
    }
}

Game::~Game(){
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    Mix_CloseAudio();
    Mix_Quit();
    IMG_Quit();
    SDL_Quit();
}

State& Game::GetState(){
     return *state;
}

SDL_Renderer* Game::GetRenderer(){
    return renderer;
}

void Game::Run(){
    state->LoadAssets();
    while (!state->QuitRequested()){
        state->Update(0.0);
        state->Render();
        SDL_RenderPresent(renderer);
        SDL_Delay(33);
    }
}