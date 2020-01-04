#version 330 core

in vec3 vNormal_vs; // Normale du sommet transformté dans l'espace View
in vec3 vTexCoords; // Cordonnées de texture du sommet
in vec3 vPosPixel;


uniform bool uJourNuit;
uniform vec3 uPointPos[15];
uniform int uNbPoint;

out vec4 fColor;

float pointLight(vec3 pointPos){
    vec3 directionLumierePixel = normalize(vPosPixel - pointPos);
	float d = length(vPosPixel - pointPos);
    float pointL = max(-dot(vNormal_vs, directionLumierePixel), 0.)/(d);
    return pointL;
}

float directionalLight(){
    vec3 dir = vec3(5, -10, 5);
    dir = normalize(dir);
    float directionL = max(-dot(vNormal_vs, dir), 0.);
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
    
	fColor = vec4(vTexCoords * luminosite, 1.0);
}