#include "State.h"
#include "SDL.h"

State::State(){
    quitRequested = false;
    bg = new Sprite();
}

bool State::QuitRequested(){
    return quitRequested;
}

void State::LoadAssets(){

}

void State::Update(float dt){
    if(SDL_QuitRequested()==true){
        quitRequested = true;
    }
}

void State::Render(){
    
}