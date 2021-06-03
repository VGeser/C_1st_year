#include <string.h>
#include <stdlib.h>
int size = sizeof(double);
void dcopy (int n , const double *X , double *Y ){
    memmove(Y,X,(n* size));
}
void dswap (int n , double *X , double *Y ){
    double *temp = malloc(n*size);
    memmove(temp,X,n*size);
    memmove(X,Y,n*size);
    memmove(Y,temp,n*size);
}
void dscal (int n , double alpha , double *X ){
    for (int i = 0; i < n; ++i) {
        double tmp=X[i]*alpha;
        X[i]=tmp;
    }
}
void daxpy (int n , double alpha , const double *X , double *Y ){
    double *tmp = malloc(n*size);
    memmove(tmp,X,n*size);
    dscal(n,alpha,tmp);
    for (int i = 0; i < n; ++i) {
        Y[i]=Y[i]+tmp[i];
    }
}
double ddot (int n , const double *X , const double * Y ){
    double res=0;
    for (int i = 0; i < n; ++i) {
        res+=(X[i]*Y[i]);
    }
    return res;
}

