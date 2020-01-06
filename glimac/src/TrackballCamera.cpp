#include "glimac/TrackballCamera.hpp"

namespace glimac {

    float TrackballCamera::getDistance() {
        return m_fDistance;
    }

    float TrackballCamera::getAngleX() {
        return m_fAngleX;
    }

    float TrackballCamera::getAngleY() {
        return m_fAngleY;
    }

    void TrackballCamera::moveFront(const float delta){
      //  if(delta > 0) { 
            m_fDistance += delta; 
      //  } else 
    }

    void TrackballCamera::rotateLeft(const float degrees){
        m_fAngleY += degrees;
    }

    void TrackballCamera::rotateUp(const float degrees){
        m_fAngleX += degrees;
    }

    glm::mat4 TrackballCamera::getViewMatrix() const {
        glm::mat4 ViewMatrix;
        ViewMatrix = glm::translate(ViewMatrix, glm::vec3(0, 0, -m_fDistance)); // Translation
        ViewMatrix = glm::rotate(ViewMatrix, glm::radians(m_fAngleX), glm::vec3(1, 0, 0)); // Rotation
        ViewMatrix = glm::rotate(ViewMatrix, glm::radians(m_fAngleY), glm::vec3(0, 1, 0)); // Rotation
        return ViewMatrix;
    }
}