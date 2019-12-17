#pragma once

#include <vector>

#include "common.hpp"

namespace glimac {

    // Structure pour les coordonnées couleurs / positions
    struct Vertex3DColor
    {
            glm::vec3 position;
            glm::vec3 color;
            // Constructeur
            Vertex3DColor() = default;
            Vertex3DColor(glm::vec3 position, glm::vec3 color);
    };

    Vertex3DColor::Vertex3DColor(glm::vec3 position, glm::vec3 color){
        this->position = position;
        this->color = color;
    };
    /*
class Cube {

    public:

    Cube() {
        
    }

    void afficheCube() {
        coordonnees[] = {
            // face devant
            Vertex3DColor(glm::vec3(-0.5, 0.5, 0.0), glm::vec3(0, 1, 0)),
            Vertex3DColor(glm::vec3(0.5, 0.5, 0.0), glm::vec3(1, 0, 0)),
            Vertex3DColor(glm::vec3(-0.5, -0.5, 0.0), glm::vec3(0, 0, 1)),
            Vertex3DColor(glm::vec3(0.5, -0.5, 0.0), glm::vec3(0, 1, 0)),
            Vertex3DColor(glm::vec3(0.5, 0.5, 0.0), glm::vec3(1, 0, 0)),
            Vertex3DColor(glm::vec3(-0.5, -0.5, 0.0), glm::vec3(0, 0, 1)),

            //face coté gauche
            Vertex3DColor(glm::vec3(-0.5, 0.5, 0.0), glm::vec3(0, 1, 0)),
            Vertex3DColor(glm::vec3(-0.5, -0.5, 0.0), glm::vec3(1, 0, 0)),
            Vertex3DColor(glm::vec3(-0.5, -0.5, -1.0), glm::vec3(0, 0, 1)),
            Vertex3DColor(glm::vec3(-0.5, 0.5, 0.0), glm::vec3(0, 1, 0)),
            Vertex3DColor(glm::vec3(-0.5, 0.5, -1.0), glm::vec3(1, 0, 0)),
            Vertex3DColor(glm::vec3(-0.5, -0.5, -1.0), glm::vec3(0, 0, 1)),

            //face coté droite
            Vertex3DColor(glm::vec3(0.5, 0.5, 0.0), glm::vec3(0, 1, 0)),
            Vertex3DColor(glm::vec3(0.5, -0.5, 0.0), glm::vec3(1, 0, 0)),
            Vertex3DColor(glm::vec3(0.5, -0.5, -1.0), glm::vec3(0, 0, 1)),
            Vertex3DColor(glm::vec3(0.5, 0.5, 0.0), glm::vec3(0, 1, 0)),
            Vertex3DColor(glm::vec3(0.5, 0.5, -1.0), glm::vec3(1, 0, 0)),
            Vertex3DColor(glm::vec3(0.5, -0.5, -1.0), glm::vec3(0, 0, 1)),

            //face dessous
            Vertex3DColor(glm::vec3(-0.5, -0.5, 0.0), glm::vec3(0, 1, 0)),
            Vertex3DColor(glm::vec3(0.5, -0.5, 0.0), glm::vec3(1, 0, 0)),
            Vertex3DColor(glm::vec3(-0.5, -0.5, -1.0), glm::vec3(0, 0, 1)),
            Vertex3DColor(glm::vec3(0.5, -0.5, 0.0), glm::vec3(0, 1, 0)),
            Vertex3DColor(glm::vec3(0.5, -0.5, -1.0), glm::vec3(1, 0, 0)),
            Vertex3DColor(glm::vec3(-0.5, -0.5, -1.0), glm::vec3(0, 0, 1)),

            //face dessus
            Vertex3DColor(glm::vec3(-0.5, 0.5, 0.0), glm::vec3(0, 1, 0)),
            Vertex3DColor(glm::vec3(0.5, 0.5, 0.0), glm::vec3(1, 0, 0)),
            Vertex3DColor(glm::vec3(0.5, 0.5, -1.0), glm::vec3(0, 0, 1)),
            Vertex3DColor(glm::vec3(-0.5, 0.5, 0.0), glm::vec3(0, 1, 0)),
            Vertex3DColor(glm::vec3(-0.5, 0.5, -1.0), glm::vec3(1, 0, 0)),
            Vertex3DColor(glm::vec3(0.5, 0.5, -1.0), glm::vec3(0, 0, 1)),

            //face derrière
            Vertex3DColor(glm::vec3(-0.5, -0.5, -1.0), glm::vec3(0, 1, 0)),
            Vertex3DColor(glm::vec3(-0.5, 0.5, -1.0), glm::vec3(1, 0, 0)),
            Vertex3DColor(glm::vec3(0.5, 0.5, -1.0), glm::vec3(0, 0, 1)),
            Vertex3DColor(glm::vec3(-0.5, -0.5, -1.0), glm::vec3(0, 1, 0)),
            Vertex3DColor(glm::vec3(0.5, -0.5, -1.0), glm::vec3(1, 0, 0)),
            Vertex3DColor(glm::vec3(0.5, 0.5, -1.0), glm::vec3(0, 0, 1))
        };

        nbCoordonnees = 36;
    }

    Vertex3DColor getCoord(){
        return coordonnees;
    }
    
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
    
        Vertex3DColor coordonnees[];

        int nbCoordonnees;
    };
    
}*/
}