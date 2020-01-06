#version 330 core

// Attributs de sommet
layout(location = 0) in vec3 aVertexPosition; // Position du sommet
layout(location = 1) in vec3 aVertexNormal; // Normale du sommet
layout(location = 2) in vec3 aVertexCouleur; // Coordonnées de couleur
layout(location = 3) in vec3 aCubePosition; // Position cube
layout(location = 4) in vec2 aVertexTexture; // Position cube

// Matrices de transformation reçues en uniform
uniform mat4 uMVPMatrix;
uniform mat4 uMVMatrix;

// Sorties du shader
out vec3 vNormal; // Normale du sommet transformté dans l'espace View
out vec3 vCouleur; // Cordonnées couleur
out vec3 vPosPixel; // Position pixel
out vec2 vTexture; // Coordonnées texture

void main(){
	// Calcul des valeurs de sortie
	vNormal = aVertexNormal;
	vCouleur = aVertexCouleur;
	vPosPixel = aVertexPosition + aCubePosition;

	// Passage en coordonnées homogènes
	vec4 vertexPosition = vec4(vPosPixel, 1);

	// Calcul de la position projetée
	gl_Position = uMVPMatrix * vertexPosition;
}