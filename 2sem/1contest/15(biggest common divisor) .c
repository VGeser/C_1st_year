#include <stdio.h>

int gcd(int a, int b) {
    return (b? gcd(b,a%b):a);
}


int main() {
    FILE *filein = fopen("input.txt", "rt");
    FILE *fileout = fopen("output.txt", "wt");
    int request;
    fscanf(filein,"%d",&request);
    for (int i = 0; i < request; ++i) {
        int num1,num2;
        fscanf(filein,"%d %d",&num1,&num2);
        fprintf(fileout,"%d\n",gcd(num1,num2));
    }
    fclose(filein);
    fclose(fileout);
    return 0;
}

