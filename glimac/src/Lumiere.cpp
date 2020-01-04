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

    int Lumiere::trouvePoint(glm::vec3 position){
        for( int k = 0; k < pointsPositions.size(); ++k){
            if( glm::length(position-pointsPositions[k]) < 0.1f){
                return k;
            }
        }
        return -1; // si on ne l'a pas trouvé
    }

    void Lumiere::ajoutPointLum(glm::vec3 position){
        supprPointLum(position);
        pointsPositions.push_back(position);
        nbPoint++;
    }

    void Lumiere::supprPointLum(glm::vec3 position){
        int index = trouvePoint(position);

        if( index != -1 ){
            int lastIndex = pointsPositions.size() - 1;

            // Supression du cube dans position
            std::swap(pointsPositions[index], pointsPositions[lastIndex]);
            pointsPositions.pop_back();
            nbPoint--;
        }
    }

}