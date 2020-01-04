#version 330 core

in vec3 vNormal_vs; // Normale du sommet transformté dans l'espace View
in vec3 vTexCoords; // Cordonnées de texture du sommet

in vec3 vPosInWorld;


uniform bool uJourNuit;

out vec4 fColor;

float pointLight(){
    vec3 dir = vec3(5, 5, 5);
    dir = normalize(dir);
    vec3 dirLghtPixel = normalize(vPosInWorld-dir);
    float pointL = max(-dot(vNormal_vs, dirLghtPixel), 0.);
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

    luminosite += pointLight();
    luminosite = min(luminosite, 1);
    
	fColor = vec4(vTexCoords * luminosite, 1.0);//vNormal_vs;
}