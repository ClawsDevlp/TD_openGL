#pragma once


#include "common.hpp"
#include "GestionCube.hpp"
#include "rbf.hpp"
#include <vector>
#include <iostream>

namespace glimac {

     const int SCENE_DIM = 20;
     
class Scene {

public:

     //GestionCube sceneCube;
     //glm::vec3 Scenecoord;

     Scene() = default;
     ~Scene() = default;

     void sceneInit(GestionCube* ActualGerant);
     //void dessinScene();
     void loadRBFscene(GestionCube* ActualGerant);
};
    
}