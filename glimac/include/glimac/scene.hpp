#pragma once


#include "common.hpp"
#include "GestionCube.hpp"
#include "rbf.hpp"
#include <fstream> 
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

          // Initialise scene plate
          void sceneInit(GestionCube* ActualGerant);
          // Supprime scene plate
          void suppSceneInit(GestionCube* ActualGerant);
          // Charge scene générée par rbf
          void loadRBFscene(GestionCube* ActualGerant);
          // Sauvegarde la scene en cours
          void saveScene(GestionCube* ActualGerant);
          // Sauvegarde les positions des cubes dans un fichier
          void savePositions(GestionCube* ActualGerant);
          // Sauvegarde les couleurs des cubes dans un fichier
          void saveColors(GestionCube* ActualGerant);
          // Charge la derniere scene enregistrée dans les deux fichiers
          void chargeScene(GestionCube* ActualGerant);
     };
    
}