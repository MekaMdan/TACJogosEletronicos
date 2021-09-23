#include "GameObject.h"
#include <algorithm>

GameObject::GameObject(){
    isDead = false;
}

GameObject::~GameObject(){
    // Por que usar o erase quando o clear já remove tudo?
    components.clear();
}

void GameObject::Update(float dt){
    for(auto &i: components){
        i->Update(dt);
    }
}

void GameObject::Render(){
    for(auto & i: components){
        i->Render();
    }
}

bool GameObject::IsDead(){
    return IsDead;
}

void GameObject::RequestDelete(){
    isDead = true;
}

void GameObject::AddComponent(Component* cpt){
    // push_back -> cria uma copia, gasta mais memoria
    // emplace_back -> adiciona o elemento no fim 
    components.emplace_back(cpt);
}

void GameObject::RemoveComponent(Component* cpt){
    // não usar remove porque não diminui o tamanho do vetor
    // remove todas instancias de cpt
    std::remove_if(components.begin(), components.end(), cpt);
}

Component* GameObject::GetComponent(std::string type){
    // Retorna o elemento de um certo tipo
    // Nao temos função de definir o tipo ainda
    for(auto &i: components){
        if(i->Is(type)){
            return i;
        }
    }
    return nullptr;
}