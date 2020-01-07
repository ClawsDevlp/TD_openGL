#pragma once

#include <vector>
#include <iostream>
#include <eigen3/Eigen/Dense>



namespace glimac {
     //fonction choisie par les programmeurs pour déterminer les valeurs de y
     float phi(const float a);

    //Déduit les valeurs de omega en fonctions de nos points de controle et valeurs associées
     Eigen::VectorXf findOmega(const Eigen::MatrixXf ptsDeControle, const Eigen::VectorXf valeurs);

    //Détermine les valeurs de y en fonction des omega précédemment calculés et de la fonction phi appliquée à nos pts de controle
     int findValue(const int i, const int j, const Eigen::MatrixXf ptsDeControle, const Eigen::VectorXf w);

    //Produit une matrice recensant les valeurs des y pour chaque coordonnées x,z en fonction de nos points de contrôle
     Eigen::MatrixXd getMap(const Eigen::MatrixXf ptsDeControle, const Eigen::VectorXf valeurs); 
}