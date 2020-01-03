#pragma once

#include <vector>
#include <iostream>
#include <eigen3/Eigen/Dense>


namespace glimac {
     // int nbPoints = 3;
     // Eigen::MatrixXd map (20,20);
     // Eigen::MatrixXf ptsDeControle(nbPoints, 2);
     // Eigen::VectorXf valeurs(nbPoints);
     float phi(const float a);
     //pour parcourir la carte
     //Eigen::MatrixXd values = Eigen::MatrixXd::Zero(20,20);


     Eigen::VectorXf findOmega(const Eigen::MatrixXf ptsDeControle, const Eigen::VectorXf valeurs);
     int findValue(const int i, const int j, const Eigen::MatrixXf ptsDeControle, const Eigen::VectorXf w);
     Eigen::MatrixXd getMap(const Eigen::MatrixXf ptsDeControle, const Eigen::VectorXf valeurs); 
}