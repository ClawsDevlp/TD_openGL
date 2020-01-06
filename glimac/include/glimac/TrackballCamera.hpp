#pragma once

#include <vector>

#include "common.hpp"


namespace glimac {

class TrackballCamera {

    private:
    float m_fDistance;
    float m_fAngleX;
    float m_fAngleY;

    public:
    TrackballCamera():
        m_fDistance(22.), m_fAngleX(10.), m_fAngleY(10.) {
    }

    // Setters et Getters
    float getDistance();
    float getAngleX();
    float getAngleY();

    // Mouvement avant et arriere de la camera
    void moveFront(const float delta);
    // Rotation gauche à droite de la caméra
    void rotateLeft(const float degrees);
    // Rotation haut bas de la caméra
    void rotateUp(const float degrees);
    // Obtenir la matrice de vue
    glm::mat4 getViewMatrix() const;
};
    
}