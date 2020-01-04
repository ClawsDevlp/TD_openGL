#pragma once

#include "common.hpp"
#include <vector>
#include <iostream>

namespace glimac {

    class Lumiere {

        public:

        Lumiere();
        ~Lumiere() = default;

        bool directional; // mode jour / nuit
        int nbPoint;
        std::vector<glm::vec3> pointsPositions;

        void modeJourNuit();
        int trouvePoint(glm::vec3 position);
        void ajoutPointLum(glm::vec3 position);
        void supprPointLum(glm::vec3 position);
    
    };
}