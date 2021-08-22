#include "Sprite.h"
#include "SDL_image.h"
#include "Game.h"

#include <iostream>

using namespace std;

Sprite::Sprite(){
    texture = nullptr;
}

Sprite::Sprite(string file){
    texture = nullptr;
    Open(file);
}

Sprite::~Sprite(){
    SDL_DestroyTexture(texture);
}

void Sprite::Open(string file){
    if(texture!=nullptr){
        SDL_DestroyTexture(texture);
    }
    SDL_Renderer* renderer = Game::GetInstance().GetRenderer();
    texture = IMG_LoadTexture(renderer, file.c_str());
    if(texture==nullptr){
        cout << SDL_GetError() << endl;
    }else{
        SDL_QueryTexture(texture, nullptr, nullptr, &width, &height);
        SetClip(0,0,width, height);
    }

}

void Sprite::SetClip(int x, int y, int w, int h){
    clipRect.h=h;
    clipRect.w=w;
    clipRect.x=x;
    clipRect.y=y;
}

void Sprite::Render(int x, int y){
    SDL_Renderer* renderer = Game::GetInstance().GetRenderer();
    SDL_Rect* dstrect = new SDL_Rect();
    dstrect->x=x;
    dstrect->y=y;
    dstrect->w=clipRect.w;
    dstrect->h=clipRect.h;
    SDL_RenderCopy(renderer, texture, &clipRect, dstrect);
}

int Sprite::GetWidth(){
    return width;
}

int Sprite::GetHeight(){
    return height;
}

bool Sprite::IsOpen(){
    if(texture!=nullptr){
        return true;
    }
    else return false;
}