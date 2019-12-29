#version 330 core

in vec3 vPosition_vs; // Position du sommet transformé dans l'espace View
in vec3 vNormal_vs; // Normale du sommet transformté dans l'espace View
in vec3 vTexCoords; // Cordonnées de texture du sommet

out vec4 fColor;

void main(){
	fColor = vec4(vTexCoords, 1.0);//vNormal_vs;
}