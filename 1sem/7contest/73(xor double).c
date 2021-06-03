#include <stdio.h>
union number{
    unsigned long long integer;
    double fraction;
    unsigned int halves [2];
};
union number xorer(union number i1,union number i2){
    for (int i = 0; i < 64; ++i) {
        int b =(i2.integer>>i)&1;
        if (b){
            if (i<32){
                i1.halves[0]^=(1<<i);
            } else {
                i1.halves[1]^=(1<<i);
            }
        }
    }
    return i1;
}
int main() {
    FILE *filein = fopen("input.txt", "rt");
    FILE *fileout = fopen("output.txt", "wt");
    union number res,in1,in2;
    int request;
    fscanf(filein,"%d",&request);
    for (int i = 0; i < request; ++i) {
        int temp1,temp2;
        fscanf(filein,"%d/%d xor %llx",&temp1,&temp2,&in2.integer);
        in1.fraction=(double)temp1/temp2;
        res = xorer(in1,in2);
        fprintf(fileout,"%0.15g\n",res.fraction);
    }
    fclose(filein);
    fclose(fileout);
    return 0;
}

