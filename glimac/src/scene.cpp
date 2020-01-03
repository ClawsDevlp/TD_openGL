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
        for (int x = 0; x < (SCENE_DIM/2)+1; ++x){
            for (int z = 0; z < SCENE_DIM+1; ++z){
                if (z<=10){
                    ActualGerant->ajoutCube(glm::vec3(-x,y-1,-z), glm::vec3(0,1,0));
                } else {
                    ActualGerant->ajoutCube(glm::vec3(-x,y-1,z-(SCENE_DIM/2)), glm::vec3(0,1,0));
                } 
            } 
        }
        for (int x = 1; x < (SCENE_DIM/2)+1; ++x){
            for (int z = 0; z < SCENE_DIM+1; ++z){
                if (z<=(SCENE_DIM/2)){
                    ActualGerant->ajoutCube(glm::vec3(x,y-1,-z), glm::vec3(0,1,0));
                } else {
                    ActualGerant->ajoutCube(glm::vec3(x,y-1,z-(SCENE_DIM/2)), glm::vec3(0,1,0));
                } 
            } 
        }
    }
}

void Scene::loadRBFscene(GestionCube* ActualGerant){
     const int nbPoints = 3;
     Eigen::MatrixXd map = Eigen::MatrixXd::Zero(21,21);
     Eigen::MatrixXf ptsDeControle(nbPoints, 2);
     ptsDeControle << 10, 10, 2, 3, 0, -8;
     Eigen::VectorXf valeurs(nbPoints);
     valeurs << 10, -2, -10;

     map = getMap(ptsDeControle, valeurs);

     for (int x = 0; x < 21; x++){
        for (int z = 0; z < 21; z++){
            for (int y = -20; y < map(x,z); y++){
                ActualGerant->ajoutCube(glm::vec3(x-(SCENE_DIM/2),y,z-(SCENE_DIM/2)), glm::vec3(0,1,0));
            }
        }
     }
}

    /*     void Scene::dessinScene(GestionCube ActualGerant){
        ActualGerant.dessinCube();
    } */
}
