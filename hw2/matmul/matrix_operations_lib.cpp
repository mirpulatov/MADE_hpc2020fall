//
// Created by mirpulatov on 9/27/20.
//
#include "matrix_operations_lib.h"

void matrix_multiplication(int **A, int **B, int **C, int n){
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < n; ++j){
            C[i][j] = 0;
            for(int k = 0; k < n; ++k){
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

void vector_multiplication(int **A, int *B, int *C, int n){
    for (int i = 0; i < n; i++){
        C[i] = 0;
        for (int j = 0; j < n; j++){
            C[i] += A[i][j] * B[j];
        }
    }
}