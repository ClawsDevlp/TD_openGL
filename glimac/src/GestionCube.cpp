                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                           #include "glimac/GestionCube.hpp"

namespace glimac {

/*
ShapeVertex posSommets[] = {
        // p0
        ShapeVertex(glm::vec3(-0.5, 0.5, 0.0), glm::vec3(0,0,0), glm::vec2(0,0)),
*/

     glm::vec3 posSommets[] = {
        // p0
        glm::vec3(-0.5, 0.5, 0.0),
        // p1
        glm::vec3(0.5, 0.5, 0.0),
        // p2
        glm::vec3(-0.5, -0.5, 0.0),
        // p3
        glm::vec3(0.5, -0.5, 0.0),
        // p4
        glm::vec3(-0.5, -0.5, -1.0),
        // p5
        glm::vec3(-0.5, 0.5, -1.0),
        // p6
        glm::vec3(0.5, -0.5, -1.0),
        // p7
        glm::vec3(0.5, 0.5, -1.0),
     };

    // index buffer
    int _indexsSommets[] = {
      // face de devant
      0, 1, 2,  1, 2, 3,
      // face de derrière
      4, 5, 7,  4, 6, 7,
      // face de gauche
      0, 2, 4,  0, 5, 4,
      // face de droite
      1, 3, 6,  1, 7, 6,
      // face de dessous
      2, 3, 4,  3, 6, 4,
      // face de dessus
      0, 1, 7,  0, 5, 7
    }; 

    const GLuint VERTEX_ATTR_SOMMET_POSITION = 0;
    const GLuint VERTEX_ATTR_SOMMET_NORMAL = 1;
    const GLuint VERTEX_ATTR_SOMMET_TEXCOORDS = 2;
    const GLuint VERTEX_ATTR_CUBE_POSITION = 3;

    const int nbCoordSommets = 36;

   GestionCube::GestionCube(){
      initialisationCube();
   }

