#version 330 core

in vec3 vFragColor;
in vec2 vFragPosition;

out vec3 fFragColor;

void main() {
	float a = 22 * exp(-100 * pow(distance(vFragPosition, vec2(0, 0)), 2)); // halo
	float b = length(fract(5. * vFragPosition)); // cadrillage
	float c = length(abs(fract(5. * vFragPosition) * 2. - 1.)); // grillage
	float d = mod(floor(10. * vFragPosition.x) + floor(10. * vFragPosition.y), 2.); // échiquier
	float e = smoothstep(0.3, 0.32, length(fract(5.*vFragPosition) -0.5)); // trouage
	float f = smoothstep(0.4, 0.5, max(abs(fract(8. * vFragPosition - 0.5 * mod(floor(8. * vFragPosition.y), 2.)) -0.5), abs(fract(8. * vFragPosition.y) - 0.5))); // mur de briques
	
	float g = length(floor(10. * vFragPosition.x) + floor(10. * vFragPosition.y)); // personnalisé1
	float h = exp(-100 * pow(length(fract(5.*vFragPosition) -0.5), 2)); // personnalisé 2 (sapin de noel)

	fFragColor = vFragColor * g;
};