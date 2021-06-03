#include <stdio.h>
#define N 1005
#define big 1000000007
int memo[N][N];

int divide(int sum, int last) {
    if (memo[sum][last]) {
        return memo[sum][last];
    }
    if (!sum && !last){
        return memo[sum][last]=1;
    }else if (sum && last <= 0){
        return memo[sum][last]=0;
    }else if (last > sum){
        return divide(sum, sum) % big;
    }else{
        int div1= (divide(sum, last - 1)) % big;
        int div2=(divide(sum - last, last)) % big;
        return memo[sum][last]=div1+div2;
    }
}

int main() {
    FILE *filein = fopen("input.txt", "rt");
    FILE *fileout = fopen("output.txt", "wt");
    int number,res;
    fscanf(filein,"%d", &number);
    /*for (int i = 0; i < number+1; ++i) {
        for (int j = 0; j < number+1; ++j) {
            memo[i][j]=-1;
        }
    }*/
    res=divide(number,number);
    fprintf(fileout,"%d",res);
    fclose(filein);
    fclose(fileout);
    return 0;
}

