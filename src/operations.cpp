//
// Created by Dylan Beharall on 25/01/2024.
//
#include "../include/operations.h"

Matrix operator*(Matrix mat1, Matrix mat2) {
    if (mat1.width != mat2.height) {
        throw std::invalid_argument( "Wrong dimensions for matrix multiplication" );
    }

    std::vector<std::vector<double>> n1= mat1.generateNested();
    std::vector<std::vector<double>> n2= mat2.generateNested();
    std::vector<double> ret = {};

    for (int i = 0; i < mat1.height; i++) {
        for (int j = 0; j < mat2.width; j++) {
            double add = 0;

            for (int k = 0; k < mat1.width; k++) {
                add += n1[i][k] * n2[k][j];
            }

            ret.push_back(add);
        }
    }

    return {mat1.height, mat2.width, ret};
}

Matrix operator*(Matrix mat, ColumnVector v) {
    return mat * v.toMatrix();
}

Matrix operator*(ColumnVector v, Matrix mat) {
    return v.toMatrix() * mat;
}

double dotP(ColumnVector c1, ColumnVector c2) {
    if (c1.height != c2.height) {
        throw std::invalid_argument( "Vectors with different heights cannot have a dot product" );
    }
    double dot = 0;
    for(int i = 0; i < c1.height; i++) dot += c1.vector[i] * c2.vector[i];
    return dot;
}

ColumnVector operator*(double lambda, ColumnVector c) {
    return c * lambda;
}

Matrix operator*(double lambda, Matrix m) {
    return m * lambda;
}