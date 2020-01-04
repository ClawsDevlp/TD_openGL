#version 330 core

// Attributs de sommet
layout(location = 0) in vec3 aVertexPosition; // Position du sommet
layout(location = 1) in vec3 aVertexNormal; // Normale du sommet
layout(location = 2) in vec3 aVertexTexCoords; // Coordonnées de texture du sommet
layout(location = 3) in vec3 aCubePosition; // Position cube

// Matrices de transformation reçues en uniform
uniform mat4 uMVPMatrix;
uniform mat4 uMVMatrix;

// Sorties du shader
out vec3 vPosition_vs; // Position du sommet transformé dans l'espace View
out vec3 vNormal_vs; // Normale du sommet transformté dans l'espace View
out vec3 vTexCoords; // Cordonnées de texture du sommet
out vec3 vPosInWorld; // Cordonnées de texture du sommet

void main(){
	// Passage en coordonnées homogènes
	vec4 vertexPosition = vec4(aVertexPosition+aCubePosition, 1);
	vPosInWorld = aVertexPosition + aCubePosition;
	// Calcul des valeurs de sortie
	vPosition_vs = vec3(uMVMatrix * vertexPosition);
	vNormal_vs = aVertexNormal;
	vTexCoords = aVertexTexCoords;

	// Calcul de la position projetée
	gl_Position = uMVPMatrix * vertexPosition;
}