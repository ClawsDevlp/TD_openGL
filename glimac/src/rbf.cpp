#include "glimac/rbf.hpp"

namespace glimac {

    float phi(const float a){
        return exp(-0.2*a*a);
    }

    Eigen::VectorXf findOmega(const Eigen::MatrixXf ptsDeControle, const Eigen::VectorXf valeurs){
        Eigen::MatrixXf A = Eigen::MatrixXf::Zero(ptsDeControle.rows(), ptsDeControle.rows());
        //on remplit la matrice avec les phi de valeurs absolue xi - xj
        for (int i = 0; i < A.rows(); i++){
            for (int j = 0; j < A.cols(); j++){
                //valeur absolue de la diff de 2 points = la norme
                A(i,j)= phi((ptsDeControle.row(i)-ptsDeControle.row(j)).norm());
            }
        }
        return A.inverse() * valeurs;
    }

    int findValue(const int i, const int j, const Eigen::MatrixXf ptsDeControle, const Eigen::VectorXf w){
        float value = 0;
        Eigen::VectorXf coordPoint(2);
        coordPoint << i, j;
        for (int index = 0; index < ptsDeControle.rows(); index++){
            //attention à bien faire passer vercteur eigen sous format vertical
            value += w(index)*phi((coordPoint.transpose()-ptsDeControle.row(index)).norm());
        }
        return round(value);
    }

    Eigen::MatrixXd getMap(const Eigen::MatrixXf ptsDeControle, const Eigen::VectorXf valeurs){
        Eigen::VectorXf w = findOmega(ptsDeControle, valeurs);
        Eigen::MatrixXd map = Eigen::MatrixXd::Zero(21,21);
        
        for (int i = 0; i < map.rows(); i++){
            for (int j = 0; j < map.cols(); j++){
                //parcours la carte
                map(i,j) = findValue(i, j, ptsDeControle, w);
            }
        }
        return map;
    }
}