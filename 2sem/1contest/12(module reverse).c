#include <stdio.h>
void nodext (long long a, long long b,long long *x,long long *y,long long *gcd){
    if (!a){
        (*x)=0;(*y)=1;(*gcd)=b;
        return;
    }
    long long x1=0, y1=0, res=0;
    nodext (b%a, a,&x1,&y1,&res);
    (*x) = y1 - (b / a) * x1;
    (*y) = x1;
}
int main() {
    FILE *filein = fopen("input.txt","rt");
    FILE *fileout =fopen("output.txt","wt");
    int request;long long mod;
    fscanf(filein,"%d %lld",&request,&mod);
    for (int i = 0; i < request; ++i) {
        long long a=0,ans=0,k1=0,k2=0;
        fscanf(filein,"%lld",&a);
        nodext(a,mod,&k1,&k2,&ans);
        k1=k1<0?k1+mod:k1;
        k1=(a*k1)%mod==1?k1:-1; //opt 2
        fprintf(fileout,"%lld\n",k1);
    }
    fclose(filein);
    fclose(fileout);
    return 0;
}

