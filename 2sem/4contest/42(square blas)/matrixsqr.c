#include "cblas.h"
//row-major
void MatrixSqr(int n, const double* A, double* R) {
    cblas_dgemm(CblasRowMajor, CblasNoTrans, CblasNoTrans, n, n, n, 1, A, n, A, n, 0.0, R, n);
}

