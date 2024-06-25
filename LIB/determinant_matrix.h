#ifndef MATRIX_DETERMIANT_H
#define MATRIX_DETERMINANT_H
#include <iostream>
#include <vector> 
#include "echelon_matrix.h"
namespace MatrixDetermiant{

    double determinantFromRowEchelonForm(std::vector<std::vector<double>>& matrix) {
        std::vector<std::vector<double>> tmp = EchelonMatrix::toRowEchelonForm(matrix);
        double det = 1.0;
        for (int i = 0; i < tmp.size(); ++i) {
            det *= tmp[i][i];
        }
        return det;
    }
}
#endif 
