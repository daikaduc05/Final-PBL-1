#ifndef MATRIX_INVERSE_H
#define MATRIX_INVERSE_H

#include <iostream>
#include <vector> 

namespace GaussJordanInverseMatrix {
    std::vector<std::vector<double>> gaussJordanInverse(std::vector<std::vector<double>>& matrix) {
        int n = matrix.size(); 
        std::vector<std::vector<double>> inverse(n, std::vector<double>(n * 2, 0.0));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                inverse[i][j] = matrix[i][j];
            }
            inverse[i][i + n] = 1.0;
        }     
        for (int i = 0; i < n; ++i) {
            if (inverse[i][i] == 0.0) {
                std::cerr << "Ma tran ko kha nghich." << std::endl;
                return std::vector<std::vector<double>>(n, std::vector<double>(n, 0.0)); 
            }

            for (int j = 0; j < n; ++j) {
                if (i != j) {
                    double ratio = inverse[j][i] / inverse[i][i];
                    for (int k = 0; k < 2 * n; ++k) {
                        inverse[j][k] -= ratio * inverse[i][k];
                    }
                }
            }
        }      
        for (int i = 0; i < n; ++i) {
            double divisor = inverse[i][i];
            for (int j = 0; j < 2 * n; ++j) {
                inverse[i][j] /= divisor;
            }
        }
        std::vector<std::vector<double>> result(n, std::vector<double>(n, 0.0));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                result[i][j] = inverse[i][j + n];
            }
        }
        return result;
    }
}
#endif
