#version 330 core

in vec3 vPosition_vs; // Position du sommet transformé dans l'espace View
in vec3 vNormal_vs; // Normale du sommet transformté dans l'espace View

uniform vec3 uKd;
uniform vec3 uKs;
uniform float uShininess;

uniform vec3 uLightDir_vs;
uniform vec3 uLightIntensity;

out vec3 fColor;


vec3 blinnPhong(){
    vec3 halfVector = (normalize(-vPosition_vs)+uLightDir_vs)/2;

    return uLightIntensity*(uKd*(dot(uLightDir_vs, vNormal_vs))+uKs*pow(dot(halfVector, vNormal_vs),uShininess));
}


void main(){
    fColor = blinnPhong();
}