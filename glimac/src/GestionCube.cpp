#include "glimac/GestionCube.hpp"

namespace glimac {

/*
ShapeVertex posSommets[] = {
        // p0
        ShapeVertex(glm::vec3(-0.5, 0.5, 0.0), glm::vec3(0,0,0), glm::vec2(0,0)),
*/

  // Indexes

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

  const glm::vec3 normales[] = {
		// face de devant
		glm::vec3(0.0, 0.0, 1.0), glm::vec3(0.0, 0.0, 1.0), glm::vec3(0.0, 0.0, 1.0), glm::vec3(0.0, 0.0, 1.0),
		// face de derrière
		glm::vec3(0.0, 0.0, -1.0), glm::vec3(0.0, 0.0, -1.0), glm::vec3(0.0, 0.0, -1.0), glm::vec3(0.0, 0.0, -1.0), 
		// face de gauche
    glm::vec3(-1.0, 0.0, 0.0), glm::vec3(-1.0, 0.0, 0.0), glm::vec3(-1.0, 0.0, 0.0), glm::vec3(-1.0, 0.0, 0.0), 
		// face de droite
    glm::vec3(1.0, 0.0, 0.0), glm::vec3(1.0, 0.0, 0.0), glm::vec3(1.0, 0.0, 0.0), glm::vec3(1.0, 0.0, 0.0), 
		// face du dessous
    glm::vec3(0.0, -1.0, 0.0), glm::vec3(0.0, -1.0, 0.0), glm::vec3(0.0, -1.0, 0.0), glm::vec3(0.0, -1.0, 0.0),
		// face du dessus
    glm::vec3(0.0, 1.0, 0.0), glm::vec3(0.0, 1.0, 0.0), glm::vec3(0.0, 1.0, 0.0), glm::vec3(0.0, 1.0, 0.0), 
	};

