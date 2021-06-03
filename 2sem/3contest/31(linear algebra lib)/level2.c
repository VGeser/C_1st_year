#include <stdlib.h>
void dgemv (
        int m , int n,//n - ширина
        double alpha , const double *A , const double *X ,
        double beta , double * Y
){
    double *temp=malloc(m* sizeof(double ));
    for (int i = 0; i < m; ++i) {
        double val=0;
        for (int j = 0; j < n; ++j) {
            val+=A[i*n+j]*X[j]*alpha;
        }
        temp[i]=val;
    }
    for (int i = 0; i < m; ++i) {
        double tmp=Y[i]*beta+temp[i];
        Y[i]=tmp;
    }
}
void dger (
        int m , int n ,
        double alpha , const double *X , const double *Y ,
        double *A
){
    double *temp = malloc(m*n*sizeof(double ));
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            temp[i*n+j]=X[i]*Y[j]*alpha;
        }
    }
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            A[i*n+j]+=temp[i*n+j];
        }
    }
}


