#include <stdlib.h>
void dgemm (
        int m , int n , int k ,
        double alpha , const double *A , const double *B ,
        double beta , double * C
){
    double *temp = calloc(n*m,sizeof(double));
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            for (int l = 0; l < k; ++l) {
                temp[i*n+j]+= A[i*k + l] * B[l*n + j]*alpha;
            }
        }
    }
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            C[i*n+j]*=beta;
            C[i*n+j]+=temp[i*n+j];
        }
    }
}