  int indexSommets[] = {
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
  const GLuint VERTEX_ATTR_SOMMET_NORMALE = 1;
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
    glGenBuffers(1, &positionSommetVbo);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, positionSommetVbo);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indexSommets), indexSommets, GL_STATIC_DRAW);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);

    // VB normales
    glGenBuffers(1, &normaleVbo);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, normaleVbo);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(normales), normales, GL_STATIC_DRAW);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);

    // VB couleurs
    glGenBuffers(1, &couleurVbo);
          
    // vertex array
    glGenVertexArrays(1, &vao);
    glBindVertexArray(vao);

    glEnableVertexAttribArray(VERTEX_ATTR_SOMMET_POSITION);
    glEnableVertexAttribArray(VERTEX_ATTR_SOMMET_NORMALE);
    glEnableVertexAttribArray(VERTEX_ATTR_SOMMET_TEXCOORDS);


    // Chaque vbo est rattaché au vao
    glBindBuffer(GL_ARRAY_BUFFER, sommetVbo);
    glVertexAttribPointer(VERTEX_ATTR_SOMMET_POSITION, 3, GL_FLOAT, GL_FALSE, sizeof(glm::vec3), 0);
    glVertexAttribPointer(VERTEX_ATTR_SOMMET_NORMALE, 3, GL_FLOAT, GL_FALSE, sizeof(glm::vec3), 0);
    glVertexAttribPointer(VERTEX_ATTR_SOMMET_TEXCOORDS, 3, GL_FLOAT, GL_FALSE, sizeof(glm::vec3), 0);

    glBindBuffer(GL_ARRAY_BUFFER, positionVbo);
    glEnableVertexAttribArray(VERTEX_ATTR_CUBE_POSITION);
    glVertexAttribPointer(VERTEX_ATTR_CUBE_POSITION, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), 0);
    glVertexAttribDivisor(VERTEX_ATTR_CUBE_POSITION, 1);

    glBindBuffer(GL_ARRAY_BUFFER, couleurVbo);
    glEnableVertexAttribArray(VERTEX_ATTR_SOMMET_TEXCOORDS);
    glVertexAttribPointer(VERTEX_ATTR_SOMMET_TEXCOORDS, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), 0);
    glVertexAttribDivisor(VERTEX_ATTR_SOMMET_TEXCOORDS, 1);

    glBindBuffer(GL_ARRAY_BUFFER, normaleVbo);
    glEnableVertexAttribArray(VERTEX_ATTR_SOMMET_NORMALE);
    glVertexAttribPointer(VERTEX_ATTR_SOMMET_NORMALE, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), 0);
    glVertexAttribDivisor(VERTEX_ATTR_SOMMET_NORMALE, 1);

    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);
  }

  void GestionCube::miseAJourGPU(){
    glBindBuffer(GL_ARRAY_BUFFER, positionVbo); 
    glBufferData(GL_ARRAY_BUFFER, sizeof(glm::vec3) * cubesPositions.size(), cubesPositions.size() > 0 ? &cubesPositions[0] : nullptr, GL_STATIC_DRAW);
    glBindBuffer(GL_ARRAY_BUFFER, couleurVbo);
    glBufferData(GL_ARRAY_BUFFER, sizeof(glm::vec3) * cubesCouleurs.size(), cubesCouleurs.size() > 0 ? &cubesCouleurs[0] : nullptr, GL_STATIC_DRAW);
    glBindBuffer(GL_ARRAY_BUFFER, 0);
  }

  void GestionCube::supprDonneesCube(){
    glDeleteBuffers(1, &positionVbo);
    glDeleteBuffers(1, &positionSommetVbo);
    glDeleteBuffers(1, &sommetVbo);
    glDeleteVertexArrays(1, &vao);
  }

  void GestionCube::dessinCube(){
    glBindVertexArray(vao);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, positionSommetVbo);
    glDrawElementsInstanced(GL_TRIANGLES, 36, GL_UNSIGNED_INT, 0, cubesPositions.size());
    glBindVertexArray(0);
  }

  void GestionCube::dessinCubeWireframe(){
    // index buffer
    int indexSommets[] = {
      // face de devant : v0, v1, v2 puis v0, v2, v3
      0, 1, 1,  3, 3, 2, 2, 0,
      // face de derrière
      4, 5, 5, 7, 4, 6, 6, 7,
      // liage de face
      0, 5, 1, 7, 3, 6, 2, 4
    }; 

    // VB positions sommets
    glGenBuffers(1, &positionSommetVbo);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, positionSommetVbo);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indexSommets), indexSommets, GL_STATIC_DRAW);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);

    glBindVertexArray(vao);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, positionSommetVbo);
    glDrawElementsInstanced(GL_LINES, 36, GL_UNSIGNED_INT, 0, cubesPositions.size());
    glBindVertexArray(0);
  };

  void GestionCube::ajoutCube(glm::vec3 position, glm::vec3 color){
    supprCube(position);
    cubesPositions.push_back(position);
    cubesCouleurs.push_back(color);
    miseAJourGPU();
  }

  int GestionCube::trouveCube(glm::vec3 position){
    for( int k = 0; k < cubesPositions.size(); ++k){
      if( glm::length(position-cubesPositions[k]) < 0.1f){
        return k;
      }
    }
    return -1; // si on ne l'a pas trouvé
  }

  void GestionCube::supprCube(glm::vec3 position){
    int index = trouveCube(position);

    if( index != -1 ){
      int lastIndex = cubesPositions.size() - 1;

      // Supression du cube dans position
      std::swap(cubesPositions[index], cubesPositions[lastIndex]);
      cubesPositions.pop_back();
      
      // Supression du cube dans couleur
      std::swap(cubesCouleurs[index], cubesCouleurs[lastIndex]);
      cubesCouleurs.pop_back();

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

  int GestionCube::extruDigCube(int axe, bool ExtrOrDig, glm::vec3 position){

    if(trouveCube(position) == -1){
      std::cout << "Vous n'êtes pas sur une colonne" << std::endl;
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

    // ExtrOrDig permet de savoir si l'utilisateur extrud ou dig
    if(ExtrOrDig){
      ajoutCube(position+incrementVec, glm::vec3(0,5,0));
    } else {
      supprCube(position);
    }

    return 1;
  }

  glm::vec3 GestionCube::trouvCouleur(glm::vec3 position) {
    int index = trouveCube(position);
    return cubesCouleurs[index];
  }

  void GestionCube::modifCouleur(glm::vec3 position, glm::vec3 couleur){
    int index = trouveCube(position);
    cubesCouleurs[index] = couleur;
    miseAJourGPU();
  }
}