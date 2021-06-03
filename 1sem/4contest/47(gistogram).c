#include <stdio.h>

int main(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int symbol_matr[95][2];
    int codenum=32;
    for (int i = 0; i < 95; ++i) {
        symbol_matr[i][0]=codenum;
        symbol_matr[i][1]=0;
        codenum++;
    }
    int curr=getchar();
    while (curr!=EOF){
        for (int i = 0; i < 95; ++i) {
            if (curr==symbol_matr[i][0]){
                symbol_matr[i][1]++;
                break;
            }
        }
        curr=getchar();
    }
    for (int i = 0; i < 95; ++i) {
        if (symbol_matr[i][1]){
            printf("%c ",symbol_matr[i][0]);
            for (int j = 0; j < symbol_matr[i][1]; ++j) {
                printf("%c",'#');
            }printf("%c",'\n');
        }
    }
    return 0;
}

