#include "glimac/Lumiere.hpp"

namespace glimac {

    Lumiere::Lumiere()
    : directional(true)
    { }

    void Lumiere::modeJourNuit(){
        if(directional){
            directional = false;
        } else {
            directional = true;
        }
    }

    void Lumiere::initLum(){

    }

    void Lumiere::ajoutPointLum(glm::vec3 position){

    }

    void Lumiere::supprPointLum(glm::vec3 position){}

}