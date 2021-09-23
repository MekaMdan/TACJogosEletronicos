#include <iostream>
#include "Sound.h"



Sound::Sound(GameObject& associated) : Component(associated){
    chunk = nullptr;
}

Sound::Sound(GameObject& associated, std::string file): Component(associated){
    chunk = nullptr;
    Open(file);
}

Sound::~Sound(){
    if(IsOpen()){
        Stop();
        Mix_FreeChunk(chunk);
    }
}

void Sound::Play(int times){
    channel = Mix_PlayChannel(-1, chunk, times);
}

void Sound::Stop(){
    if(chunk==nullptr){
        std::cout<< SDL_GetError() << std::endl;
    }else{
       Mix_HaltChannel(channel); 
    }
    
}

void Sound::Open(std::string file){  
    chunk = Mix_LoadWAV(file.c_str());
    if(chunk==nullptr){
        std::cout<< SDL_GetError() << std::endl;
    }

    
}

bool Sound::IsOpen(){
    if(chunk!=nullptr){
       return true; 
    }
    return false;
}

void Sound::Update(float dt){

}

void Sound::Render(){

}

bool Sound::Is(std::string type){
    return "Sound" == type;
}