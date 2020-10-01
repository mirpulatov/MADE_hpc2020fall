#include "matrix_operations_lib.h"

int main() {
    // Size of matrix
    int n;
    cin >> n;

    // Init time
    clock_t beginTime_v, endTime_v, beginTime_m, endTime_m;

    // Init matrices
    int **matrixA, **matrixB, **matrixC;

    matrixA = new int *[n];
    matrixB = new int *[n];
    matrixC = new int *[n];

    for(int i = 0; i < n; i++){
        matrixA[i]=new int [n];
        matrixB[i]=new int [n];
        matrixC[i]=new int [n];
    }


    // Init vectors
    int *vectorA, *vectorB;
    vectorA = new int [n];
    vectorB = new int [n];


    // Fill the matrix A, B
    for(int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            matrixA[i][j] = rand() % 10 + 1;
            matrixB[i][j] = rand() % 10 + 1;
        }
    }


    // Fill the vector A
    for (int i = 0; i < n; i++){
        vectorA[i] = rand() % 100;
    }


    // Multiplications and time check
    beginTime_v = clock();
    vector_multiplication(matrixA, vectorA, vectorB, n);
    endTime_v = clock();
    cout << "Matrix * Vector time: " << (double)(endTime_v - beginTime_v) / CLOCKS_PER_SEC << endl;

    beginTime_m = clock();
    matrix_multiplication(matrixA, matrixB, matrixC, n);
    endTime_m = clock();
    cout << "Matrix * Matrix time: " << (double)(endTime_m - beginTime_m) / CLOCKS_PER_SEC << endl;


    // Clean memory
    for (int i = 0; i < n; i ++)
    {
        delete[] matrixA[i];
        delete[] matrixB[i];
        delete[] matrixC[i];
    }
    delete [] matrixA;
    delete [] matrixB;
    delete [] matrixC;
    delete [] vectorA;
    delete [] vectorB;

    return 0;
}
