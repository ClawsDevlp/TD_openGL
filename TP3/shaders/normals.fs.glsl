#version 330 core

in vec3 vNormal; // Normale du sommet transformté dans l'espace View
in vec3 vCouleur; // Cordonnées de texture du sommet
in vec3 vPosPixel;


uniform bool uJourNuit;
uniform vec3 uPointPos[15];
uniform int uNbPoint;

out vec4 fColor;

float pointLight(vec3 pointPos){
    vec3 directionLumierePixel = normalize(vPosPixel - pointPos);
    float pointL = max(-dot(vNormal, directionLumierePixel), 0.);
    return pointL;
}

float directionalLight(){
    vec3 dir = vec3(3, -13, 8);
    dir = normalize(dir);
    float directionL = max(-dot(vNormal, dir), 0.);
    return directionL;
}

void main(){
    float luminosite = 0.3;

    if(uJourNuit){
        luminosite += directionalLight();
    }

    for(int i=0; i <15; i++){
        if(uPointPos[i] != vec3(0,0,0)){
            luminosite += pointLight(uPointPos[i]);
        }
    }
    luminosite = min(luminosite, 1);
    
	fColor = vec4(vCouleur * luminosite, 1.0);
}