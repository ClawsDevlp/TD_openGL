#pragma once

#include "common.hpp"
#include <vector>
#include <iostream>
#include "glimac/common.hpp"
#include <glimac/Texture.hpp>

namespace glimac {

     const glm::vec3 COULEURBASE = glm::vec3(0.,1.,0.);

     class GestionCube {

          private:
          std::vector<glm::vec3> cubesPositions;
          std::vector<glm::vec3> cubesCouleurs;
          std::vector<int> cubesTextures;

          //Texture* textureCube;          
          int type;

          GLuint positionVbo;
          GLuint vao;
          GLuint sommetVbo;
          GLuint positionSommetVbo;
          GLuint normaleVbo;
          GLuint couleurVbo;
          GLuint textureVbo;

          public:
          GestionCube();
          ~GestionCube() = default;

          // Getters et setters
          int getCubesPositionsSize();
          glm::vec3 getCubesPositions(const int index);
          void setCubesPositions(const int index, const glm::vec3 donnee);
          glm::vec3 getCubesCouleurs(const int index);
          void setCubesCouleurs(const int index, const glm::vec3 donnee);

          // Initialisation vbos et vao de tous les cubes
          void initialisationCube();
          // Mise a jour vbos
          void miseAJourGPU();
          // Dessine tous les cubes pleins
          void dessinCube();
          // Dessine les arrêtes des cubes (curseur)
          void dessinCubeWireframe();
          // Trouve la position d'un cube dans cubesPositions en fonction de ses coordonnées
          int trouveCube(const glm::vec3 position);
          // Libère les données de tous les cubes
          void supprDonneesCube();
          // Ajoute un cube dans cubesPositions
          void ajoutCube(const glm::vec3 position, const glm::vec3 color);
          // Supprime les données d'un cube dans cubesPositions et cubesCouleurs
          void supprCube(const glm::vec3 position);
          // Ajoute ou supprime un cube d'une colonne
          int extruDigCube(const int axe, const bool ExtrOrDig, glm::vec3 position);
          // Incrémente un axe
          glm::vec3 incrementAxe(const int axe);
          // Trouve la couleur d'un cube en fonction de ses coordonnées
          glm::vec3 trouvCouleur(const glm::vec3 position);
          // Modifie la couleur d'un cube
          void modifCouleur(const glm::vec3 position, const glm::vec3 couleur);
          // Change le type de cube (texture)
          void changeType(const glm::vec3 position, const int nType);
          // Ajoute texture au cube
          Texture* ajoutTexture();
     };
    
}
