#pragma once

#include "common.hpp"
#include <vector>
#include <iostream>
#include "glimac/common.hpp"

namespace glimac {

     class GestionCube {

          public:
          GestionCube();
          ~GestionCube() = default;

          std::vector<glm::vec3> cubesPositions;
          std::vector<glm::vec3> cubesCouleurs;

          GLuint positionVbo;
          GLuint vao;
          GLuint sommetVbo;
          GLuint positionSommetVbo;
          GLuint normaleVbo;
          GLuint couleurVbo;

          // Initialisation vbos et vao de tous les cubes
          void initialisationCube();
          // Mise a jour vbos
          void miseAJourGPU();
          // Dessine tous les cubes pleins
          void dessinCube();
          // Dessine les arrêtes des cubes (curseur)
          void dessinCubeWireframe();
          // Trouve la position d'un cube dans cubesPositions en fonction de ses coordonnées
          int trouveCube(glm::vec3 position);
          // Libère les données de tous les cubes
          void supprDonneesCube();
          // Ajoute un cube dans cubesPositions
          void ajoutCube(glm::vec3 position, glm::vec3 color);
          // Supprime les données d'un cube dans cubesPositions et cubesCouleurs
          void supprCube(glm::vec3 position);
          // Ajoute ou supprime un cube d'une colonne
          int extruDigCube(int axe, bool ExtrOrDig, glm::vec3 position);
          // Incrémente un axe
          glm::vec3 incrementAxe(int axe);
          // Trouve la couleur d'un cube en fonction de ses coordonnées
          glm::vec3 trouvCouleur(glm::vec3 position);
          // Modifie la couleur d'un cube
          void modifCouleur(glm::vec3 position, glm::vec3 couleur);
     };
    
}
