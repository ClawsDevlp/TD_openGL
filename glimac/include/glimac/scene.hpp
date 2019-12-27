#pragma once


#include "common.hpp"
#include "GestionCube.hpp"
#include <vector>
#include <iostream>


namespace glimac {

class Scene {

public:

     //GestionCube sceneCube;
     //glm::vec3 Scenecoord;

     Scene() = default;
     ~Scene() = default;

     void sceneInit(GestionCube* ActualGerant);
     //void dessinScene();
};
    
}