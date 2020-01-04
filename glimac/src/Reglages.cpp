#include "glimac/Reglages.hpp"

namespace glimac {

    void Reglage::initMatrice(Program *program) {
        uMVPMatrix = glGetUniformLocation(program->getGLId(), "uMVPMatrix");
        uMVMatrix = glGetUniformLocation(program->getGLId(), "uMVMatrix");

        uNbPoint = glGetUniformLocation(program->getGLId(), "uNbPoint");
        uJourNuit = glGetUniformLocation(program->getGLId(), "uJourNuit");
        uPointPos = glGetUniformLocation(program->getGLId(), "uPointPos");

        // Active le test de profondeur GPU
        glEnable(GL_DEPTH_TEST);

        // Calculer la matrice ProjMatrix
        ProjMatrix = glm::perspective(glm::radians(70.f), 800.f/600.f, 0.1f, 100.f);
    }

    void Reglage::renvoiMatrice(TrackballCamera camera, Lumiere lum){
        const glm::mat4 ViewMatrix = camera.getViewMatrix();
        glm::mat4 CubeModelMatrix;
        MVMatrix = ViewMatrix*CubeModelMatrix;

        // Renvoi des valeurs des variables uniformes de lumieres
        glUniform1f(uNbPoint,  lum.nbPoint);
        glUniform1f(uJourNuit,  lum.directional);
        glUniform3fv(uPointPos,  lum.nbPoint, glm::value_ptr(lum.pointsPositions[0]));

        glUniformMatrix4fv(uMVPMatrix, 1, GL_FALSE, glm::value_ptr(ProjMatrix*MVMatrix));
        glUniformMatrix4fv(uMVMatrix, 1, GL_FALSE, glm::value_ptr(MVMatrix));
    }

}