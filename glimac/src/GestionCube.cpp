#include "glimac/GestionCube.hpp"

namespace glimac {
  // Indexes

  glm::vec3 posSommets[] = {
    // face de devant 0 1 2 3
    glm::vec3(-0.5, 0.5, 0.0), glm::vec3(0.5, 0.5, 0.0), glm::vec3(-0.5, -0.5, 0.0), glm::vec3(0.5, -0.5, 0.0),
    // face de derrière 5 7 4 6
    glm::vec3(-0.5, 0.5, -1.0), glm::vec3(0.5, 0.5, -1.0), glm::vec3(-0.5, -0.5, -1.0), glm::vec3(0.5, -0.5, -1.0),
    // face de gauche 7 1 6 3
    glm::vec3(-0.5, 0.5, -1.0),glm::vec3(-0.5, 0.5, 0.0), glm::vec3(-0.5, -0.5, -1.0), glm::vec3(-0.5, -0.5, 0.0),
    // face de droite 5 0  4 2
    glm::vec3(0.5, 0.5, -1.0), glm::vec3(0.5, 0.5, 0.0), glm::vec3(0.5, -0.5, -1.0), glm::vec3(0.5, -0.5, 0.0),
    // face du dessous 2 3 4 6
    glm::vec3(-0.5, -0.5, 0.0), glm::vec3(0.5, -0.5, 0.0), glm::vec3(-0.5, -0.5, -1.0), glm::vec3(0.5, -0.5, -1.0),
    // face du dessus 0 1 5 7
    glm::vec3(-0.5, 0.5, 0.0), glm::vec3(0.5, 0.5, 0.0), glm::vec3(-0.5, 0.5, -1.0), glm::vec3(0.5, 0.5, -1.0),

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
    4, 5, 6,  5, 6, 7,
    // face de gauche
    8, 9, 10,  9, 10, 11,
    // face de droite
    12, 13, 14,  13, 14, 15,
    // face de dessous
    16, 17, 18,  17, 18, 19,
    // face de dessus
    20, 21, 22,  21, 22, 23
  }; 
/*
  const Texture indexTextures[]={
    Texture("/home/claclicla/Documents/ANNEE2/OpenGL_NEUF/imac-s3-opengl-master/TD_openGL/TP3/assets/textures/bois.jpg"),
    Texture("/home/claclicla/Documents/ANNEE2/OpenGL_NEUF/imac-s3-opengl-master/TD_openGL/TP3/assets/textures/MoonMap.jpg")
  };
*/
  const GLuint VERTEX_ATTR_SOMMET_POSITION = 0;
  const GLuint VERTEX_ATTR_SOMMET_NORMALE = 1;
  const GLuint VERTEX_ATTR_SOMMET_COULEUR = 2;
  const GLuint VERTEX_ATTR_CUBE_POSITION = 3;
  const GLuint VERTEX_ATTR_SOMMET_TEXTURE = 4;

  const int nbCoordSommets = 36;

  GestionCube::GestionCube(){
    initialisationCube();
  }

  glm::vec3 GestionCube::getCubesPositions(int index){
    return cubesPositions[index];
  }
  int GestionCube::getCubesPositionsSize(){
    return cubesPositions.size();
  }
  void GestionCube::setCubesPositions(int index, glm::vec3 donnee){
    cubesPositions[index] = donnee;
  }
  glm::vec3 GestionCube::getCubesCouleurs(int index){
    return cubesCouleurs[index];
  }
  void GestionCube::setCubesCouleurs(int index, glm::vec3 donnee){
    cubesCouleurs[index] = donnee;
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
    glBindBuffer(GL_ARRAY_BUFFER, normaleVbo);
    glBufferData(GL_ARRAY_BUFFER, sizeof(normales), normales, GL_STATIC_DRAW);
    glBindBuffer(GL_ARRAY_BUFFER, 0);

    // VB couleurs
    glGenBuffers(1, &couleurVbo);
    
    // VB couleurs
    glGenBuffers(1, &textureVbo);
          
    // vertex array
    glGenVertexArrays(1, &vao);
    glBindVertexArray(vao);

    glEnableVertexAttribArray(VERTEX_ATTR_SOMMET_POSITION);
    glEnableVertexAttribArray(VERTEX_ATTR_CUBE_POSITION);
    glEnableVertexAttribArray(VERTEX_ATTR_SOMMET_NORMALE);
    glEnableVertexAttribArray(VERTEX_ATTR_SOMMET_COULEUR);
    glEnableVertexAttribArray(VERTEX_ATTR_SOMMET_TEXTURE);

    // Chaque vbo est rattaché au vao
    glBindBuffer(GL_ARRAY_BUFFER, sommetVbo);
    glVertexAttribPointer(VERTEX_ATTR_SOMMET_POSITION, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), 0);

    glBindBuffer(GL_ARRAY_BUFFER, positionVbo);
    glEnableVertexAttribArray(VERTEX_ATTR_CUBE_POSITION);
    glVertexAttribPointer(VERTEX_ATTR_CUBE_POSITION, 3, GL_FLOAT, GL_FALSE,  3 * sizeof(float), 0);
    glVertexAttribDivisor(VERTEX_ATTR_CUBE_POSITION, 1);

