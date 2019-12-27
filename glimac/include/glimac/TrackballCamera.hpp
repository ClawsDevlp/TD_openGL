#pragma once

#include <vector>

#include "common.hpp"

namespace glimac {

class TrackballCamera {

public:
    TrackballCamera():
        m_fDistance(5.), m_fAngleX(0.), m_fAngleY(0.) {
    }

    float getDistance() {
        return m_fDistance;
    }

    float getAngleX() {
        return m_fAngleX;
    }

    float getAngleY() {
        return m_fAngleY;
    }

    void moveFront(float delta){
      //  if(delta > 0) { 
            m_fDistance += delta; 
      //  } else 
    }

    void rotateLeft(float degrees){
        m_fAngleY += degrees;
    }

    void rotateUp(float degrees){
        m_fAngleX += degrees;
    }

    glm::mat4 getViewMatrix() const {
        glm::mat4 ViewMatrix;
        ViewMatrix = glm::translate(ViewMatrix, glm::vec3(0, 0, -m_fDistance)); // Translation
        ViewMatrix = glm::rotate(ViewMatrix, glm::radians(m_fAngleX), glm::vec3(1, 0, 0)); // Rotation
        ViewMatrix = glm::rotate(ViewMatrix, glm::radians(m_fAngleY), glm::vec3(0, 1, 0)); // Rotation
        return ViewMatrix;
    }

private:
    float m_fDistance;
    float m_fAngleX;
    float m_fAngleY;
};
    
}