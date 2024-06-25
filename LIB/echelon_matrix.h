#ifndef MATRIX_ECHELON_H
#define MATRIX_ECHELON_H
#include <iostream>
#include <vector>

namespace EchelonMatrix {
    std::vector<std::vector<double>> toRowEchelonForm(std::vector<std::vector<double>>& matrix1) {
        std::vector<std::vector<double>> matrix = matrix1;
        int lead = 0;
        int rowCount = matrix.size();
        int colCount = matrix[0].size();
        for (int r = 0; r < rowCount; ++r) {
            if (lead >= colCount) {
                return matrix;
            }
            int i = r;
            while (matrix[i][lead] == 0) {
                ++i;
                if (i == rowCount) {
                    i = r;
                    ++lead;
                    if (lead == colCount) {
                        return matrix;
                    }
                }
            }
            std::swap(matrix[i], matrix[r]);
            double lv = matrix[r][lead];
            for (int j = 0; j < colCount; ++j) {
                matrix[r][j] /= lv;
            }
            for (int i = 0; i < rowCount; ++i) {
                if (i != r) {
                    double lv = matrix[i][lead];
                    for (int j = 0; j < colCount; ++j) {
                        matrix[i][j] -= lv * matrix[r][j];
                    }
                }
            }
            ++lead;
        }
        return matrix;
    }
}
#endif
