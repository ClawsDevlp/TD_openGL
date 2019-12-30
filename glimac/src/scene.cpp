#include "glimac/scene.hpp"

namespace glimac {

    //glm::vec3 Scenecoord = (0.);
    /* 
    void Scene::sceneInit(){
     	for (int y = 0; y < 1; ++y){
            for (int x = 0; x < 3; ++x){
                for (int z = 0; z < 3; ++z){
                    sceneCube.ajoutCube(glm::vec3(x,y-1,z));
                }
            }
        }
    } */

void Scene::sceneInit(GestionCube* ActualGerant){
    for (int y = 0; y < 1; ++y){
        for (int x = 0; x < 11; ++x){
            for (int z = 0; z < 21; ++z){
                if (z<=10){
                    ActualGerant->ajoutCube(glm::vec3(-x,y-1,-z), glm::vec3(0,0,0));
                } else {
                    ActualGerant->ajoutCube(glm::vec3(-x,y-1,z-10), glm::vec3(0,0,0));
                } 
            } 
        }
    }

    for (int y = 0; y < 1; ++y){
        for (int x = 1; x < 11; ++x){
            for (int z = 0; z < 21; ++z){
                if (z<=10){
                    ActualGerant->ajoutCube(glm::vec3(x,y-1,-z), glm::vec3(0,0,0));
                } else {
                    ActualGerant->ajoutCube(glm::vec3(x,y-1,z-10), glm::vec3(0,0,0));
                } 
            } 
        }
    }
}


    /*     void Scene::dessinScene(GestionCube ActualGerant){
        ActualGerant.dessinCube();
    } */
}
