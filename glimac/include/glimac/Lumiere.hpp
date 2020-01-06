#pragma once

#include "common.hpp"
#include <vector>
#include <iostream>

namespace glimac {

    class Lumiere {

        private:
        bool directional; // mode jour-nuit
        int nbPoint;

        public:
        std::vector<glm::vec3> pointsPositions;
        Lumiere();
        ~Lumiere() = default;

        // Getters et Setters
        int getNbPoint();
        int getDirectional();
        glm::vec3 getPointsPositions(int index);

        void modeJourNuit();
        int trouvePoint(glm::vec3 position);
        void ajoutPointLum(glm::vec3 position);
        void supprPointLum(glm::vec3 position);
    
        friend class Reglages;
    };
}