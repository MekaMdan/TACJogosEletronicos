#include "GameObject.h"

GameObject::GameObject(){
    isDead = false;
}

GameObject::~GameObject(){
    // Por que usar o erase quando o clear já remove tudo?
    components.clear();
}

void GameObject::Update(float dt){

}

void GameObject::Render(){

}

bool GameObject::IsDead(){
    return IsDead;
}

void GameObject::RequestDelete(){
    isDead = true;
}

void GameObject::AddComponent(Component* cpt){

}

void GameObject::RemoveComponent(Component* cpt){

}

Component* GameObject::GetComponent(std::string type){

}