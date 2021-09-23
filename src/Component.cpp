#include "Component.h"
#include "GameObject.h"

// Inicializa associated com o valor associated passado nos parametros
// seria igual a dizer associated(da classe) = associated(parametro)
Component::Component(GameObject& associated) : associated(associated){

}

Component::~Component(){
    
}