    void GestionCube::initialisationCube(){
      // VB sommet
      glGenBuffers(1, &sommetVbo);
      glBindBuffer(GL_ARRAY_BUFFER, sommetVbo);
      glBufferData(GL_ARRAY_BUFFER, sizeof(posSommets), posSommets, GL_STATIC_DRAW);      

      glBindBuffer(GL_ARRAY_BUFFER, 0);

      // VB positions cubes
      glGenBuffers(1, &positionVbo);
      glBindBuffer(GL_ARRAY_BUFFER, positionVbo);
      glBufferData(GL_ARRAY_BUFFER, sizeof(glm::vec3) * cubesPositions.size(), cubesPositions.size() > 0 ? &cubesPositions[0] : nullptr, GL_STATIC_DRAW);
      glBindBuffer(GL_ARRAY_BUFFER, 0);

      // VB positions sommets
      glGenBuffers(1, &ibPositionsSommetsID);
      glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ibPositionsSommetsID);
      glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(_indexsSommets), _indexsSommets, GL_STATIC_DRAW);
      glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
      
      //vertex array
      glGenVertexArrays(1, &c_Vao);
      glBindVertexArray(c_Vao);

      glEnableVertexAttribArray(VERTEX_ATTR_SOMMET_POSITION);
      //glEnableVertexAttribArray(VERTEX_ATTR_SOMMET_NORMAL);
      //glEnableVertexAttribArray(VERTEX_ATTR_SOMMET_TEXCOORDS);

      glBindBuffer(GL_ARRAY_BUFFER, sommetVbo);
      
      glVertexAttribPointer(VERTEX_ATTR_SOMMET_POSITION, 3, GL_FLOAT, GL_FALSE, sizeof(glm::vec3), 0);
      //glVertexAttribPointer(VERTEX_ATTR_SOMMET_NORMAL, 3, GL_FLOAT, GL_FALSE, sizeof(glm::vec3), (const GLvoid*)(offsetof(glm::vec3, color)));
      // glVertexAttribPointer(VERTEX_ATTR_SOMMET_TEXCOORDS, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex3DColor), (const GLvoid*)(offsetof(ShapeVertex, texCoords)));

      glBindBuffer(GL_ARRAY_BUFFER, positionVbo);
      glEnableVertexAttribArray(VERTEX_ATTR_CUBE_POSITION);
      glVertexAttribPointer(VERTEX_ATTR_CUBE_POSITION, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), 0);
      glVertexAttribDivisor(VERTEX_ATTR_CUBE_POSITION, 1);

      glBindBuffer(GL_ARRAY_BUFFER, 0);
      glBindVertexArray(0);
    }

    void GestionCube::miseAJourGPU(){
        glBindBuffer(GL_ARRAY_BUFFER, positionVbo); 
        glBufferData(GL_ARRAY_BUFFER, sizeof(glm::vec3) * cubesPositions.size(), cubesPositions.size() > 0 ? &cubesPositions[0] : nullptr, GL_STATIC_DRAW);
        glBindBuffer(GL_ARRAY_BUFFER, 0);
    }

    void GestionCube::supprDonneesCube(){
      glDeleteBuffers(1, &positionVbo);
      glDeleteBuffers(1, &ibPositionsSommetsID);
      glDeleteBuffers(1, &sommetVbo);
      glDeleteVertexArrays(1, &c_Vao);
    }

    void GestionCube::dessinCube(){
      glBindVertexArray(c_Vao);
      glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ibPositionsSommetsID);
      glDrawElementsInstanced(GL_TRIANGLES, 36, GL_UNSIGNED_INT, 0, cubesPositions.size());
      glBindVertexArray(0);
    }

    void GestionCube::dessinCubeWireframe(){
              // index buffer
        int _indexsSommets[] = {
          // face de devant : v0, v1, v2 puis v0, v2, v3
          0, 1, 1,  3, 3, 2, 2, 0,
          // face de derrière
          4, 5, 5, 7, 4, 6, 6, 7,
          // face de gauche
          0, 5, 1, 7, 3, 6, 2, 4
        }; 


        // VB positions sommets
        glGenBuffers(1, &ibPositionsSommetsID);
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ibPositionsSommetsID);
        glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(_indexsSommets), _indexsSommets, GL_STATIC_DRAW);
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);

        glBindVertexArray(c_Vao);
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ibPositionsSommetsID);
        glDrawElementsInstanced(GL_LINES, 36, GL_UNSIGNED_INT, 0, cubesPositions.size());
        glBindVertexArray(0);
    };

    void GestionCube::ajoutCube(glm::vec3 position){
      //std::cout << position << std::endl;
      //supprCube(position);
      cubesPositions.push_back(position);
      miseAJourGPU();
    }

    int GestionCube::trouveCube(glm::vec3 position){
      for( int k = 0; k < cubesPositions.size(); ++k){
        // comme on sait que nos cubes sont positionnés sur une grille avec un pas de 1, ce test suffit
        if( glm::length(position-cubesPositions[k]) < 0.1f){
          return k;
        }
      }
      return -1; // si on ne l'a pas trouvé
    }

    void GestionCube::supprCube(glm::vec3 position){
      int index = trouveCube(position);
        if( index != -1 ){
          // on place l'élément à retirer à la fin
          int lastIndex = cubesPositions.size() - 1;
          std::swap(cubesPositions[index], cubesPositions[lastIndex]);
          // on retire le dernier élément
          cubesPositions.pop_back();
          miseAJourGPU();
        }
    }

    glm::vec3 GestionCube::incrementAxe(int axe) {
      glm::vec3 incrementAxe;

      if (axe == 0) {
            incrementAxe += glm::vec3(1, 0, 0);
        } else if (axe == 1) {
            incrementAxe += glm::vec3(0, 1, 0);
        } else if (axe == 2) {
            incrementAxe += glm::vec3(0, 0, 1);
      }

      return incrementAxe;
    }

    int GestionCube::extrudCube(int axe, glm::vec3 position){

      if(trouveCube(position) == -1){
        std::cout << "Vous n'êtes pas sur une colonne à extruder" << std::endl;
        return -1;
      }

      glm::vec3 incrementVec = incrementAxe(axe);
      bool found = false;

      while(!found){   
        if(trouveCube(position+incrementVec) == -1){
          ajoutCube(position+incrementVec);
          found = true;
        } else {
          position += incrementVec;
        }
      }
      return 1;
    }

    int GestionCube::digCube(int axe, glm::vec3 position){

      if(trouveCube(position) == -1){
        std::cout << "Vous n'êtes pas sur une colonne à creuser" << std::endl;
        return -1;
      }

      glm::vec3 incrementVec = incrementAxe(axe);
      bool found = false;

      while(!found){   
        if(trouveCube(position+incrementVec) == -1){
          found = true;
        } else {
          position += incrementVec;
        }
      }

      supprCube(position);

      return 1;
    }
}