    glBindBuffer(GL_ARRAY_BUFFER, couleurVbo);
    glEnableVertexAttribArray(VERTEX_ATTR_SOMMET_COULEUR);
    glVertexAttribPointer(VERTEX_ATTR_SOMMET_COULEUR, 3, GL_FLOAT, GL_FALSE,  3 * sizeof(float), 0);
    glVertexAttribDivisor(VERTEX_ATTR_SOMMET_COULEUR, 1);

    glBindBuffer(GL_ARRAY_BUFFER, textureVbo);
    glEnableVertexAttribArray(VERTEX_ATTR_SOMMET_TEXTURE);
    glVertexAttribPointer(VERTEX_ATTR_SOMMET_TEXTURE, 2, GL_FLOAT, GL_FALSE,  2 * sizeof(float), 0);
    glVertexAttribDivisor(VERTEX_ATTR_SOMMET_TEXTURE, 1);

    glBindBuffer(GL_ARRAY_BUFFER, normaleVbo);
    glEnableVertexAttribArray(VERTEX_ATTR_SOMMET_NORMALE);
    glVertexAttribPointer(VERTEX_ATTR_SOMMET_NORMALE, 3, GL_FLOAT, GL_FALSE,  3 * sizeof(float), 0);

    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);
  }

  void GestionCube::miseAJourGPU(){
    glBindBuffer(GL_ARRAY_BUFFER, positionVbo); 
    glBufferData(GL_ARRAY_BUFFER, sizeof(glm::vec3) * cubesPositions.size(), cubesPositions.size() > 0 ? &cubesPositions[0] : nullptr, GL_STATIC_DRAW);
    glBindBuffer(GL_ARRAY_BUFFER, couleurVbo);
    glBufferData(GL_ARRAY_BUFFER, sizeof(glm::vec3) * cubesCouleurs.size(), cubesCouleurs.size() > 0 ? &cubesCouleurs[0] : nullptr, GL_STATIC_DRAW);
    glBindBuffer(GL_ARRAY_BUFFER, textureVbo);
    glBufferData(GL_ARRAY_BUFFER, sizeof(int) * cubesTextures.size(), cubesTextures.size() > 0 ? &cubesTextures[0] : nullptr, GL_STATIC_DRAW);
    glBindBuffer(GL_ARRAY_BUFFER, 0);
  }

  void GestionCube::supprDonneesCube(){
    glDeleteBuffers(1, &positionVbo);
    glDeleteBuffers(1, &positionSommetVbo);
    glDeleteBuffers(1, &sommetVbo);
    glDeleteVertexArrays(1, &vao);
    //cubesTextures[0]->~Texture();
  }

  void GestionCube::dessinCube(){
    //textureCube->bind();
    glBindVertexArray(vao);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, positionSommetVbo);
    glDrawElementsInstanced(GL_TRIANGLES, 36, GL_UNSIGNED_INT, 0, cubesPositions.size());
    glBindVertexArray(0);
    //textureCube->debind();
  }

  void GestionCube::dessinCubeWireframe(){
    // index buffer
    int indexSommets[] = {
      // face de devant
      0, 1,   1, 3,   3, 2,   2, 0,
      // face de derrière
      4, 5,   5, 7,   4, 6,   6, 7,
      // faces côtés
      8, 9,   10, 11,   12, 13,   14, 15
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
    if(trouveCube(position) == -1){
      // Ajout du cube dans position et couleur
      cubesPositions.push_back(position);
      cubesCouleurs.push_back(color);
      cubesTextures.push_back(0);

      miseAJourGPU();
    } else {
      std::cout << "Cube deja posé ici" << std::endl;
    }
  }

  int GestionCube::trouveCube(glm::vec3 position){
    for( int i=0; i < cubesPositions.size(); ++i ){
      if( cubesPositions[i] == position ){
        return i;
      }
    }
    return -1;
  }

  void GestionCube::supprCube(glm::vec3 position){
    int index = trouveCube(position);

    if( index != -1 ){
      int lastIndex = cubesPositions.size() - 1;

      // Supression du cube dans position et couleur
      cubesPositions.erase(cubesPositions.begin() + index);
      cubesCouleurs.erase(cubesCouleurs.begin() + index);
      cubesTextures.erase(cubesTextures.begin() + index);

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
    int index = trouveCube(position);

    if(index == -1){
      std::cout << "Vous n'êtes pas sur une colonne" << std::endl;
      return -1;
    }

    glm::vec3 incrementVec = incrementAxe(axe);
    bool trouve = false;

    while(!trouve){   
      if(trouveCube(position+incrementVec) == -1){
        trouve = true;
      } else {
        position += incrementVec;
      }
    }

    // ExtrOrDig permet de savoir si l'utilisateur extrud ou dig
    if(ExtrOrDig){
      ajoutCube(position+incrementVec, cubesCouleurs[index]);
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

  void GestionCube::changeType(glm::vec3 position, int nType){
    type = nType;
    int index = trouveCube(position);
    cubesTextures[index] = nType;
    miseAJourGPU();
  }

/*
  Texture* GestionCube::ajoutTexture(){
    if(type == 1){
      return new Texture("/home/claclicla/Documents/ANNEE2/OpenGL_NEUF/imac-s3-opengl-master/TD_openGL/TP3/assets/textures/bois.jpg");
    } else if(type == 0){
      return new Texture("/home/claclicla/Documents/ANNEE2/OpenGL_NEUF/imac-s3-opengl-master/TD_openGL/TP3/assets/textures/MoonMap.jpg");
    }
  }*/
}