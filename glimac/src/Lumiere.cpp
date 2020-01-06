#include "glimac/Lumiere.hpp"

namespace glimac {

    Lumiere::Lumiere()
    : directional(true)
    { }

    int Lumiere::getDirectional(){
        return directional;
    }
    int Lumiere::getNbPoint(){
        return nbPoint;
    }
    glm::vec3 Lumiere::getPointsPositions(int index){
        return pointsPositions[index];
    }

    void Lumiere::modeJourNuit(){
        if(directional){
            directional = false;
        } else {
            directional = true;
        }
    }

    int Lumiere::trouvePoint(glm::vec3 position){
        for( int i = 0; i < pointsPositions.size(); ++i ){
            if( pointsPositions[i] == position ){
                return i;
            }
        }
        return -1;
    }

    void Lumiere::ajoutPointLum(glm::vec3 position){
        if(trouvePoint(position) == -1){
            pointsPositions.push_back(position);
            nbPoint++;
        } else {
            std::cout << "Lumière deja posée ici" << std::endl;
        }
    }

    void Lumiere::supprPointLum(glm::vec3 position){
        int index = trouvePoint(position);

        if( index != -1 ){
            // Supression du cube dans position
            pointsPositions.erase(pointsPositions.begin() + index);
            nbPoint--;
        }
    }

}