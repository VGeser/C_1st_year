void cblas_dgemm(int Layout, int transa, int transb, int m, int n, int k,
                 const double alpha, const double *A, int lda, const double *B, int ldb, const double beta, double *C,
                 int ldc) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            C[i * n + j] *= beta;
            double res = 0;
            for (int l = 0; l < k; l++)
                res += A[i * k + l] * B[l * n + j];
            C[i * n + j] += alpha * res;
        }
    }
}

