#include "Music.h"
#include <iostream>

Music::Music(){
    music = nullptr;
}

Music::Music(string file){
    music = nullptr;
    Open(file);
}

Music::~Music(){
    Stop();
    Mix_FreeMusic(music);
}

void Music::Play(int times){
    Mix_PlayMusic(music,times);
}

void Music::Stop(int msToStop){
    Mix_FadeOutMusic(msToStop);
}

void Music::Open(string file){
    if(music!=nullptr){
        Mix_FreeMusic(music);
    }
    music = Mix_LoadMUS(file.c_str());
    if(music==nullptr){
        cout << SDL_GetError() << endl;
    }else{
    }
    
}

bool Music::IsOpen(){
    if(music!=nullptr){
        return true;
    }
    else return false;
}