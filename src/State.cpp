#include "State.h"
#include "SDL.h"

State::State():bg(),music(){
    quitRequested = false;
}

bool State::QuitRequested(){
    return quitRequested;
}

void State::LoadAssets(){
    bg.Open("./assets/img/ocean.jpg");
    music.Open("./assets/audio/stageState.ogg");
    music.Play();
}

void State::Update(float dt){
    if(SDL_QuitRequested()==true){
        quitRequested = true;
    }
}

void State::Render(){
    bg.Render(0,0);
}