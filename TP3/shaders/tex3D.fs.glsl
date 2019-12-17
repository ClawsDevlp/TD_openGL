#version 330 core

in vec3 vPosition_vs; // Position du sommet transformé dans l'espace View
in vec3 vNormal_vs; // Normale du sommet transformté dans l'espace View
in vec2 vTexCoords; // Cordonnées de texture du sommet

uniform sampler2D uTexture;

out vec3 fColor;


void main(){
    fColor = texture(uTexture, vTexCoords).xyz;
}