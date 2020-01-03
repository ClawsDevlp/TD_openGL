#version 330 core

in vec3 vPosition_vs; // Position du sommet transformé dans l'espace View
in vec3 vNormal_vs; // Normale du sommet transformté dans l'espace View
in vec3 vTexCoords; // Cordonnées de texture du sommet

uniform vec3 uKd;
uniform vec3 uKs;
uniform float uShininess;

uniform vec3 uLightPos_vs;
uniform vec3 uLightIntensity;

out vec4 fColor;

vec3 pointLight(){
    vec3 halfVector = (normalize(uLightPos_vs - vPosition_vs) + uLightPos_vs) /2;
    vec3 lightIntensity = uLightIntensity / (distance(uLightPos_vs ,vPosition_vs) * distance(uLightPos_vs ,vPosition_vs));
    
    return lightIntensity*(uKd*(dot(uLightPos_vs, vNormal_vs))+uKs*pow(dot(halfVector, vNormal_vs),uShininess));
}

vec3 directionalLight(){
    vec3 halfVector = (normalize(-vPosition_vs)+uLightDir_vs)/2;

    return uLightIntensity*(uKd*(dot(uLightDir_vs, vNormal_vs))+uKs*pow(dot(halfVector, vNormal_vs),uShininess));
}

void main(){
	fColor = vec4(vTexCoords, 1.0);//vNormal_vs;
}