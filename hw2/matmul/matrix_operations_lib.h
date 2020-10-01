//
// Created by mirpulatov on 9/27/20.
//
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

#ifndef HPC_MATRIX_OPERATIONS_LIB_H
#define HPC_MATRIX_OPERATIONS_LIB_H

void matrix_multiplication(int **A, int **B, int **C, int n);
void vector_multiplication(int **A, int *B, int *C, int n);

#endif //HPC_MATRIX_OPERATIONS_LIB_H
