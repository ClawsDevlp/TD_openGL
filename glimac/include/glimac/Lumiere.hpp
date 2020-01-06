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
        glm::vec3 getPointsPositions(const int index);

        // Mode jour ou nuit
        void modeJourNuit();
        // Trouve l'indice du point dans pointsPositions à la position donnée
        int trouvePoint(const glm::vec3 position);
        // Ajoute un point dans pointsPositions
        void ajoutPointLum(const glm::vec3 position);
        // Supprime un point dans pointsPositions
        void supprPointLum(const glm::vec3 position);
    };
}