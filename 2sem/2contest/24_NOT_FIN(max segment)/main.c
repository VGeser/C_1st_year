#include <stdio.h>
#define N 100005
int inarr[N],nums;
void Init ( const int * arr , int n );
int Query ( int l , long long sum);
int main() {
    FILE *filein = fopen("input.txt", "rt");
    FILE *fileout = fopen("output.txt", "wt");
    int request;
    fscanf(filein, "%d%d", &nums,&request);
    for (int i = 0; i < nums; ++i) {
        fscanf(filein,"%d",&inarr[i]);
    }
    Init(inarr,nums);
    for (int i = 0; i < request; ++i) {
        int r1;
        long long r2;
        fscanf(filein,"%d%lld",&r1,&r2);
        fprintf(fileout,"%d\n",Query(r1,r2));
    }
    fclose(filein);
    fclose(fileout);
    return 0;
}